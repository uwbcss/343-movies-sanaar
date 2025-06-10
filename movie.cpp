#include "movie.h"

Movie::Movie(int stock, std::string director, std::string title, int year)
    : stock(stock), director(director), title(title), yearOfRelease(year) {}

int Movie::getStock() const {
    return stock;
}

void Movie::setStock(int s) {
    stock = s;
}

std::string Movie::getDirector() const {
    return director;
}

std::string Movie::getTitle() const {
    return title;
}

int Movie::getYearOfRelease() const {
    return yearOfRelease;
}