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
#include <algorithm>
#include <ciso646>
using std::vector;
using std::string;
using std::to_string;
using std::cout;
using std::endl;

vector<Account> generateAccounts(size_t, string);

int main() {
    
    size_t size = 5;
    
    auto a = generateAccounts(size, "Client A");
    auto b = generateAccounts(size, "Client B");
    
    vector<Account> a_plus_b(size);
    
    std::transform(a.begin(), a.end(), b.begin(), b.end(),
                   [](const Account& lhv, const Account& rhv) {
                       return lhv + rhv;
                   });
    for (size_t i = 0; i < size; i++) {
        cout<< a[i] << " + " << b[i] << " = " << a_plus_b[i] << endl;
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
