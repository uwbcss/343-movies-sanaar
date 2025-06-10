#include "drama.h"

Drama::Drama(int stock, std::string director, std::string title, int year)
    : Movie(stock, director, title, year) {}

char Drama::getMovieType() const { return 'D'; }

char Drama::getType() const { return 'D'; }

std::string Drama::getKey() const { return getDirector() + getTitle(); }

std::string Drama::getMovieInfo() const {
  return getTitle() + ", " + getDirector() + ", " +
         std::to_string(getYearOfRelease());
}

bool Drama::operator==(const Movie &other) const {
  const Drama *rhs = dynamic_cast<const Drama *>(&other);
  return rhs && getDirector() == rhs->getDirector() &&
         getTitle() == rhs->getTitle();
}

bool Drama::operator<(const Movie &other) const {
  const Drama *rhs = dynamic_cast<const Drama *>(&other);
  if (rhs == nullptr) {
    return false;
  }
  if (getDirector() != rhs->getDirector()) {
    return getDirector() < rhs->getDirector();
  }
  return getTitle() < rhs->getTitle();
}