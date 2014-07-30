/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  date.h
 */

#include "date.h"

date_t::date_t(uint16_t m, uint16_t d, uint16_t y) : _year(y) {
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

uint16_t date_t::month()const {
    return _month;
}
uint16_t date_t::day()const {
    return _day;
}
uint16_t date_t::year()const {
    return _year;
}

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
    std::cin.putback('\n');
    
    d = date_t(month, day, year);
    if (d.month() != month or d.day() != day or d.year() != year) {
        in.setstate(std::ios::failbit);
    }
    return in;
}
