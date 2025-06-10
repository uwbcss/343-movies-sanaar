#include "history.h"

History::History(int customerId)
    : customerId(customerId) {}

void History::execute(Store* store) {
  store->displayCustomerHistory(customerId);
}
