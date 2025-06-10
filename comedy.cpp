#include "comedy.h"

// Constructor
Comedy::Comedy(int stock, const std::string &director, const std::string &title, int yearOfRelease)
  : Movie(stock, director, title, yearOfRelease) {
  movieType = 'F';
}

// Equality operator
bool Comedy::operator==(const Movie &other) const {
  const Comedy *temp = dynamic_cast<const Comedy *>(&other);
  if (temp == nullptr) {
        return false;
    }

  return (title == temp->title && yearOfRelease == temp->yearOfRelease);
}

// Less-than operator
bool Comedy::operator<(const Movie &other) const {
  const Comedy *temp = dynamic_cast<const Comedy *>(&other);
  if (temp == nullptr) {
        return false;
    }

  if (title == temp->title) {
    return yearOfRelease < temp->yearOfRelease;
  }

  return title < temp->title;
}

// Greater-than operator
bool Comedy::operator>(const Movie &other) const {
  const Comedy *temp = dynamic_cast<const Comedy *>(&other);
  if (temp == nullptr) {
    return false;
  }

  if (title == temp->title) {
    return yearOfRelease > temp->yearOfRelease;
}

  return title > temp->title;
}

std::string Comedy::getInfo() const {
  return "F, " + std::to_string(stock) + ", " + director + ", " + title + ", " +
         std::to_string(yearOfRelease);
}