/*
Project: CSC 1310 Lab Program 2: Parking Lot Manager
File: Driver.cpp
Authors: Tristen Martin, Matt Nokes
Date: 11.5.2024
*/

#include "LinkedList.h"
#include "ParkingLot.h"
#include <iostream>
using namespace std;

int main(){
    int userMenuOption = 0; 
    int numParkingLots = 0; // might be used in a future print statement
    LinkedList<ParkingLot> parkingLots;

    cout << "Welcome to the Tennessee Tech Parking Lot Manager\n";

    do{
        cout << "\nPick an option:\n";
        cout << "1. Create Parking Lot\n";
        cout << "2. View Cars in Parking Lot\n";
        cout << "3. Add Car to Parking Lot\n";
        cout << "4. Remove Car from Parking Lot\n";
        cout << "5. Exit Program\n";
        cout << "CHOICE: ";
        cin >> userMenuOption;

        if(userMenuOption == 1){ // create parking lot
            ParkingLot* newLot = new ParkingLot();
            parkingLots.add(newLot);
            cout << "Parking lot created.\n";
            numParkingLots++;
        } 

        else if(userMenuOption == 2){ // view cars in parking lot
            if (parkingLots.getSize() == 0){
                cout << "No parking lots available.\n";
            } 
            
            else{
                for(int i = 0; i < parkingLots.getSize(); ++i){
                    cout << "Parking Lot " << i + 1 << ":\n";
                    parkingLots.get(i)->displayCars();
                }
            }
        } 
        
        else if(userMenuOption == 3){ // add car to parking lot
            int lotIndex;
            string plate;
            
            cout << "Enter parking lot index (1 to " << parkingLots.getSize() << "): ";
            cin >> lotIndex;

            if (lotIndex < 1 || lotIndex > parkingLots.getSize()){
                cout << "Invalid parking lot index.\n";
            }

            cout << "Enter the car's license plate: ";
            cin >> plate;
            parkingLots.get(lotIndex - 1)->addCar(plate);
            cout << "Car added.\n";
        } 
        
        else if(userMenuOption == 4){ // remove car from parking lot
            int lotIndex;
            string plate;

            if (parkingLots.getSize() == 0){
                cout << "No parking lots available. Create at least one parking lot and one car first.\n";
            }

            else{
                cout << "Available parking lots and cars:\n";
                for (int i = 0; i < parkingLots.getSize(); ++i) {
                    cout << "Parking Lot " << i + 1 << ":\n";
                    parkingLots.get(i)->displayCars();
                }
            
                cout << "Enter parking lot index (1 to " << parkingLots.getSize() << "): ";
                cin >> lotIndex;
                if (lotIndex < 1 || lotIndex > parkingLots.getSize()){
                    cout << "Invalid parking lot index.\n";
                    break;
                }

                cout << "Enter the car's license plate to remove: ";
                cin >> plate;
                parkingLots.get(lotIndex - 1) -> removeCar(plate);
            }
        } 
        
        else if(userMenuOption == 5){
            cout << "Exiting Program...\n";

            for (int i = 0; i < parkingLots.getSize(); ++i) { // this might be broken as the program seg faults when exiting
                delete parkingLots.get(i);
            }
        } 
        
        else {
            cout << "Invalid Option: " << userMenuOption << "\n";
            userMenuOption = 0;
        }

    } while(userMenuOption != 5);

    return 0;
}
