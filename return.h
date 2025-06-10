#ifndef RETURN_H
#define RETURN_H

#include "command.h"
#include "movie.h"

class Return : public Command {
public:
    Return(int customerId, Movie* movie);
    void execute(Store* store) override;
    ~Return();

private:
    int customerId;
    Movie* movie;
};

#endif