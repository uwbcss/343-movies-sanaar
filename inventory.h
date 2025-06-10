#ifndef INVENTORY_H
#define INVENTORY_H

#include "command.h"

class Inventory : public Command {
public:
    Inventory() = default;
    void execute(Store* store) override;
};

#endif