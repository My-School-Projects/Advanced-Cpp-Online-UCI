/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  car.cpp
 */

#include "car.h"

car::car(const std::string& pn, const std::string& d) :
plate_number(pn), description(d) {
    capitolize_plate_number();
}

car::car(std::string&& pn, std::string&& d) :
plate_number(std::move(pn)), description(std::move(d)) {
    capitolize_plate_number();
}

void car::capitolize_plate_number() {
    for (size_t i = 0; i < plate_number.length(); i++) {
        if (plate_number[i] >= 0x61 and plate_number[i] <= 0x7A) {
            plate_number[i] -= 0x20;
        }
    }
}
