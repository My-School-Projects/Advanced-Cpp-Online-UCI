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

void clear_screen();
void print_title(std::string title, int width, char = '*');
void add_car(lot_t&);
void exit_car(lot_t&);
enum sort {
    by_inv_num, by_date, ask
};
void print_lot(const lot_t&, sort = ask);

namespace option {
    bool clear_screen_enabled;
}

namespace constant {
    std::string title = " Welcome to the Used Car Dealership ";
    std::string exit_car = "x";
    std::string print_lot = "r";
    std::string quit = "q";
    std::string by_inv_num = "i";
    std::string by_date = "d";
}

int main() {
    using std::cout; using std::endl; using std::cin;
    
    lot_t lot;
    
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
    clear_screen();
    
    do {
        if (response == "") {
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
    using std::cin; using std::cout; using std::endl; using std::move;
    std::string plate_number;
    std::string description;
    date_t date;
    
    cout<<endl<<endl
    <<"Enter the car's licence plate #"<<endl
    <<">> ";
    std::getline(cin, plate_number);
    cout<<endl
    <<"Enter the car's description"<<endl
    <<">> ";
    std::getline(cin, description);
    cout<<endl
    <<"Enter the date the car was bought (mm/dd/yyyy)"<<endl
    <<">> ";
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Please enter a date in the format (mm/dd/yyyy)"<<endl
            <<">>";
        }
        cin>>date;
    } while (cin.fail());
    
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
    using std::endl;
    std::string response;
    if (sort == ask) {
        do {
            std::cout<<endl
            <<"Type '"<<constant::by_inv_num
            <<"' to view cars sorted by inventory number"<<endl
            <<"Type '"<<constant::by_date
            <<"' to view cars sorted by date"<<endl
            <<">> ";
            std::getline(std::cin, response);
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
            std::cout<<endl<<*i;
        }
    } else {
        for (auto i = lot.cbegin_by_inv_num(); i != lot.cend_by_inv_num(); i++) {
            std::cout<<endl<<*i;
        }
    }
}

void exit_car(lot_t& lot) {
    using std::cout; using std::cin; using std::endl;
    std::string response;
    do {
        std::cout<<endl
        <<"Type '"<<constant::by_inv_num
        <<"' to select car by inventory number"<<endl
        <<"Type '"<<constant::by_date
        <<"' to select car by date"<<endl
        <<">> ";
        std::getline(std::cin, response);
        clear_screen();
    } while (response != constant::by_date and
             response != constant::by_inv_num);
    clear_screen();
    if (response == constant::by_date) {
        print_lot(lot, by_date);
    } else {
        print_lot(lot, by_inv_num);
    }
    if (response == constant::by_date) {
        cout<<endl
        <<"Enter the date the car was bought (mm/dd/yyyy)"<<endl
        <<">> ";
        do {
            date_t date;
            do {
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout<<"Please enter a date in the format (mm/dd/yyyy)"<<endl
                    <<">>";
                }
                cin>>date;
            } while (cin.fail());
            auto it = lot.find_by_date(date);
            if (it == lot.end_by_date()) {
                cout<<"No car was found for the date "<<date<<"."<<endl;
                continue;
            } else {
                cout<<"The exiting car:"<<endl<<*it<<endl;
                lot.erase(it);
            }
        } while (true);
    } else {
        cout<<endl
        <<"Enter the the inventory number for the car"<<endl
        <<">> ";
        do {
            car_t::inv_num_t inv_num;
            do {
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout<<"Please enter a valid inventory number"<<endl
                    <<">>";
                }
                cin>>inv_num;
            } while (cin.fail());
            auto it = lot.find_by_inv_num(inv_num);
            if (it == lot.end_by_inv_num()) {
                continue;
            } else {
                cout<<"The exiting car:"<<endl<<*it<<endl;
                lot.erase(it);
            }
        } while (true);
    }
}

void clear_screen() {
    if (option::clear_screen_enabled) {
        if (system("cls")) system("clear");
        print_title(constant::title, 40);
    }
}

void print_title(std::string title, int width, char fill_char) {
    using std::cout;
    using std::setw; using std::endl;
    cout<<std::setfill(fill_char)<<std::right
    <<setw(width*2-(int)title.length())<<fill_char<<endl
    <<setw(width)<< title <<setw(width-(int)title.length())<<fill_char<<endl
    <<setw(width*2-(int)title.length())<<fill_char<<endl<<std::setfill(' ');
}
