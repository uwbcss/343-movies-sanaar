#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

class Movie {
public:
  // Default constructor
  Movie();

  // Copy constructor
  Movie(const Movie &other);
  

  // Virtual destructor
  virtual ~Movie();

  // Getters and setters
  int getStock() const;
  void setStock(int input);

  char getMovieType() const;
  void setMovieType(char type);

  string getDirector() const;
  void setDirector(const string &input);

  string getTitle() const;
  void setTitle(const string &input);

  int getYearOfRelease() const;
  void setYearOfRelease(int input);

  string getMajorActorFirstName() const;
  void setMajorActorFirstName(const string &firstName);

  string getMajorActorLastName() const;
  void setMajorActorLastName(const string &lastName);

  int getMonthOfRelease() const;
  void setMonthOfRelease(int month);

  // Overloadable comparison operators
  virtual bool operator==(const Movie &other) const = 0;
  virtual bool operator<(const Movie &other) const = 0;
  virtual bool operator>(const Movie &other) const = 0;

  bool decreaseStock(); // reduces stock by 1 if available
  void increaseStock(); // increases stock by 1

  virtual string getInfo() const = 0;

protected:
  char movieType; // F = Comedy, D = Drama, C = Classic
  int stock;
  string director;
  string title;
  int yearOfRelease;
  string majorActorFirstName;
  string majorActorLastName;
  int monthOfRelease;
};

#endif // MOVIE_H