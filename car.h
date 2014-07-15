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
    /**
     * unsigned short sequence
     **
     * The above is unnecessary for this application,
     * as a std::deque keeps track of the order
     * of its elements for you.
     * Also, the maximum value of an unsigned short on my system is 65535.
     * That might well be insufficient in an extreme case; certainly a
     * std::deque can hold many more elements than that.
     * Perhaps size_t, uint64_t, or simply unsigned long would be a better choice.
     */
    double amount_paid;
    std::string description;
    
public:
    
};

#endif
