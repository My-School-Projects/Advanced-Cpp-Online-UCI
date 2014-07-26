/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  date.h
 */

#ifndef Used_Car_Dealership__date_h
#define Used_Car_Dealership__date_h

#include <iostream>
#include <ciso646>

class date_t {
    
    uint16_t _month;
    uint16_t _day;
    uint16_t _year;
    
public:
    
    date_t(uint16_t m = 1, uint16_t d = 1, uint16_t y = 2000);
    uint16_t month()const;
    uint16_t day()const;
    uint16_t year()const;
    
    friend std::istream& operator >> (std::istream&, date_t&);
};

bool operator < (const date_t&, const date_t&);

#endif
