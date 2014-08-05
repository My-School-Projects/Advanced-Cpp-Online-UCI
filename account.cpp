/**
 *  Michael Dorst
 *  Assignment 4
 *  Accounting
 *
 *  account.cpp
 */

#include "account.h"

Account::Account(const string& n, double b) : name(n), balance(b) {}

Account Account::operator + (const Account& that)const {
    return Account(this->name + " & " + that.name, this->balance+that.balance);
}

ostream& operator << (ostream& out, const Account& account) {
    out<<account.name<<": $"<<account.balance;
    return out;
}

bool operator < (const Account& lhv, const Account& rhv) {
    return lhv.balance < rhv.balance;
}
