/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  date.h
 */

#include "date.h"


std::ostream& operator << (std::ostream& out, const date_t& d) {
    return out<<d._month<<"/"<<d._day<<"/"<<d._year;
}

std::istream& operator >> (std::istream& in, date_t& d) {
    using std::tie;
    std::string input;
    uint16_t month, day, year;
    std::getline(in, input, '/');
    month = (uint16_t)atoi(input.c_str());
    std::getline(in, input, '/');
    day = (uint16_t)atoi(input.c_str());
    std::getline(in, input, '\n');
    year = (uint16_t)atoi(input.c_str());
    
    d = date_t(month, day, year);
    if (d.month() != month or d.day() != day or d.year() != year) {
        in.setstate(std::ios::failbit);
    }
    return in;
}
