/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  car.h
 */

#ifndef Used_Car_Dealership__car_h
#define Used_Car_Dealership__car_h

#include <string>
#include <ctime>

class car {
    std::string plate_number;
    std::string description;
    std::time_t time_in;
    
public:
    std::time_t get_time_in()const {
        return time_in;
    }
    
    car() = delete;
    car(std::string&& pn, std::string&& d) :
    plate_number(std::move(pn)), description(std::move(d)),
    time_in(std::time(nullptr)) {}
    
    friend std::ostream& operator << (std::ostream&, const car&);
    friend bool operator <  (const car&, const car&);
};

#endif
