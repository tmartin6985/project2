#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
using namespace std;

class Car {
private:
    string licensePlate, color, make, model;

public:
    // constructor
    Car(const string& plate, const string& carColor, const string& carMake, const string& carModel) {
        licensePlate = plate;
        color = carColor;
        make = carMake;
        model = carModel;
    }

    string getLicensePlate() const { return licensePlate; }
    string getColor() const { return color; }
    string getMake() const { return make; }
    string getModel() const { return model; }

    // prints car attributes
    friend ostream& operator<<(ostream& os, const Car& car) {
        os << "\n- License Plate:\t" << car.licensePlate << "\n- Make:\t\t\t" << car.make << "\n- Model:\t\t" << car.model << "\n- Color:\t\t" << car.color << endl;        return os;
    }
};

#endif // CAR_H
