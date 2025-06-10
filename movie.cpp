#include "movie.h"
using namespace std;

// Default constructor
Movie::Movie() {
  movieType = ' ';
  stock = 0;
  director = "";
  title = "";
  yearOfRelease = 0;
  majorActorFirstName = "";
  majorActorLastName = "";
  monthOfRelease = 0;
}

// Copy constructor
Movie::Movie(const Movie &other) {
  movieType = other.movieType;
  stock = other.stock;
  director = other.director;
  title = other.title;
  yearOfRelease = other.yearOfRelease;
  majorActorFirstName = other.majorActorFirstName;
  majorActorLastName = other.majorActorLastName;
  monthOfRelease = other.monthOfRelease;
}

// Virtual destructor
Movie::~Movie() {}

// Getters and setters
int Movie::getStock() const { return stock; }

void Movie::setStock(int input) { stock = input; }

char Movie::getMovieType() const { return movieType; }

void Movie::setMovieType(char type) { movieType = type; }

string Movie::getDirector() const { return director; }

void Movie::setDirector(const string &input) { director = input; }

string Movie::getTitle() const { return title; }

void Movie::setTitle(const string &input) { title = input; }

int Movie::getYearOfRelease() const { return yearOfRelease; }

void Movie::setYearOfRelease(int input) { yearOfRelease = input; }

string Movie::getMajorActorFirstName() const { return majorActorFirstName; }

void Movie::setMajorActorFirstName(const string &name) {
  majorActorFirstName = name;
}

string Movie::getMajorActorLastName() const { return majorActorLastName; }

void Movie::setMajorActorLastName(const string &name) {
  majorActorLastName = name;
}

int Movie::getMonthOfRelease() const { return monthOfRelease; }

void Movie::setMonthOfRelease(int month) { monthOfRelease = month; }

// Decrease stock by 1 if stock > 0, return true if successful
bool Movie::decreaseStock() {
  if (stock > 0) {
    stock--;
    return true;
  }
  return false;
}

// Increase stock by 1
void Movie::increaseStock() { stock++; }
