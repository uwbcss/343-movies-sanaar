#ifndef COMMAND_H
#define COMMAND_H

class Store;

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(Store* store) = 0;
};

#endif