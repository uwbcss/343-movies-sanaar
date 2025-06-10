#include "customer.h"
#include <iostream>
using namespace std;

// Constructor
Customer::Customer(int id, const std::string& name) {
    this->id = id;
    this->name = name;
}

// Getters
int Customer::getId() const {
    return id;
    }

std::string Customer::getName() const {
    return name;
}

// Add transaction to history
void Customer::addHistory(const std::string& entry) {
    history.push_back(entry);
}

// Display transaction history
void Customer::printHistory() const {
    if (history.empty()) {
        cout << "No transactions found.\n";
        return;
}

    for (const string& record : history) {
        cout << record << endl;
}
}
