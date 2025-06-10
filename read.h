#ifndef READ_H
#define READ_H

#include "store.h"
#include <string>

// Parses all input files and populates the store
void loadStoreData(Store &store, const std::string &customersFile,
                   const std::string &moviesFile, const std::string &commandsFile);

#endif // READ_H
