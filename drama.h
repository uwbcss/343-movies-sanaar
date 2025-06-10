#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

class Drama : public Movie {
public:
    Drama(int stock, std::string director, std::string title, int year);

    bool operator==(const Movie& other) const override;
    bool operator<(const Movie& other) const override;

    char getMovieType() const override;
    /// @brief 
    /// @return 
    char getType() const override;
    std::string getKey() const override;
    std::string getMovieInfo() const override;
};

#endif