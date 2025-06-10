#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie {
public:
  Comedy(int stock, const std::string &director, const std::string &title,
         int yearOfRelease);

  // Operator overloads
  bool operator==(const Movie &other) const override;
  bool operator<(const Movie &other) const override;
  bool operator>(const Movie &other) const override;

  std::string getInfo() const override;

};

#endif // COMEDY_H
