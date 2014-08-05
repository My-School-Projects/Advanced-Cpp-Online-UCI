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
#include <queue>
#include <algorithm>
#include <ciso646>
using std::vector;
using std::transform;
using std::priority_queue;
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
    
    transform(a.begin(), a.end(), b.begin(), b.end(),
                   [](const Account& lhv, const Account& rhv) {
                       return lhv + rhv;
                   });
    cout << "4.1 (Transform)" << endl << endl;
    for (size_t i = 0; i < size; i++) {
        cout << a[i] << " + " << b[i] << " = " << a_plus_b[i] << endl;
    }
    
    cout << endl << "4.2 (Priority Queue)" << endl << endl;
    cout << "Unsorted:" << endl;
    for (size_t i = 0; i < size; i++) {
        cout << a_plus_b[i] << endl;
    }
    
    priority_queue<Account> sorted(std::less<Account>(), a_plus_b);
    
    cout << endl << "Sorted:" << endl;
    while (sorted.size() > 0) {
        cout << sorted.top() << endl;
        sorted.pop();
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
