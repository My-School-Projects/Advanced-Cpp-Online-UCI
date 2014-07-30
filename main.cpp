/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  main.cpp
 */

#include "lot.h"
#include <iostream>
#include <iomanip>
#include <ciso646>
#include "io_helper.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;

void add_car(lot_t&);
void exit_car(lot_t&);
enum sort {
    by_inv_num, by_date, ask
};
void print_lot(const lot_t&, sort = ask);

int main() {
    
    lot_t lot;
    
    string response;
    
    prompt_clear_screen();
    
    clear_screen();
    
    do {
        if (response == "") {
            cout<<endl;
            add_car(lot);
            clear_screen();
        } else if (response == constant::exit_car) {
            exit_car(lot);
        } else if (response == constant::print_lot) {
            print_lot(lot);
        } else if (response == constant::quit) {
            return 0;
        }
        
        do {
            cout<<endl
            <<"Press [return] to enter a new car..."<<endl
            <<"Type '"<<constant::exit_car<<"' exit a car"<<endl
            <<"Type '"<<constant::print_lot<<"' to view all the cars in the lot"<<endl
            <<"Type '"<<constant::quit<<"' to stop the program"<<endl
            <<">> ";
            std::getline(cin, response);
            clear_screen();
            
        } while (response != "" and
                 response != constant::exit_car and
                 response != constant::print_lot and
                 response != constant::quit);
        
    } while (response != constant::quit);
}

void add_car(lot_t& lot) {
    
    string plate_number = get_input<string>("Enter the car's licence plate #");
    string description = get_input<string>("Enter the car's description");
    date_t date = get_input<date_t>
    ("Enter the date the car was bought (mm/dd/yyyy)",
     "Please enter a date in the format (mm/dd/yyyy)");
    
    /**
     * It is extremely unlikely, but still technically possible
     * that car_t's constructor will create a car with the same
     * inventory number as one already in lot. The call to insert
     * is the condition to the following empty while loop so that,
     * if this were to happen, a new car would be constructed with
     * the same data, and lot.insert would be called again.
     */
    while (lot.insert(car_t(plate_number, description, date)) == false) {}
}

void print_lot(const lot_t& lot, sort sort) {
    string response;
    if (sort == ask) {
        do {
            cout<<endl
            <<"Type '"<<constant::by_inv_num
            <<"' to view cars sorted by inventory number"<<endl
            <<"Type '"<<constant::by_date
            <<"' to view cars sorted by date"<<endl
            <<">> ";
            std::getline(cin, response);
            clear_screen();
        } while (response != constant::by_date and
                 response != constant::by_inv_num);
    } else if (sort == by_date) {
        response = constant::by_date;
    } else {
        response = constant::by_inv_num;
    }
    if (response == constant::by_date) {
        for (auto i = lot.cbegin_by_date(); i != lot.cend_by_date(); i++) {
            cout<<endl<<*i;
        }
    } else {
        for (auto i = lot.cbegin_by_inv_num(); i != lot.cend_by_inv_num(); i++) {
            cout<<endl<<*i;
        }
    }
}

void exit_car(lot_t& lot) {
    string response;
    do {
        cout<<endl
        <<"Type '"<<constant::by_inv_num
        <<"' to select car by inventory number"<<endl
        <<"Type '"<<constant::by_date
        <<"' to select car by date"<<endl
        <<">> ";
        std::getline(cin, response);
        clear_screen();
    } while (response != constant::by_date and
             response != constant::by_inv_num);
    clear_screen();
    if (response == constant::by_date) {
        print_lot(lot, by_date);
        do {
            date_t date = get_input<date_t>
            ("Enter the date the car was bought (mm/dd/yyyy)",
             "Please enter a date in the format (mm/dd/yyyy)");
            auto it = lot.find_by_date(date);
            if (it == lot.end_by_date()) {
                cout<<"No car was found with the date "<<date<<"."<<endl;
                continue;
            } else {
                clear_screen();
                cout<<endl<<"The exiting car:"<<endl<<*it<<endl;
                lot.erase(it);
                break;
            }
        } while (true);
    } else {
        print_lot(lot, by_inv_num);
        do {
            car_t::inv_num_t inv_num = get_input<car_t::inv_num_t>
            ("Enter the the inventory number for the car",
             "Please enter a valid inventory number");
            auto it = lot.find_by_inv_num(inv_num);
            if (it == lot.end_by_inv_num()) {
                cout<<"No car was found with the inventory number "
                <<inv_num<<"."<<endl;
                continue;
            } else {
                clear_screen();
                cout<<endl<<"The exiting car:"<<endl<<*it<<endl;
                lot.erase(it);
                break;
            }
        } while (true);
    }
}
