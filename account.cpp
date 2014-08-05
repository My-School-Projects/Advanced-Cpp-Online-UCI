/**
 *  Michael Dorst
 *  Assignment 4
 *  Accounting
 *
 *  account.cpp
 */

#include "account.h"

Account::Account(const string& n, double b) : name(n), balance(b) {}

ostream& operator << (ostream& out, const Account& account) {
    out<<account.name<<": $"<<account.balance;
    return out;
}
