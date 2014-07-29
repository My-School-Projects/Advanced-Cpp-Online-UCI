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
        friend lot_t;
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
    
    typedef iter<map_by_inv_num::iterator> iterator_by_inv_num;
    typedef iter<map_by_inv_num::const_iterator> const_iterator_by_inv_num;
    typedef iter<map_by_date::iterator> iterator_by_date;
    typedef iter<map_by_date::const_iterator> const_iterator_by_date;
    
    bool insert(car_t car);
    
    void erase(const iterator_by_inv_num& it);
    void erase(const iterator_by_date& it);
    
    iterator_by_inv_num find_by_inv_num(const car_t::inv_num_t& inv_num);
    iterator_by_date find_by_date(const date_t& date);
    
    iterator_by_inv_num begin_by_inv_num();
    iterator_by_inv_num end_by_inv_num();
    iterator_by_date begin_by_date();
    iterator_by_date end_by_date();
    const_iterator_by_inv_num cbegin_by_inv_num()const;
    const_iterator_by_inv_num cend_by_inv_num()const;
    const_iterator_by_date cbegin_by_date()const;
    const_iterator_by_date cend_by_date()const;
    
};

#endif
