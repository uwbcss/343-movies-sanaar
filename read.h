#ifndef READ_H
#define READ_H

#include <string>

class Store;
class CommandFactory;

namespace Read {
    void readMovies(const std::string& filename, Store* store);
    void readCustomers(const std::string& filename, Store* store);
    void readCommands(const std::string& filename, Store* store, CommandFactory& factory);
}

#endif