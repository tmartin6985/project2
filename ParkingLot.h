#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Car.h"
#include "smartpointer.h"
#include <vector>

using namespace std;

class ParkingLot {
private:
    vector<SmartPointer<Car>> cars;  // Dynamically allocated cars

public:
    ParkingLot() {}

    void addCar(const string& plate) {
         cars.push_back(SmartPointer<Car>(new Car(plate)));  // Dynamically allocate cars
    }

    void removeCar(const string& plate) {
        for (auto it = cars.begin(); it != cars.end();) {
            if ((*it)->getLicensePlate() == plate) {
                cars.erase(it);  // Remove it from the vector
                return;
            } else {
                ++it; //increments if there are no errors
            }
        }

        cout << "Car with plate " << plate << " not found.\n";
    }

    void displayCars() const {
        if (cars.empty()) {
            cout << "No cars in the parking lot.\n";
        } else {
            for (const auto& car : cars) {
                cout << car << endl;
            }
        }
    }

    friend ostream& operator << (ostream& os, const ParkingLot& lot) {
        os << "Parking Lot [Cars: " << lot.cars.size() << "]";
        return os;
    }
};

#endif // PARKINGLOT_H
