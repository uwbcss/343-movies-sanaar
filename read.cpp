#include "read.h"
#include "store.h"
#include "commandfactory.h"
#include "command.h"
#include "comedy.h"
#include "drama.h"
#include "classics.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Read::readMovies(const std::string& filename, Store* store) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Could not open movie file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        char type;
        int stock;
        std::string director, title;
        int year;

        if (!(iss >> type)) continue;
        iss.ignore();  // skip comma

        if (type == 'F') {
            getline(iss, title, ',');
            getline(iss, director, ',');
            iss >> year >> stock;
            store->addMovie(new Comedy(stock, director, title, year));
        } else if (type == 'D') {
            getline(iss, director, ',');
            getline(iss, title, ',');
            iss >> year >> stock;
            store->addMovie(new Drama(stock, director, title, year));
        } else if (type == 'C') {
            std::string actorFirst, actorLast;
            int month;
            getline(iss, director, ',');
            getline(iss, title, ',');
            iss >> actorFirst >> actorLast >> month >> year >> stock;
            store->addMovie(new Classics(stock, director, title, year, month, actorFirst, actorLast));
        }
    }
}

void Read::readCustomers(const std::string& filename, Store* store) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Could not open customer file: " << filename << std::endl;
        return;
    }

    int id;
    std::string firstName, lastName;
    while (file >> id >> firstName >> lastName) {
        store->addCustomer(id, firstName + " " + lastName);
    }
}

void Read::readCommands(const std::string& filename, Store* store, CommandFactory& factory) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Could not open commands file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        Command* command = factory.createCommand(line);
        if (command) {
            store->executeCommand(command);
            delete command;
        }
    }
}