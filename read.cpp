#include "read.h"
#include "classics.h"
#include "comedy.h"
#include "command.h"
#include "commandfactory.h"
#include "drama.h"
#include "store.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Read::readMovies(const std::string &filename, Store *store) {
  std::ifstream file(filename);
  if (!file) {
    std::cerr << "Could not open movie file: " << filename << std::endl;
    return;
  }

  std::string line;
  while (getline(file, line)) {
    if (line.empty()) {
      continue;
    }

    std::istringstream iss(line);
    char type;
    iss >> type;
    iss.ignore(); // skip comma and space

    if (type == 'F') {
      // F, stock, director, title, year
      std::string stockStr
      std::string director
      std::string title
      std::string yearStr;
      getline(iss, stockStr, ',');
      getline(iss, director, ',');
      getline(iss, title, ',');
      getline(iss, yearStr);

      try {
        int stock = std::stoi(stockStr);
        int year = std::stoi(yearStr);
        store->addMovie(new Comedy(stock, director, title, year));
      } catch (...) {
        std::cerr << "Invalid Comedy movie format: " << line << std::endl;
      }

    } else if (type == 'D') {
      // D, stock, director, title, year
      std::string stockStr;
      std::string director;
      std::string title;
      std::string yearStr;
      getline(iss, stockStr, ',');
      getline(iss, director, ',');
      getline(iss, title, ',');
      getline(iss, yearStr);

      try {
        int stock = std::stoi(stockStr);
        int year = std::stoi(yearStr);
        store->addMovie(new Drama(stock, director, title, year));
      } catch (...) {
        std::cerr << "Invalid Drama movie format: " << line << std::endl;
      }

    } else if (type == 'C') {
      // C, stock, director, title, actorFirst actorLast month year
      std::string stockStr;
      std::string director;
      std::string title;
      std::string actorFirst;
      std::string actorLast;
      int month;
      int year;

      getline(iss, stockStr, ',');
      getline(iss, director, ',');
      getline(iss, title, ',');

      iss >> actorFirst >> actorLast >> month >> year;

      try {
        int stock = std::stoi(stockStr);
        store->addMovie(new Classics(stock, director, title, year, month,
                                     actorFirst, actorLast));
      } catch (...) {
        std::cerr << "Invalid Classics movie format: " << line << std::endl;
      }

    } else {
      std::cerr << "Unknown movie type: " << type
                << ", discarding line: " << line << std::endl;
    }
  }
}

void Read::readCustomers(const std::string &filename, Store *store) {
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

void Read::readCommands(const std::string &filename, Store *store,
                        CommandFactory &factory) {
  std::ifstream file(filename);
  if (!file) {
    std::cerr << "Could not open commands file: " << filename << std::endl;
    return;
  }

  std::string line;
  while (getline(file, line)) {
    if (line.empty())
      continue;

    Command *command = factory.createCommand(line);
    if (command) {
      store->executeCommand(command);
      delete command;
    } else {
      std::cerr << "Failed to execute command: " << line << std::endl;
    }
  }
}