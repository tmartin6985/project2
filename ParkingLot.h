#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <vector>
#include "Car.h"
using namespace std;

class ParkingLot {
private:
    vector<Car*> cars;  // Dynamically allocated cars

public:
    ParkingLot() {}

    ~ParkingLot() {
        for (Car* car : cars) {
            delete car;  // Clean up dynamically allocated cars
        }
    }

    void addCar(const string& plate) {
        cars.push_back(new Car(plate));  // Dynamically allocate cars
    }

    void removeCar(const string& plate) {
        for (auto it = cars.begin(); it != cars.end(); ++it) {
            if ((*it)->getLicensePlate() == plate) {
                delete *it;  // Delete the car
                cars.erase(it);  // Remove it from the vector
                return;
            }
        }

        cout << "Car with plate " << plate << " not found.\n";
    }

    void displayCars() const {
        if (cars.empty()) {
            cout << "No cars in the parking lot.\n";
        } else {
            for (const auto& car : cars) {
                cout << *car << endl;
            }
        }
    }

    friend ostream& operator << (ostream& os, const ParkingLot& lot) {
        os << "Parking Lot [Cars: " << lot.cars.size() << "]";
        return os;
    }
};

#endif // PARKINGLOT_H
