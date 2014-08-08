/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  car.cpp
 */

#include "car.h"
#include <cstdlib>

random_generator::random_generator() : generator(std::random_device().operator()()) {}

random_generator car_t::rand;

uint32_t random_generator::operator()() {
    return distribution(generator);
}

car_t::car_t(const std::string& pn, const std::string& dscptn, const date_t& date) :
plate_number(pn), description(dscptn),
_date(date), inv_num(rand()) {
    capitolize_plate_number();
}

car_t::car_t(std::string&& pn, std::string&& dscptn, const date_t& date) :
plate_number(std::move(pn)), description(std::move(dscptn)),
_date(date), inv_num(rand()) {
    capitolize_plate_number();
}

car_t::inv_num_t car_t::inventory_number()const {
    return inv_num;
}

date_t car_t::date()const {
    return _date;
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
    <<"Inventory #: "<<car.inv_num<<std::endl
    <<"Plate #: "<<car.plate_number<<std::endl
    <<"Description: "<<car.description<<std::endl
    <<"Date purchased: "<<car.date()<<std::endl;
    return out;
}
