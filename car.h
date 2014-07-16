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
    std::string description;
    double amount_paid;
public:
    void set_description(std::string& d)  { description = d;  }
    void set_description(std::string&& d) { description = d;  }
    void set_amount_paid(double ap) {
        if (ap >= 0) {
            amount_paid = ap;
        }
    }
    car() = default;
    car(std::string& d, double ap) : description(d) {
        set_amount_paid(ap);
    }
    car(std::string&& d, double ap) : description(d) {
        set_amount_paid(ap);
    }
    friend std::ostream& operator << (std::ostream&, car&);
};

#endif
