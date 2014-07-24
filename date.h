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

class date {
    
    uint16_t _month;
    uint16_t _day;
    uint16_t _year;
    
public:
    
    date(uint16_t m = 1, uint16_t d = 1, uint16_t y = 2000) : _year(y) {
        if (m > 0 and m <= 12) {
            _month = m;
        } else {
            _month = 1;
        }
        uint16_t max_days;
        switch (_month) {
            case 4:
            case 6:
            case 9:
            case 11:
                max_days = 30;
                break;
            case 2:
                if (_year % 4) {
                    max_days = 29;
                } else {
                    max_days = 28;
                }
                break;
            default:
                max_days = 31;
                break;
        }
        if (d > 0 and d <= max_days) {
            _day = d;
        } else {
            _day = 1;
        }
    }
    
    uint16_t month() { return _month; }
    uint16_t day() { return _day; }
    uint16_t year() { return _year; }
    
    friend std::ostream& operator << (std::ostream&, const date&);
    friend std::istream& operator >> (std::istream&, date&);
};

std::ostream& operator << (std::ostream& out, const date& d) {
    return out<<d._month<<"/"<<d._day<<"/"<<d._year;
}

std::istream& operator >> (std::istream& in, date& d) {
    using std::tie;
    std::string input;
    uint16_t month, day, year;
    std::getline(in, input, '/');
    month = (uint16_t)atoi(input.c_str());
    std::getline(in, input, '/');
    day = (uint16_t)atoi(input.c_str());
    std::getline(in, input, '\n');
    year = (uint16_t)atoi(input.c_str());
    
    d = date(month, day, year);
    if (d.month() != month or d.day() != day or d.year() != year) {
        in.setstate(std::ios::failbit);
    }
    return in;
}

#endif