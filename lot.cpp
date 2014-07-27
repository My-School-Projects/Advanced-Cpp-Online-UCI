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
    
    /**
     * 'std::map::insert' returns a 'std::pair<iterator, bool>'.
     * The boolean is there to tell if the operation failed
     * due to the presence of an identical key.
     * The call to 'second' isolates the boolean
     * for storage in 'success'.
     */
    success = by_inv_num.insert(make_pair(car.inventory_number(), car)).second;
    if (success) {
        by_date.insert(make_pair(car.date(), car));
    }
    return success;
}

std::map<car_t::inv_num_t, car_t>::const_iterator lot_t::cbegin_by_inv_num()const {
    return by_inv_num.cbegin();
}

std::map<car_t::inv_num_t, car_t>::const_iterator lot_t::cend_by_inv_num()const {
    return by_inv_num.cend();
}

std::multimap<date_t, car_t>::const_iterator lot_t::cbegin_by_date()const {
    return by_date.cbegin();
}

std::multimap<date_t, car_t>::const_iterator lot_t::cend_by_date()const {
    return by_date.cend();
}
