#include "return.h"
#include "store.h"
#include <iostream>

Return::Return(int customerId, Movie* movie) : customerId(customerId), movie(movie) {}

void Return::execute(Store* store) {
    if (!store->returnMovie(movie, customerId)) {
        std::cerr << "Return command failed for customer " << customerId << std::endl;
    }
}

Return::~Return() {
    delete movie;
}