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
using std::ostream;
using std::string;

class Account {
public:
    
    string name;
    double balance;
    
    friend ostream& operator << (ostream&, const Account&);
};

ostream& operator << (ostream&, const Account&);

#endif
