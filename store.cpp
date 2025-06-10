#include "store.h"
#include <iostream>
using namespace std;

// Constructor
Store::Store() {}

// Add movie to inventory
void Store::addMovie(Movie *movie) {
  if (movie != nullptr) {
    inventory.push_back(movie);
  }
}

// Add customer with their ID and name
void Store::addCustomer(int id, const std::string &name) {
  if (!customers.contains(id)) {
    customers.insert(id, new Customer(id, name));
  }
}

// Borrow a movie
bool Store::borrowMovie(Movie *movie, int customerId) {
  if (movie == nullptr) {
    return false;
  }

  Customer *customer = getCustomer(customerId);
  Movie *inventoryMovie = findMovie(*movie);

  if (customer == nullptr || inventoryMovie == nullptr ||
      inventoryMovie->getStock() <= 0) {
    cout << "Borrow failed: invalid movie, customer ID, or out of stock.\n";
    return false;
  }

  inventoryMovie->setStock(inventoryMovie->getStock() - 1);
  customer->addHistory("Borrowed: " + inventoryMovie->getTitle());
  return true;
}

// Return a movie
bool Store::returnMovie(Movie *movie, int customerId) {
  if (movie == nullptr) {
    return false;
  }

  Customer *customer = getCustomer(customerId);
  Movie *inventoryMovie = findMovie(*movie);

  if (customer == nullptr || inventoryMovie == nullptr) {
    cout << "Return failed: invalid movie or customer ID.\n";
    return false;
  }

  inventoryMovie->setStock(inventoryMovie->getStock() + 1);
  customer->addHistory("Returned: " + inventoryMovie->getTitle());
  return true;
}

// Display all movies in inventory
void Store::displayInventory() const {
  cout << "\n--- Store Inventory ---\n";
  for (Movie *m : inventory) {
    cout << "Type: " << m->getMovieType() << ", "
         << "Title: " << m->getTitle() << ", "
         << "Director: " << m->getDirector() << ", "
         << "Year: " << m->getYearOfRelease() << ", "
         << "Stock: " << m->getStock() << "\n";
  }
}

// Display a customer's history
void Store::displayCustomerHistory(int customerId) const {
  Customer *customer = getCustomer(customerId);
  if (customer == nullptr) {
    cout << "Customer ID " << customerId << " not found.\n";
    return;
  }

  cout << "\n--- History for Customer " << customerId << " ---\n";
  customer->printHistory();
}

// Helper to get a customer by ID
Customer *Store::getCustomer(int customerId) const {
  return customers.get(customerId);
}

// Helper to find a movie by comparing with inventory
Movie *Store::findMovie(const Movie &movie) const {
  for (Movie *m : inventory) {
    if (*m == movie) {
      return m;
    }
  }
  return nullptr;
}
