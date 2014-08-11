/**
 *  Michael Dorst
 *  Assignment 3.2
 *  Function Pointers
 *
 *  main.cpp
 */

#include "io_helper.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include <map>
#include <cctype>
#include <ciso646>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::function;
using std::transform;
using std::map;

void apply(function<void(string&)>, string&);

int main() {
    
    map<string, function<void(string&)>> mutator =
    {
        {constant::new_string,
            [](string& str) {
                str = get_input<string>("Enter a string:");
            }
        },
        {constant::toupper,
            [](string& str) {
                transform(str.begin(), str.end(), str.begin(),
                          [](char& c) {
                              return std::toupper(c);
                          });
            }
        },
        {constant::tolower,
            [](string& str) {
                transform(str.begin(), str.end(), str.begin(),
                          [](char& c) {
                              return std::tolower(c);
                          });
            }
        }
    };
    
    string response;
    string str;
    
    do {
        do {
            response = get_input<string>
            ("[Q]uit, [E]nter a string, [C]apitalize, [L]ower case");
        } while (response != constant::quit and
                 response != constant::new_string and
                 response != constant::toupper and
                 response != constant::tolower);
        
        if (response != constant::quit) {
            cout << "Before mutation:" << endl << str << endl;
            apply(mutator[response], str);
            cout << "After mutation:" << endl << str << endl;
        }
        
    } while (response != constant::quit);
}

void enter_string(string& str) {
    str = get_input<string>
    ("Enter string:");
}

void apply(function<void(string&)> func, string& str) {
    func(str);
}
