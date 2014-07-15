/**
 *  Michael Dorst
 *  Assignment 1
 *  Car Wash
 *
 *  main.cpp
 */

#include "car.h"
#include <iostream>
#include <iomanip>
#include <deque>

void clear_screen();
void print_title(std::string title, int width, char = '*', std::ostream& = std::cout);

int main() {
    
    std::deque<car> que;
    
//    clear_screen();
    
    print_title(" Michael's Car Wash ", 25);
    
    
    
    return 0;
}

void clear_screen() {
    if (system("cls")) system("clear");
}

void print_title(std::string title, int width, char fill_char, std::ostream& out) {
    using std::setfill; using std::setw; using std::endl;
    out<<setfill(fill_char)
    <<setw(width*2-(int)title.length())<<fill_char<<endl
    <<setw(width)<< title <<setw(width-(int)title.length())<<fill_char<<endl
    <<setw(width*2-(int)title.length())<<fill_char<<endl;
}
