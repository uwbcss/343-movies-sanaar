#include "return.h"

Return::Return(int customerId, Movie *movie)
    : customerId(customerId), movie(movie) {}

void Return::execute(Store *store) {
  // Check customer exists
  Customer *customer = store->getCustomer(customerId);
  if (customer == nullptr) {
    std::cerr << "Return command failed: Customer ID " << customerId << " not found." << std::endl;
    return;
  }

  // Check movie exists in inventory
  Movie *storeMovie = store->getMovie(movie);
  if (storeMovie == nullptr) {
    std::cerr << "Return command failed: Movie not found in inventory: ";
    movie->printShort();
    std::cerr << std::endl;
    return;
  }

  // Proceed with returning logic
  if (!store->returnMovie(customer, storeMovie)) {
    std::cerr << "Return command failed: Customer " << customerId << " did not borrow this movie." << std::endl;
  } else {
    std::cout << "Return successful: Customer " << customerId << " returned movie." << std::endl;
  }
}
