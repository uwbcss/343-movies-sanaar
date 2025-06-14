#ifndef STORE_H
#define STORE_H

#include "command.h"
#include "customer.h"
#include "hashtable.h"
#include "movie.h"
#include <string>
#include <vector>

class Store {
public:
  Store();
  ~Store() = default;

  void addCustomer(int id, const std::string &name);
  void addMovie(Movie *movie);
  bool borrowMovie(Movie *movie, int customerId);
  bool returnMovie(Movie *movie, int customerId);
  void displayInventory() const;
  void displayCustomerHistory(int customerId) const;
  void executeCommand(Command *command);
  Customer *getCustomer(int id) const;

private:
  std::vector<Movie *> inventory;
  HashTable<int, Customer *> customers;

  Movie *findMovie(const Movie &movie) const;
};

#endif