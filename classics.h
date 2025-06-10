#ifndef CLASSICS_H
#define CLASSICS_H

#include "movie.h"

class Classics : public Movie {
public:
    Classics(int stock, std::string director, std::string title,
             int year, int month, std::string actorFirst, std::string actorLast);

    std::string getMajorActor() const;
    int getMonth() const;

    bool operator==(const Movie &other) const override;
    bool operator<(const Movie &other) const override;

    char getMovieType() const override;
    char getType() const override;
    std::string getKey() const override;
    std::string getMovieInfo() const override;

private:
    std::string majorActorFirst;
    std::string majorActorLast;
    int releaseMonth;
};

#endif