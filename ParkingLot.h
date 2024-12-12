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
    ParkingLot();
    void addCar(const string& plate);
    void removeCar(const string& plate);
    bool displayCars() const;

    friend ostream& operator << (ostream& os, const ParkingLot& lot) {
        os << "Parking Lot [Cars: " << lot.cars.size() << "]";
        return os;
    }
};

#endif // PARKINGLOT_H
