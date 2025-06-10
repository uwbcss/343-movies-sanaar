#include "history.h"
#include "store.h"
#include <iostream>

History::History(int customerId) : customerId(customerId) {}

void History::execute(Store* store) {
    store->displayCustomerHistory(customerId);
}
