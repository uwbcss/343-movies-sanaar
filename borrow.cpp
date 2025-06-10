#include <iostream>
#include "borrow.h"
#include "store.h"
#include "customer.h"
#include "movie.h"

Borrow::Borrow(int customerId, Movie *movie)
    : customerId(customerId), movie(movie) {}

void Borrow::execute(Store *store) {
  // Check customer exists
  Customer *customer = store->getCustomer(customerId);
  if (customer == nullptr) {
    std::cerr << "Borrow command failed: Customer ID " << customerId << " not found." << std::endl;
    return;  // safely exit without throwing
  }

  // Check movie exists in inventory
  Movie *storeMovie = store->getMovie(movie);
  if (storeMovie == nullptr) {
    std::cerr << "Borrow command failed: Movie not found in inventory: ";
    movie->printShort();  // or print title/identifier however you do
    std::cerr << std::endl;
    return;
  }

  // Proceed with borrowing logic
  if (!store->borrowMovie(customer, storeMovie)) {
    std::cerr << "Borrow command failed: Could not borrow movie (maybe out of stock)." << std::endl;
        } else {
    std::cout << "Borrow successful: Customer " << customerId << " borrowed movie." << std::endl;
        }
}
