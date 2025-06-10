#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie {
public:
    Comedy(int stock, std::string director, std::string title, int year);

    bool operator==(const Movie &other) const override;
    bool operator<(const Movie &other) const override;

    char getMovieType() const override;
    char getType() const override;
    std::string getKey() const override;
    std::string getMovieInfo() const override;
};

#endif