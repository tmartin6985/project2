/*
Project: CSC 1310 Lab Program 2: Parking Lot Manager
File: Driver.cpp
Authors: Tristen Martin, Matt Nokes
Date: 11.5.2024
*/

#include "LinkedList.h"
#include "ParkingLot.h"
#include "smartpointer.h"
#include <iostream>
using namespace std;

int main(){
    int userMenuOption = 0; 
    int numParkingLots = 0; // might be used in a future print statement
    int lotIndex;
    string plate, color, make, model, carAttribute;
    LinkedList<ParkingLot> parkingLots;

    cout << "Welcome to the Tennessee Tech Parking Lot Manager\n";

    do{
        cout << "\n****************************************************************\n";
        cout << "\nPick an option:\n";
        cout << "1. Create Parking Lot\n";
        cout << "2. View Cars in Parking Lot\n";
        cout << "3. Add Car to Parking Lot\n";
        cout << "4. Remove Car from Parking Lot\n";
        cout << "5. Sort Cars in Parking Lot\n";
        cout << "6. Exit Program\n";
        cout << "CHOICE: ";
        cin >> userMenuOption;

        if(userMenuOption == 1){ // create parking lot
            cout << "Attempting to create a new parking lot..." << endl; //for bug testing
            SmartPointer<ParkingLot> newLot(new ParkingLot());
            parkingLots.add(newLot);
            cout << "Parking lot created.\n";
            numParkingLots++;
        } 

        else if(userMenuOption == 2){ // view cars in parking lot
            if (parkingLots.getSize() <= 0){
                cout << "No parking lots available. Create at least one parking lot and one car first.\n";
            } 
            
            else{
                for(int i = 0; i < parkingLots.getSize(); i++){
                    cout << "\nParking Lot " << i + 1 << ":\n";
                    parkingLots.get(i)->displayCars();
                }
            }
        } 
        
        else if(userMenuOption == 3){ // add car to parking lot
            if(parkingLots.getSize() <= 0){
                cout << "No parking lots available. Create at least one parking lot and one car first.\n";
            }

            else {
                do {
                    cout << "Enter parking lot index (1 to " << parkingLots.getSize() << "): ";
                    cin >> lotIndex;
                    cin.ignore();

                    if (lotIndex < 1 || lotIndex > parkingLots.getSize()) {
                        cout << "Invalid parking lot index.\n";
                    }
                } while (lotIndex < 1 || lotIndex > parkingLots.getSize());

                cout << "Enter the car's license plate: ";
                getline(cin, plate);
                cout << "Enter the car's make: ";
                getline(cin, make);
                cout << "Enter the car's model: ";
                getline(cin, model);
                cout << "Enter the car's color: ";
                getline(cin, color);

                parkingLots.get(lotIndex - 1)->addCar(plate, color, make, model);
                cout << "Car added.\n";
    }
        } 
        
        else if(userMenuOption == 4){ // remove car from parking lot
            if (parkingLots.getSize() <= 0){
                cout << "No parking lots available. Create at least one parking lot and one car first.\n";
            }

            else{
                cout << "Available parking lots: " << parkingLots.getSize() << endl; // Debug
                for (int i = 0; i < parkingLots.getSize(); ++i) {
                    cout << "\nParking Lot " << i + 1 << ":\n";
                    parkingLots.get(i)->displayCars();
                }

                if(parkingLots.getSize() <= 0){
                    cout << "No parking lots available. Create at least one parking lot and one car first.\n";
                }

                else{
                    do{
                        cout << "Enter parking lot index (1 to " << parkingLots.getSize() << "): ";
                        cin >> lotIndex;
                        if (lotIndex < 1 || lotIndex > parkingLots.getSize()){
                            cout << "Invalid parking lot index.\n";
                        }
                    } while (lotIndex < 1 || lotIndex > parkingLots.getSize());
                    cout << "Enter the car's license plate to remove: ";
                    getline(cin, plate);
                    parkingLots.get(lotIndex - 1) -> removeCar(plate);
                }
            }
        }
        
        else if(userMenuOption == 5){ // bubble sort cars in parking lot
            if(parkingLots.getSize() <= 0){
                cout << "No parking lots available. Create at least one parking lot and one car first.\n";
            } 
            
            else{
                do{
                    cout << "Enter parking lot index (1 to " << parkingLots.getSize() << "): ";
                    cin >> lotIndex;
                    cin.ignore();

                    if(lotIndex < 1 || lotIndex > parkingLots.getSize()){
                        cout << "Invalid parking lot index.\n";
                    }
                } while (lotIndex < 1 || lotIndex > parkingLots.getSize());

                cout << "Enter the car attribute to sort by ('make', 'model', or 'color'): ";
                cin >> carAttribute;
                parkingLots.get(lotIndex - 1)->sortCars(carAttribute);
                cout << "Cars sorted.\n";
            }
        } 

        else if(userMenuOption == 6){ // exit program
            cout << "Exiting Program...\n";
        } 
        
        else{
            cout << "Invalid Option: " << userMenuOption << "\n";
            userMenuOption = 0;
        }

    } while(userMenuOption != 6);
    return 0;
}
