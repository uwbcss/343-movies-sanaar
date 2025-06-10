#include "customer.h"
#include <iostream>

Customer::Customer(int id, const std::string& name)
    : id(id), name(name) {}

void Customer::addHistory(const std::string& record) {
    history.push_back(record);
}

void Customer::printHistory() const {
    for (const auto& entry : history) {
        std::cout << entry << std::endl;
    }
}

int Customer::getId() const {
    return id;
}

std::string Customer::getName() const {
    return name;
}