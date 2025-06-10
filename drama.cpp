#include "drama.h"

// Constructor
Drama::Drama(int stock, const std::string &director, const std::string &title,
             int yearOfRelease) {
  movieType = 'D'; // Drama
  this->stock = stock;
  this->director = director;
  this->title = title;
  this->yearOfRelease = yearOfRelease;
}

// operator==: compare by director then title
bool Drama::operator==(const Movie &other) const {
  const Drama *temp = dynamic_cast<const Drama *>(&other);
  if (temp == nullptr) {
    return false;
  }

  return (director == temp->director && title == temp->title);
}

// operator<: compare by director then title
bool Drama::operator<(const Movie &other) const {
  const Drama *temp = dynamic_cast<const Drama *>(&other);
  if (temp == nullptr) {
        return false;
    }

  if (director == temp->director) {
    return title < temp->title;
  }

  return director < temp->director;
}

// operator>: compare by director then title
bool Drama::operator>(const Movie &other) const {
  const Drama *temp = dynamic_cast<const Drama *>(&other);
  if (temp == nullptr) {
        return false;
    }

  if (director == temp->director) {
    return title > temp->title;
}

  return director > temp->director;
}

std::string Drama::getInfo() const {
  return "D, " + std::to_string(stock) + ", " + director + ", " + title + ", " + std::to_string(yearOfRelease);
}

