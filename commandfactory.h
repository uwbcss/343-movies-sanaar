#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "command.h"
#include "store.h"

class CommandFactory {
public:
  // Constructor with a reference to the store
  explicit CommandFactory(Store *store);

  // Builds a command from a single line of input
  static Command *createCommand(const std::string &commandLine);

private:
  Store *store;
};

#endif // COMMANDFACTORY_H
