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
#include <ciso646>

class car_t {
    
    uint32_t inv_num;
    date_t _date;
    std::string plate_number;
    std::string description;
    
    void capitolize_plate_number();
    
public:
    
    car_t(const std::string& pn, const std::string& d);
    car_t(std::string&& pn, std::string&& d);
    
    uint32_t inventory_number()const;
    date_t date()const;
    
    friend std::ostream& operator << (std::ostream&, const car_t&);
    
};

#endif
