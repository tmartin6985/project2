/*
Project: CSC 1310 Lab Program 2: Parking Lot Manager
File: Driver.cpp
Authors: Tristen Martin, Matt Nokes
Date: 11.5.2024
*/

#include "DataClass.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(){
    int userMenuOption = 0; 

    do{
        cout << "Welcome to the Tennessee Tech Parking Lot Manager\n";
        cout << "Pick an option:\n";
        cout << "1.\tView Cars in Parking Lot\n";
        cout << "2.\tAdd Car to Parking Lot\n";
        cout << "3.\tRemove Car from Parking Lot\n";
        cout << "4.\tExit Program\n";
        cout << "CHOICE: ";
        cin >> userMenuOption;
    } while(userMenuOption != 4) // I chose 4 as the exit option but this can be changed at any time

    return 0;
}
