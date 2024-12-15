#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Car.h"
#include "smartpointer.h"
#include <vector>

using namespace std;

class ParkingLot {
private:
    vector<SmartPointer<Car>> cars;

public:
    ParkingLot();
    void addCar(const string& plate, const string& color, const string& make, const string& model);
    void removeCar(const string& plate);
    void displayCars() const;
    void sortCars(const string& carAttribute);
    void quickSort(int low, int high, const string& carAttribute);
    int partition(int low, int high, const string& carAttribute);
    void swap(int i, int j);
    friend ostream& operator << (ostream& os, const ParkingLot& lot) {
        os << "Parking Lot [Cars: " << lot.cars.size() << "]";
        return os;
    }
};

#endif // PARKINGLOT_H
