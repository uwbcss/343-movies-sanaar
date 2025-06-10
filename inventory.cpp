#include "inventory.h"

Inventory::Inventory() {}

void Inventory::execute(Store* store) {
    store->displayInventory();
} 
