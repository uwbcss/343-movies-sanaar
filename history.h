#ifndef HISTORY_H
#define HISTORY_H

#include "command.h"

class History : public Command {
public:
  explicit History(int customerId);
  void execute(Store *store) override;

private:
  int customerId;
};

#endif