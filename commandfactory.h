#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "command.h"
#include "store.h"
#include <string>

class CommandFactory {
public:
    explicit CommandFactory(Store *store);
    Command *createCommand(const std::string &commandLine);

private:
    Store *store;
};

#endif // COMMANDFACTORY_H