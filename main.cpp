#include <iostream>
#include "Battle.h" // includes Mythikin.h & Attack.h
#include "Mythidex.h" //
using namespace std;

void askForName() {
  string name;
  string confirm;
  while (true) {
    cout << "Please enter your name: ";
    getline(cin, name);
    cout << "You're name is " << name << ". Is this correct? (yes/no): ";
    getline(cin, confirm);
    if (confirm == "yes") { break; }
  }
  cout << "Welcome, " << name << "!\n";
}

int main() {

  // Create Mythidex, Read Mythikins & Moves from files
  Mythidex mythidex;
  mythidex.readMythikinsFromFile("mythikins.txt");
  mythidex.readMovesFromFile("moves.txt");

  askForName();


  return 0;
}