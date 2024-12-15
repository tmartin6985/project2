#include "ParkingLot.h"
#include "smartpointer.h"
using namespace std;

ParkingLot::ParkingLot() {}

void ParkingLot::addCar(const string& plate, const string& color, const string& make, const string& model) {
    cars.push_back(SmartPointer<Car>(new Car(plate, color, make, model)));  // adds the new car
    cout << "Car added with details [Plate: " << plate << ", Color: " << color << ", Make: " << make << ", Model: " << model << "]. Total cars: " << cars.size() << endl;
}

void ParkingLot::removeCar(const string& plate) {
    vector<SmartPointer<Car>>::iterator it = cars.begin(); // variable "it" is the iterator
    while (it != cars.end()) {
        if ((*it)->getLicensePlate() == plate) {
            it = cars.erase(it);  
            cout << "Car with plate " << plate << " removed.\n";
            return;
        } 

        else {
            it++;  
        }
    }
    cout << "Car with plate " << plate << " not found.\n";
}

void ParkingLot::displayCars() const {
    if (cars.empty()) {
        cout << "No cars in the parking lot.\n";
        return;
    }

    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].operator->() != nullptr) {  
            cout << "Car " << i + 1 << ": " << *(cars[i]) << endl;
        } 
        
        else {
            cout << "Car " << i + 1 << ": null pointer\n";
        }
    }
}

void ParkingLot::sortCars(const string& carAttribute) {
    if (carAttribute != "make" && carAttribute != "model" && carAttribute != "color") {
        cout << "Invalid sort attribute. Choose 'make', 'model', or 'color'.\n";
        return;
    }

    quickSort(0, cars.size() - 1, carAttribute);
}

void ParkingLot::quickSort(int low, int high, const string& carAttribute) {
    if (low < high) {
        int pivotIndex = partition(low, high, carAttribute); 
        quickSort(low, pivotIndex - 1, carAttribute);
        quickSort(pivotIndex + 1, high, carAttribute);
    }
}


int ParkingLot::partition(int low, int high, const string& carAttribute) {
    SmartPointer<Car> pivot = cars[high]; 
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        bool condition = false;

        if (carAttribute == "make") {
            condition = cars[j]->getMake() < pivot->getMake();
        } else if (carAttribute == "model") {
            condition = cars[j]->getModel() < pivot->getModel();
        } else if (carAttribute == "color") {
            condition = cars[j]->getColor() < pivot->getColor();
        }

        if (condition) {
            ++i;
            std::swap(cars[i], cars[j]); // requires std:: to work
        }
    }

    std::swap(cars[i + 1], cars[high]); // requires std:: to work
    return i + 1;
}
