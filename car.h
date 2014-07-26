/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  car.h
 */

#ifndef Used_Car_Dealership__car_h
#define Used_Car_Dealership__car_h

#include "date.h"
#include <iostream>
#include <string>

class car_t {
    
    uint32_t inventory_number;
    std::string plate_number;
    std::string description;
    
    void capitolize_plate_number();
    
public:
    
    car_t(const std::string& pn, const std::string& d);
    
    car_t(std::string&& pn, std::string&& d);
    
    friend std::ostream& operator << (std::ostream&, const car_t&);
    
};

#endif
