#ifndef CLASSICS_H
#define CLASSICS_H

#include "movie.h"

class Classics : public Movie {
public:
  // Constructor
  Classics(int stock, const std::string &director, const std::string &title,
           int yearOfRelease, int monthOfRelease,
           const std::string &majorActorFirstName,
           const std::string &majorActorLastName);

  // Operator overloads
  bool operator==(const Movie &other) const override;
  bool operator<(const Movie &other) const override;
  bool operator>(const Movie &other) const override;

  std::string getInfo() const override;

};

#endif // CLASSICS_H
