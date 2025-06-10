#include "read.h"
#include "commandfactory.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

static string trim(const string &s) {
  auto b = s.find_first_not_of(" \t");
  auto e = s.find_last_not_of(" \t");
  return (b == string::npos) ? "" : s.substr(b, e - b + 1);
}

void loadStoreData(Store &store, const string &customersFile,
                   const string &moviesFile, const string &commandsFile) {
  ifstream cf(customersFile);
  ifstream mf(moviesFile);
  ifstream cmdf(commandsFile);

  if (!cf.is_open()) {
    cerr << "Error: Cannot open customer file\n";
    return;
  }
  if (!mf.is_open()) {
    cerr << "Error: Cannot open movie file\n";
    return;
    }
  if (!cmdf.is_open()) {
    cerr << "Error: Cannot open command file\n";
    return;
}

  // Load customers
  string line;
  while (getline(cf, line)) {
    if (line.empty()) {
      continue;
  }

    stringstream ss(line);
    int id;
    string name;
    ss >> id;
    getline(ss, name);

    if (!name.empty() && name[0] == ' ') {
      name = name.substr(1);
    }
    store.addCustomer(id, name); // skip leading space
  }

  // Load movies
  while (getline(mf, line)) {
    if (line.empty()) {
      continue;
    }

  stringstream ss(line);
    char genre;
    int stock;

    ss >> genre;
    ss >> stock;
    ss.ignore();

    try {
      if (genre == 'F') {
        string director;
        string title;
        int year;

        getline(ss, director, ','); // already the first item after 'F'
        getline(ss, title, ',');
        ss >> year;

        director = trim(director);
        title = trim(title);

        Movie *m = new Comedy(stock, director, title, year);
        store.addMovie(m);
      } else if (genre == 'D') {
        string director;
        string title;
        int year;

        getline(ss, director, ',');
        getline(ss, title, ',');
        ss >> year;

        director = trim(director);
        title = trim(title);

        Movie *m = new Drama(stock, director, title, year);
        store.addMovie(m);
      } else if (genre == 'C') {
        string director;
        string title;
        int month;
        int year;
        string actorFirst;
        string actorLast;

        getline(ss, director, ',');
        getline(ss, title, ',');
        ss >> actorFirst >> actorLast >> month >> year;

        director = trim(director);
        title = trim(title);
        actorFirst = trim(actorFirst);
        actorLast = trim(actorLast);

        Movie *m = new Classics(stock, director, title, year, month, actorFirst, actorLast);
        store.addMovie(m);
      } else {
        cerr << "Unknown movie type: " << genre << ", discarding line: " << line << endl;
        continue;
      }
    } catch (const exception &e) {
      cerr << "Error parsing movie line: " << line << "\n"
           << "Reason: " << e.what() << endl;
  }
}

  // Load commands
  CommandFactory factory(&store);
  while (getline(cmdf, line)) {
    if (line.empty()) {
      continue;
    }
    Command *cmd = CommandFactory::createCommand(line);
    if (cmd != nullptr) {
      cmd->execute(&store);
      delete cmd;
    }
  }
}
