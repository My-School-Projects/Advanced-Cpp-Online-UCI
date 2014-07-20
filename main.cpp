/**
 *  Michael Dorst
 *  Assignment 2
 *  Parking Lot
 *
 *  main.cpp
 */

#include "car.h"
#include <iostream>
#include <iomanip>
#include <set>

void clear_screen();
void print_title(std::string title, int width, char = '*', std::ostream& = std::cout);
void add_car(std::set<car>&);
void print_lot(std::set<car>&);

namespace option {
    bool clear_screen_enabled;
}

namespace constant {
    std::string title = " Welcome to the Parking Lot ";
    std::string exit_car = "x";
    std::string print_lot = "r";
    std::string quit = "q";
}

int main() {
    using std::cout; using std::endl; using std::cin;
    std::set<car> lot;
    
    std::string response;
    
    cout<<"This program would like your permission to clear the terminal."<<endl
    <<"Warning: this option is designed to work on MS-DOS and UNIX based"<<endl
    <<"systems only (including Windows, Linux and OS X)."<<endl;
    
    while (true) {
        cout<<"[Y]es or [N]o?"<<endl
        <<">> ";
        std::getline(cin, response);
        if (response[0] == 'y' or response[0] == 'Y') {
            option::clear_screen_enabled = true;
            break;
        } else if (response[0] == 'n' or response[0] == 'N') {
            option::clear_screen_enabled = false;
            break;
        }
    }
    
    {
        do {
            clear_screen();
            if (response == "") {
                add_car(lot);
                clear_screen();
            } else if (response == constant::exit_car) {
                if (lot.size() > 0) {
                    // exit car
                }
                print_lot(lot);
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
                
            } while (response != "" and
                     response != constant::exit_car and
                     response != constant::print_lot and
                     response != constant::quit);
            
        } while (response != constant::quit);
    }
}

void clear_screen() {
    if (option::clear_screen_enabled) {
        if (system("cls")) system("clear");
        print_title(constant::title, 30);
    }
}

void print_title(std::string title, int width, char fill_char, std::ostream& out) {
    using std::setw; using std::endl;
    out<<std::setfill(fill_char)<<std::right
    <<setw(width*2-(int)title.length())<<fill_char<<endl
    <<setw(width)<< title <<setw(width-(int)title.length())<<fill_char<<endl
    <<setw(width*2-(int)title.length())<<fill_char<<endl<<std::setfill(' ');
}

void add_car(std::set<car>& lot) {
    using std::cout; using std::endl; using std::cin; using std::move;
    std::string plate_number;
    std::string description;
    cout<<endl<<endl
    <<"Enter the next car's plate #"<<endl
    <<">> ";
    std::getline(cin, plate_number);
    cout<<endl
    <<"Enter the next car's description"<<endl
    <<">> ";
    std::getline(cin, description);
    
    lot.insert(move(car(move(plate_number), move(description))));
}

void print_lot(std::set<car>& lot) {
    // print lot
}

std::ostream& operator << (std::ostream& out, const car& c) {
    out
    <<"Plate #: "<<c.plate_number<<std::endl
    <<"Description: "<<c.description<<std::endl
    <<"Time in: "<<std::put_time(std::localtime(&c.time_in), "%R %D");
    return out;
}

bool operator <  (const car& lhv, const car& rhv) {
    return lhv.time_in < rhv.time_in;
}
bool operator <= (const car& lhv, const car& rhv) {
    return lhv.time_in <= rhv.time_in;
}
bool operator == (const car& lhv, const car& rhv) {
    return lhv.time_in == rhv.time_in;
}
bool operator >= (const car& lhv, const car& rhv) {
    return lhv.time_in >= rhv.time_in;
}
bool operator >  (const car& lhv, const car& rhv) {
    return lhv.time_in > rhv.time_in;
}
