#include "classics.h"

Classics::Classics(int stock, std::string director, std::string title,
                   int year, int month, std::string actorFirst, std::string actorLast)
    : Movie(stock, director, title, year),
      majorActorFirst(actorFirst), majorActorLast(actorLast), releaseMonth(month) {}

std::string Classics::getMajorActor() const {
    return majorActorFirst + " " + majorActorLast;
}

int Classics::getMonth() const {
    return releaseMonth;
}

char Classics::getMovieType() const {
    return 'C';
}

char Classics::getType() const {
    return 'C';
}

std::string Classics::getKey() const {
    return std::to_string(getYearOfRelease()) +
           std::to_string(getMonth()) + getMajorActor();
}

std::string Classics::getMovieInfo() const {
    return getTitle() + ", " + getDirector() + ", " +
           getMajorActor() + ", " + std::to_string(getMonth()) +
           "/" + std::to_string(getYearOfRelease());
}

bool Classics::operator==(const Movie &other) const {
    const Classics* rhs = dynamic_cast<const Classics*>(&other);
    if (!rhs) return false;
    return getTitle() == rhs->getTitle() &&
           getDirector() == rhs->getDirector() &&
           getYearOfRelease() == rhs->getYearOfRelease() &&
           releaseMonth == rhs->releaseMonth &&
           majorActorFirst == rhs->majorActorFirst &&
           majorActorLast == rhs->majorActorLast;
}

bool Classics::operator<(const Movie &other) const {
    const Classics* rhs = dynamic_cast<const Classics*>(&other);
    if (!rhs) return false;
    if (getYearOfRelease() != rhs->getYearOfRelease())
        return getYearOfRelease() < rhs->getYearOfRelease();
    if (releaseMonth != rhs->releaseMonth)
        return releaseMonth < rhs->releaseMonth;
    return getMajorActor() < rhs->getMajorActor();
}