#include "ParkingLot.h"
#include "smartpointer.h"
using namespace std;

ParkingLot::ParkingLot() {
    cout << "ParkingLot constructor called.\n";
}

void ParkingLot::addCar(const string& plate, const string& color, const string& make, const string& model) {
    cars.push_back(SmartPointer<Car>(new Car(plate, color, make, model)));  // Add the new car
    cout << "Car added with details [Plate: " << plate
         << ", Color: " << color
         << ", Make: " << make
         << ", Model: " << model
         << "]. Total cars: " << cars.size() << endl;
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

void ParkingLot::sortCars(const string& carAttribute) { // bubble sort algorithm
    for (size_t i = 0; i < cars.size(); ++i) {
        for (size_t j = 0; j < cars.size() - i - 1; ++j) {
            bool swap = false;

            if (carAttribute == "make"){
                swap = cars[j]->getMake() > cars[j + 1]->getMake();
            } 
            
            else if (carAttribute == "model"){
                swap = cars[j]->getModel() > cars[j + 1]->getModel();
            }
            
            else if (carAttribute == "color"){
                swap = cars[j]->getColor() > cars[j + 1]->getColor();
            }
            
            else {
                cout << "Invalid sort attribute. Choose 'make', 'model', or 'color'.\n";
                return;
            }

            if (swap){ 
                // swaps cars[j] and cars[j + 1]
                SmartPointer<Car> temp = cars[j];
                cars[j] = cars[j + 1];
                cars[j + 1] = temp;
            }
        }
    }
}
