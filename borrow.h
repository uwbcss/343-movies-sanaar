#ifndef BORROW_H
#define BORROW_H

#include "command.h"

class Borrow : public Command {
public:
    Borrow(int customerId, Movie* movie);
    void execute(Store* store) override;

private:
    int customerId;
    Movie* movie;
};

#endif // BORROW_H
