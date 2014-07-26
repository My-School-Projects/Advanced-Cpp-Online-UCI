/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  lot.cpp
 */

#include "lot.h"

bool lot_t::insert(car_t car) {
    using std::make_pair;
    
    bool success;
    success = by_inv_num.insert(make_pair(car.inventory_number(), car)).second;
    if (success) {
        by_date.insert(make_pair(car.date(), car));
    }
    return success;
}
