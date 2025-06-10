#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

class Customer {
public:
  Customer(int id, const std::string &name);
  void addHistory(const std::string &record);
  void printHistory() const;

  int getId() const;
  std::string getName() const;

private:
  int id;
  std::string name;
  std::vector<std::string> history;
};

#endif