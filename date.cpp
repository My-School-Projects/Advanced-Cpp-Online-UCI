/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  date.h
 */

#include "date.h"

bool operator < (const date_t& lhv, const date_t& rhv) {
    if (lhv.year() == rhv.year()) {
        if (lhv.month() == rhv.month()) {
            return lhv.day() < rhv.day();
        } else {
            return lhv.month() < rhv.month();
        }
    } else {
        return lhv.year() < rhv.year();
    }
}

std::ostream& operator << (std::ostream& out, const date_t& d) {
    return out<<d.month()<<"/"<<d.day()<<"/"<<d.year();
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
