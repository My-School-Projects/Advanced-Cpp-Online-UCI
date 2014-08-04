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
    success = map_by_inv_num.insert(make_pair(car.inventory_number(), car)).second;
    if (success) {
        map_by_date.insert(make_pair(car.date(), car));
    }
    return success;
}

void lot_t::erase(lot_t::iterator_by_inv_num& it) {
    /**
     * First, find the range of cars with the same date as the car
     * pointed to by it
     */
    auto d_it_r = map_by_date.equal_range(it->date());
    /**
     * Then find the car in that range with the correct inventory number
     * and delete it
     */
    for (auto i = d_it_r.first; i != d_it_r.second; i++) {
        if (i->second.inventory_number() == it->inventory_number()) {
            map_by_date.erase(i);
            break;
        }
    }
    /**
     * Then erase the entry in map_by_inv_num
     */
    map_by_inv_num.erase(it._it);
}

void lot_t::erase(lot_t::iterator_by_date& it) {
    /**
     * First, find and erase the matching entry in map_by_inv_num
     */
    map_by_inv_num.erase(map_by_inv_num.find(it->inventory_number()));
    /**
     * Then erase the entry in map_by_date
     */
    map_by_date.erase(it._it);
}

lot_t::iterator_by_inv_num lot_t::find_by_inv_num(const car_t::inv_num_t& inv_num) {
    return map_by_inv_num.find(inv_num);
}

lot_t::iterator_by_date lot_t::find_by_date(const date_t& date) {
    return map_by_date.find(date);
}

lot_t::iterator_by_inv_num lot_t::begin_by_inv_num() {
    return map_by_inv_num.begin();
}

lot_t::iterator_by_inv_num lot_t::end_by_inv_num() {
    return map_by_inv_num.end();
}

lot_t::iterator_by_date lot_t::begin_by_date() {
    return map_by_date.begin();
}

lot_t::iterator_by_date lot_t::end_by_date() {
    return map_by_date.end();
}

lot_t::const_iterator_by_inv_num lot_t::cbegin_by_inv_num()const {
    return map_by_inv_num.cbegin();
}

lot_t::const_iterator_by_inv_num lot_t::cend_by_inv_num()const {
    return map_by_inv_num.cend();
}

lot_t::const_iterator_by_date lot_t::cbegin_by_date()const {
    return map_by_date.cbegin();
}

lot_t::const_iterator_by_date lot_t::cend_by_date()const {
    return map_by_date.cend();
}
