/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  car.h
 */

#ifndef Used_Car_Dealership__car_h
#define Used_Car_Dealership__car_h

#include <string>

class car {
    
    std::string plate_number;
    std::string description;
    
public:
    
    car(const std::string& pn, const std::string& d) :
    plate_number(pn), description(d) {}
    
    car(std::string&& pn, std::string&& d) :
    plate_number(std::move(pn)), description(std::move(d)) {}
    
    friend std::ostream& operator << (std::ostream&, const car&);
    
};

#endif
