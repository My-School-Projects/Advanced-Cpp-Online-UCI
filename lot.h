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

typedef unsigned date_t;

class lot {
    
    std::map<std::string, car> by_plate;
    std::multimap<date_t, car> by_date;
    
public:
    
};

#endif
