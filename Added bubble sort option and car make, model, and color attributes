#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
using namespace std;

class Car {
private:
    string licensePlate;
    string color;
    string make;
    string model;

public:
    // constructor
    Car(const string& plate, const string& carColor, const string& carMake, const string& carModel) {
        licensePlate = plate;
        color = carColor;
        make = carMake;
        model = carModel;
    }

    // getters
    string getLicensePlate() const { return licensePlate; }
    string getColor() const { return color; }
    string getMake() const { return make; }
    string getModel() const { return model; }

    // prints car data
    friend ostream& operator<<(ostream& os, const Car& car) {
        os << "License Plate: " << car.licensePlate << "\nMake: " << car.make << "\nModel: " << car.model << "\nColor: " << car.color << endl;
        return os;
    }
};

#endif // CAR_H
