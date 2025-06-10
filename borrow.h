#ifndef BORROW_H
#define BORROW_H

#include "command.h"
#include "movie.h"

class Borrow : public Command {
public:
    Borrow(int customerId, Movie* movie);
    void execute(Store* store) override;
    ~Borrow();

private:
    int customerId;
    Movie* movie;
};

#endif