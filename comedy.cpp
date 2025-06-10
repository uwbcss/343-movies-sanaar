#include "comedy.h"

Comedy::Comedy(int stock, std::string director, std::string title, int year)
    : Movie(stock, director, title, year) {}

char Comedy::getMovieType() const { return 'F'; }

char Comedy::getType() const { return 'F'; }

std::string Comedy::getKey() const {
  return getTitle() + std::to_string(getYearOfRelease());
}

std::string Comedy::getMovieInfo() const {
  return getTitle() + ", " + getDirector() + ", " +
         std::to_string(getYearOfRelease());
}

bool Comedy::operator==(const Movie &other) const {
  const Comedy *rhs = dynamic_cast<const Comedy *>(&other);
  return rhs && getTitle() == rhs->getTitle() &&
         getYearOfRelease() == rhs->getYearOfRelease();
}

bool Comedy::operator<(const Movie &other) const {
  const Comedy *rhs = dynamic_cast<const Comedy *>(&other);
  if (rhs == nullptr) {
    return false;
  }
  if (getTitle() != rhs->getTitle()) {
    return getTitle() < rhs->getTitle();
  }
  return getYearOfRelease() < rhs->getYearOfRelease();
}