/**
 *  Michael Dorst
 *  Assignment 2
 *  Parking Lot
 *
 *  car.h
 */

#ifndef Parking_Lot__car_h
#define Parking_Lot__car_h

#include <string>

class car {
    std::string description;
    
public:
    car() = delete;
    car(std::string&& d) : description(std::move(d)) {
        
    }
    friend std::ostream& operator << (std::ostream&, car&);
};

#endif
