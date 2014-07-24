/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  car.cpp
 */

#include "car.h"
#include <iostream>

car_t::car_t(const std::string& pn, const std::string& d) :
plate_number(pn), description(d), inventory_number(arc4random()) {
    capitolize_plate_number();
}

car_t::car_t(std::string&& pn, std::string&& d) :
plate_number(std::move(pn)), description(std::move(d)), inventory_number(arc4random()) {
    capitolize_plate_number();
}

void car_t::capitolize_plate_number() {
    for (size_t i = 0; i < plate_number.length(); i++) {
        if (plate_number[i] >= 0x61 and plate_number[i] <= 0x7A) {
            plate_number[i] -= 0x20;
        }
    }
}

std::ostream& operator << (std::ostream& out, const car_t& car) {
    out
    <<"Inventory #: "<<car.inventory_number
    <<"Plate #: "<<car.plate_number<<std::endl
    <<"Description: "<<car.description<<std::endl;
    return out;
}
