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
    
    Account() = default;
    
    friend ostream& operator << (ostream&, const Account&);
};

ostream& operator << (ostream&, const Account&);

#endif
