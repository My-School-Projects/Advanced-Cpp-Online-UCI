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

namespace option {
    bool clear_screen_enabled;
}

namespace constant {
    std::string title = " Welcome to the Used Car Dealership ";
    std::string exit_car = "x";
    std::string print_lot = "r";
    std::string quit = "q";
}

int main() {
    using std::cout; using std::endl; using std::cin;
    
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
            // add car
            clear_screen();
        } else if (response == constant::exit_car) {
            // print lot
            do {
                response = std::string();
                cout<<endl
                <<"Enter the plate number of the exiting car"<<endl
                <<">> ";
                std::getline(cin, response);
                // find car
            } while (false /* car not found */);
            clear_screen();

            // print information about exiting car
            // delete exiting car
            
        } else if (response == constant::print_lot) {
            // print lot
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
