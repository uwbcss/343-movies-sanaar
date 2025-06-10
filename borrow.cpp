#include "borrow.h"
#include "store.h"
#include <iostream>

Borrow::Borrow(int customerId, Movie* movie) : customerId(customerId), movie(movie) {}

void Borrow::execute(Store* store) {
    if (!store->borrowMovie(movie, customerId)) {
        std::cerr << "Borrow command failed for customer " << customerId << std::endl;
    }
}

Borrow::~Borrow() {
    delete movie;
}