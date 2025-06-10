#include "inventory.h"
#include "store.h"

void Inventory::execute(Store* store) {
    store->displayInventory();
}
