/**
 *  Michael Dorst
 *  Assignment 3.2
 *  Function Pointers
 *
 *  io_helper.cpp
 */

#ifndef Function_Pointers__io_helper_h
#define Function_Pointers__io_helper_h

#include <iostream>
#include <ciso646>

using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace constant {
    string quit = "q";
    string new_string = "e";
    string toupper = "c";
    string tolower = "l";
}

template <class T>
T get_input(string prompt, string error_message = "") {
    cout<<prompt<<endl<<">> ";
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
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return data;
}

template <>
string get_input<string>(string prompt, string error_message) {
    string input;
    cout<<endl<<prompt<<endl<<">> ";
    std::getline(cin, input);
    return input;
}

#endif
