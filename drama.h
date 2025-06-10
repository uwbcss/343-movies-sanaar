#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

class Drama : public Movie {
public:
  // Constructor
  Drama(int stock, const std::string &director, const std::string &title,
        int yearOfRelease);

  // Operator overloads
  bool operator==(const Movie &other) const override;
  bool operator<(const Movie &other) const override;
  bool operator>(const Movie &other) const override;

  std::string getInfo() const override;

};

#endif // DRAMA_H
