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
#include <deque>

void clear_screen();
void print_title(std::string title, int width, char = '*', std::ostream& = std::cout);
void add_car(std::deque<car>&);
void print_que(std::deque<car>&);

namespace option {
    bool clear_screen_enabled;
}

namespace constant {
    std::string title = " Welcome to the Parking Lot ";
    std::string pop_front = "wash";
    std::string print_que = "report";
    std::string exit = "exit";
}

int main() {
    using std::cout; using std::endl; using std::cin;
    std::deque<car> que;
    
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
                add_car(que);
                clear_screen();
            } else if (response == constant::pop_front) {
                if (que.size() > 0) {
                    que.pop_front();
                }
                print_que(que);
            } else if (response == constant::print_que) {
                print_que(que);
            } else if (response == constant::exit) {
                return 0;
            }
            
            do {
                cout<<endl
                <<"Press [return] to enter a new car..."<<endl
                <<"Type '"<<constant::pop_front<<"' to wash the front car"<<endl
                <<"Type '"<<constant::print_que<<"' to view all the cars in the que"<<endl
                <<"Type '"<<constant::exit<<"' to stop the program"<<endl
                <<">> ";
                std::getline(cin, response);
                
            } while (response != "" and
                     response != constant::pop_front and
                     response != constant::print_que and
                     response != constant::exit);
            
        } while (response != constant::exit);
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

void add_car(std::deque<car>& que) {
    using std::cout; using std::endl; using std::cin;
    std::string description;
    double amount_paid;
    cout<<endl<<endl
    <<"Enter the next car's description (plate #, model, color...)"<<endl
    <<">> ";
    std::getline(cin, description);
    cout<<endl
    <<"Enter the amount paid"<<endl
    <<">> ";
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Please enter a number"<<endl
            <<">>";
        }
        cin>>amount_paid;
    } while (cin.fail());
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
}

void print_que(std::deque<car>& que) {
    for (size_t i = 0; i < que.size(); i++) {
        std::cout<<que[i]<<std::endl;
    }
}

std::ostream& operator << (std::ostream& out, car& c) {
    out
    <<"Plate #: "<<c.plate_number<<std::endl
    <<"Description: "<<c.description<<std::endl
    <<"Time in: "<<std::put_time(std::localtime(&c.time_in), "%R %D");
    return out;
}
