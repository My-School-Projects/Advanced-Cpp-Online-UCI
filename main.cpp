/**
 *  Michael Dorst
 *  Assignment 4
 *  Accounting
 *
 *  main.cpp
 */

#include "account.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <ciso646>
using std::vector;
using std::string;
using std::to_string;
using std::cout;
using std::endl;

vector<Account> generateAccounts(size_t, string);

int main() {
    
    auto v = generateAccounts(5, "Client A");
    for (auto i : v) {
        cout<<i<<endl;
    }
    
}

vector<Account> generateAccounts(size_t n, string baseName) {
    vector<Account> vec;
    vec.reserve(n);
    for (size_t i = 1; i <= n; i++) {
        vec.push_back(Account(baseName+to_string(i), arc4random() % 1000));
    }
    return vec;
}
