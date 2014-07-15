/**
 *  Michael Dorst
 *  Assignment 1
 *  Car Wash
 *
 *  car.h
 */

#ifndef Car_Wash__car_h
#define Car_Wash__car_h

#include <string>

class car {
    double amount_paid;
    std::string description;
public:
    void set_amount_paid(double ap)       { amount_paid = ap; }
    void set_description(std::string& d)  { description = d;  }
    void set_description(std::string&& d) { description = d;  }
};

#endif
