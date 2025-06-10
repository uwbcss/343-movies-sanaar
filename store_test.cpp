/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

#include "command.h"
#include "commandfactory.h"
#include "read.h"
#include "store.h"

using namespace std;

void testStore1() {
  cout << "Start testStore1" << endl;
  string cfile = "testcommands-1.txt";

  ifstream fs(cfile);
  assert(fs.is_open());
  stringstream out;
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End testStore1" << endl;
}

void testStore2() {
  cout << "Start testStore2" << endl;
  cout << "End testStore2" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;

  Store store;
  CommandFactory factory(&store);

  Read::readCustomers("data4customers.txt", &store);
  Read::readMovies("data4movies.txt", &store);
  Read::readCommands("data4commands.txt", &store, factory);

  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  testStore1();
  testStore2();
  testStoreFinal();
}