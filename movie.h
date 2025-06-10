#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
public:
    Movie(int stock, std::string director, std::string title, int year);
    virtual ~Movie() = default;

    int getStock() const;
    void setStock(int stock);
    std::string getDirector() const;
    std::string getTitle() const;
    int getYearOfRelease() const;

    virtual char getMovieType() const = 0;
    virtual bool operator==(const Movie& other) const = 0;
    virtual bool operator<(const Movie& other) const = 0;

    virtual std::string getKey() const = 0;
    virtual char getType() const = 0;
    virtual std::string getMovieInfo() const = 0;

protected:
    int stock;
    std::string director;
    std::string title;
    int yearOfRelease;
};

#endif