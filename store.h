#ifndef STORE_H
#define STORE_H
#include "customer.h"
#include "command.h"
#include <vector>
#include <unordered_map>
#include <map>
#include <string>

class Store {
public:
    Store();
    ~Store();
    void addCustomer(Customer* customer);
    void addMovie(Movie* movie);
    void executeCommand(Command* command);
    Customer* getCustomer(int id) const;

private:
    std::map<char, std::vector<Movie*>> inventory;
    HashTable<int, Customer*> customerTable;
};

#endif