#include "classics.h"

// Constructor
Classics::Classics(int stock, const std::string &director,
                   const std::string &title, int yearOfRelease,
                   int monthOfRelease, const std::string &majorActorFirstName,
                   const std::string &majorActorLastName) {
  movieType = 'C'; // Classic
  this->stock = stock;
  this->director = director;
  this->title = title;
  this->yearOfRelease = yearOfRelease;
  this->monthOfRelease = monthOfRelease;
  this->majorActorFirstName = majorActorFirstName;
  this->majorActorLastName = majorActorLastName;
}

// operator==
bool Classics::operator==(const Movie &other) const {
  const Classics *temp = dynamic_cast<const Classics *>(&other);
  if (temp == nullptr) {
        return false;
    }

  bool sameDate = (yearOfRelease == temp->yearOfRelease &&
                   monthOfRelease == temp->monthOfRelease);
  bool sameActor = (majorActorFirstName == temp->majorActorFirstName &&
                    majorActorLastName == temp->majorActorLastName);
  return sameDate && sameActor;
}

// operator<
bool Classics::operator<(const Movie &other) const {
  const Classics *temp = dynamic_cast<const Classics *>(&other);
  if (temp == nullptr) {
        return false;
    }

  if (yearOfRelease == temp->yearOfRelease) {
    if (monthOfRelease == temp->monthOfRelease) {
      return (majorActorFirstName + majorActorLastName) <
             (temp->majorActorFirstName + temp->majorActorLastName);
    }
    return monthOfRelease < temp->monthOfRelease;
  }
  return yearOfRelease < temp->yearOfRelease;
}

// operator>
bool Classics::operator>(const Movie &other) const {
  const Classics *temp = dynamic_cast<const Classics *>(&other);
  if (temp == nullptr) {
    return false;
  }

  if (yearOfRelease == temp->yearOfRelease) {
    if (monthOfRelease == temp->monthOfRelease) {
      return (majorActorFirstName + majorActorLastName) >
             (temp->majorActorFirstName + temp->majorActorLastName);
}
    return monthOfRelease > temp->monthOfRelease;
  }
  return yearOfRelease > temp->yearOfRelease;
}

std::string Classics::getInfo() const {
  return "C, " + std::to_string(stock) + ", " + director + ", " + title + ", " +
         std::to_string(monthOfRelease) + " " + std::to_string(yearOfRelease) + ", " +
         majorActorFirstName + " " + majorActorLastName;
}
