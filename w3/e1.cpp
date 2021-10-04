#include <iostream>
#include <set>

using namespace std;

int main() {
  string command;
  int arg;

  set<int, greater<int> > bag;

  while (true) {
    cin >> command;
    if (command == "quit") {
      break;
    } else {
      cin >> arg;
      if (command == "add") {
        bag.insert(arg);
      } else if (command == "del") {
        bag.erase(arg);
      } else if (command == "qry") {
        bool result = bag.find(arg) != bag.end();
        cout << (result ? "T" : "F");
      }
    }
  }

  return 0;
}