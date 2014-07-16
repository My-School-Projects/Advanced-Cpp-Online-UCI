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
void add_car(std::deque<car>&);

int main() {
    using std::cout; using std::endl; using std::cin;
    std::deque<car> que;
    
//    clear_screen();
    
    print_title(" Welcome to the Car Wash ", 30);
    
    {
        std::string response;
        do {
            if (response == "") {
                add_car(que);
            } else if (response == "report") {
                
            } else if (response == "finish") {
                
            } else if (response == "exit") {
                return 0;
            }
            
            do {
                cout<<endl
                <<"Press [return] to enter a new car..."<<endl
                <<"Type 'finish' to get rid of the front car"<<endl
                <<"Type 'report' to view all the cars in the que"<<endl
                <<"Type 'exit' to stop the program"<<endl
                <<">> ";
                std::getline(cin, response);
                
            } while (response != "finish" and
                     response != "report" and
                     response != "exit" and
                     response.length() > 0);
            
        } while (response != "exit");
    }
}

void clear_screen() {
    if (system("cls")) system("clear");
}

void print_title(std::string title, int width, char fill_char, std::ostream& out) {
    using std::setw; using std::endl;
    out<<std::setfill(fill_char)
    <<setw(width*2-(int)title.length())<<fill_char<<endl
    <<setw(width)<< title <<setw(width-(int)title.length())<<fill_char<<endl
    <<setw(width*2-(int)title.length())<<fill_char<<endl;
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
    que.push_back(car(std::move(description), amount_paid));
}
