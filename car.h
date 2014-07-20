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
    car(std::string&& pn, std::string&& d) :
    plate_number(std::move(pn)), description(std::move(d)),
    time_in(std::time(nullptr)) {}
    
    friend std::ostream& operator << (std::ostream&, const car&);
    friend bool operator <  (const car&, const car&);
    friend bool operator <= (const car&, const car&);
    friend bool operator == (const car&, const car&);
    friend bool operator >= (const car&, const car&);
    friend bool operator >  (const car&, const car&);
};

#endif
