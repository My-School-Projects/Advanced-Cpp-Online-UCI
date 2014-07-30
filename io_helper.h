/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  io_helper.cpp
 */

#ifndef Used_Car_Dealership__io_helper_h
#define Used_Car_Dealership__io_helper_h

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

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

template <class T>
T get_input(string prompt, string error_message = "") {
    cout<<endl<<prompt<<endl<<">> ";
    T data;
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<error_message<<endl
            <<">>";
        }
        cin>>data;
    } while (cin.fail());
    return data;
}

template <>
string get_input<string>(string prompt, string error_message) {
    string input;
    cout<<endl<<prompt<<endl<<">> ";
    std::getline(cin, input);
    return input;
}

void prompt_clear_screen() {
    string response;
    
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
}

#endif
