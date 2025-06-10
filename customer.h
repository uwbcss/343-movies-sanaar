#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector> 

class Customer {
public:
    // Constructor
    Customer(int id, const std::string& name);
    
    // Getters
    int getId() const;
    std::string getName() const;
    
    // Add an entry to the customer's transaction history
    void addHistory(const std::string& entry);
    
    // Display the customer's transaction history
    void printHistory() const;
    
private:
    int id;
    std::string name;
    std::vector<std::string> history;
};

#endif // CUSTOMER_H
