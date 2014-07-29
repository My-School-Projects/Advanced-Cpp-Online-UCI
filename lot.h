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
    
    typedef std::map<car_t::inv_num_t, car_t> map_by_inv_num;
    typedef std::multimap<date_t, car_t> map_by_date;
    
    map_by_inv_num by_inv_num;
    map_by_date by_date;
    
    template <class It>
    class iter {
        It _it;
    public:
        iter() = default;
        iter(It it) : _it(it) {}
        decltype(_it->second) operator * () {
            return _it->second;
        }
        bool operator == (const iter<It>& it)const {
            return this->_it == it._it;
        }
        bool operator != (const iter<It>& it)const {
            return not (*this == it);
        }
        iter<It>& operator ++ (int) {
            _it++;
            return *this;
        }
    };
    
public:
    
    bool insert(car_t car);
    
    iter<map_by_inv_num::iterator> begin_by_inv_num();
    iter<map_by_inv_num::iterator> end_by_inv_num();
    iter<map_by_date::iterator> begin_by_date();
    iter<map_by_date::iterator> end_by_date();
    iter<map_by_inv_num::const_iterator> cbegin_by_inv_num()const;
    iter<map_by_inv_num::const_iterator> cend_by_inv_num()const;
    iter<map_by_date::const_iterator> cbegin_by_date()const;
    iter<map_by_date::const_iterator> cend_by_date()const;
    
};

#endif
