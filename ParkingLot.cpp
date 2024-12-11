#include "ParkingLot.h"
using namespace std;

void ParkingLot::addCar(const string& plate) {
    cars.push_back(SmartPointer<Car>(new Car(plate)));  // Dynamically allocate cars
}

void ParkingLot::removeCar(const string& plate){
    for (auto it = cars.begin(); it != cars.end();) {
        if ((*it)->getLicensePlate() == plate) {
            cars.erase(it);  // Remove it from the vector
            return;
        } 
        else{
            ++it; //increments if there are no errors
        }
    }
    cout << "Car with plate " << plate << " not found.\n";
}

void ParkingLot::displayCars() const{
    if (cars.empty()) {
            cout << "No cars in the parking lot.\n";
    }

    else{
        for(int i = 0; i < cars.size(); i++){
            cout << "Car " << i + 1 << ": " << cars[i] << endl;
        }
    }
}
