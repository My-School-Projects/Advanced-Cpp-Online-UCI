/**
 *  Michael Dorst
 *  Assignment 4
 *  Accounting
 *
 *  account.h
 */

#ifndef Accounting__account_h
#define Accounting__account_h

#include <ostream>
#include <ciso646>
using std::ostream;
using std::string;

class Account {
public:
    
    string name;
    double balance;
    
    Account(const string& = "", double = 0);
    
    Account operator + (const Account&)const;
    
    friend ostream& operator << (ostream&, const Account&);
};

ostream& operator << (ostream&, const Account&);

bool operator < (const Account&, const Account&);

#endif
