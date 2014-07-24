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

class car {
    
    std::string plate_number;
    std::string description;
    
    void capitolize_plate_number();
    
public:
    
    car(const std::string& pn, const std::string& d);
    
    car(std::string&& pn, std::string&& d);
    
    friend std::ostream& operator << (std::ostream&, const car&);
    
};

#endif
