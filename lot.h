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
    
    std::map<car_t::inv_num_t, car_t> by_inv_num;
    std::multimap<date_t, car_t> by_date;
    
public:
    
    bool insert(car_t car);
    
    std::map<car_t::inv_num_t, car_t>::const_iterator begin_by_inv_num();
    std::map<car_t::inv_num_t, car_t>::const_iterator end_by_inv_num();
    std::multimap<date_t, car_t>::const_iterator begin_by_date();
    std::multimap<date_t, car_t>::const_iterator end_by_date();
    
};

#endif
