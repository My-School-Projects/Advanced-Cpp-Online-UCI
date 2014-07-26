/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  lot.h
 */

#ifndef Used_Car_Dealership__lot_h
#define Used_Car_Dealership__lot_h

#include "car.h"
#include <map>
#include <ciso646>

class lot_t {
    
    std::map<std::string, car_t> by_plate;
    std::multimap<date_t, car_t> by_date;
    
public:
    
    
    
};

#endif
