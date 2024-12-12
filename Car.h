#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
#include "smartpointer.h"
using namespace std;

class Car {
private:
    string licensePlate;

public:
    Car(const string& plate) {
        this->licensePlate = plate;
    }

    string getLicensePlate() const {
        return licensePlate;
    }

    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << "Car [License Plate: " << car.licensePlate << "]";
        return os;
    }
};

#endif // CAR_H
