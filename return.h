#ifndef RETURN_H
#define RETURN_H

#include "command.h"

class Return : public Command {
public:
    Return(int customerId, Movie* movie);
    void execute(Store* store) override;

private:
  int customerId;
    Movie* movie;
};

#endif // RETURN_H
