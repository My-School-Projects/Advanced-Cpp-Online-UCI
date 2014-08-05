/**
 *  Michael Dorst
 *  Assignment 4
 *  Accounting
 *
 *  account.cpp
 */

#include "account.h"

ostream& operator << (ostream& out, const Account& account) {
    out<<account.name<<": $"<<account.balance;
    return out;
}
