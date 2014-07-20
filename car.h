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
#include <ctime>

class car {
    std::string plate_number;
    std::string description;
    std::time_t time_in;
    
public:
    car() = delete;
    car(std::string&& pn, std::time_t t, std::string&& d) :
    plate_number(pn), time_in(t), description(std::move(d)) {}
    
    friend std::ostream& operator << (std::ostream&, car&);
};

#endif
