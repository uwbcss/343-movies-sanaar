#include "commandfactory.h"
#include "borrow.h"
#include "classics.h"
#include "comedy.h"
#include "drama.h"
#include "history.h"
#include "inventory.h"
#include "return.h"
#include <iostream>
#include <sstream>

using namespace std;

CommandFactory::CommandFactory(Store *store) { this->store = store; }

Command *CommandFactory::createCommand(const string &line) {
  istringstream iss(line);
  char commandType;
  iss >> commandType;

  if (commandType == 'I') {
    return new Inventory();
  }

  if (commandType == 'H') {
    int customerId;
    if (iss >> customerId) {
      return new History(customerId);
    }
  }

  if (commandType == 'B' || commandType == 'R') {
    int customerId;
    char mediaType;
    char movieType;

    if (!(iss >> customerId >> mediaType >> movieType)) {
      cerr << "Invalid format for borrow/return command: " << line << endl;
      return nullptr;
    }

    Movie *movie = nullptr;

    if (movieType == 'F') {
      string title;
      string yearStr;
      getline(iss, title, ',');
      getline(iss, yearStr);
      try {
        movie = new Comedy(0, "", title, stoi(yearStr));
      } catch (...) {
        cerr << "Invalid comedy command: " << line << endl;
        return nullptr;
      }

    } else if (movieType == 'D') {
      string director;
      string title;
      getline(iss, director, ',');
      getline(iss, title);
      size_t commaPos = title.find(',');
      if (commaPos != string::npos && commaPos + 1 < title.length()) {
        string actualTitle = title.substr(0, commaPos);
        string yearStr = title.substr(commaPos + 1);
        try {
          int year = stoi(yearStr);
          movie = new Drama(0, director, actualTitle, year);
        } catch (...) {
          cerr << "Invalid year in drama command: " << line << endl;
          return nullptr;
        }
      } else {
        cerr << "Drama movie line incorrectly formatted: " << line << endl;
        return nullptr;
      }

    } else if (movieType == 'C') {
      int month;
      int year;
      string first;
      string last;
      if (iss >> month >> year >> first >> last) {
        movie = new Classics(0, "", "", year, month, first, last);
      } else {
        cerr << "Classics movie line incorrectly formatted: " << line << endl;
        return nullptr;
      }
    }

    if (movie == nullptr) {
      cerr << "Failed to create movie: " << line << endl;
      return nullptr;
    }

    if (commandType == 'B') {
      return new Borrow(customerId, movie);
    }
    return new Return(customerId, movie);
  }

  cerr << "Unknown command type or movie type: " << line << endl;
  return nullptr;
}