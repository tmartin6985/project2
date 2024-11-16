#ifndef PARKING_LOT_H
#define PARKING_LOT_H

#include <iostream>
using namespace std;

// *********** unfinished

class ParkingLot{
    private:
        int totalCars; // total number of cars currently in a parking lot
        int maxCars; // maximum capacity of cars for a parking lot

    public:
        ParkingLot(); // constructor

        ~ParkingLot(); // destructor

        int getTotalCars(){
            return totalCars;
        }

        int getMaxCars(){
            return maxCars;
        }

        bool isAtCapacty(){ // checks to see if a parking lot is ful or not
            if(totalCars == maxCars){
                return true;
            }

            else if(totalCars < maxCars){
                return false;
            }
        }


};

#endif
