#include "../../header/Menus/BattleMenu.h"
#include <iostream>

using namespace std;

BattleMenu::BattleMenu(Player mainChar, NPC opponentNPC) {
  this->mainChar = mainChar;
  this->opponentNPC = opponentNPC;
  Battle playerVsNPC = Battle();
  // while(playerVsNPC.isOver()) {//Not Implemented Yet, comment out later

  while(true) {
    printMenu();

    char option;
    if (!(cin >> option)) { //If invalid input, print err and start over loop 
      cout << "Invalid Input" << endl;
      cin.clear();
      cin.ignore(256, '\n');
      continue;
    }

    //Checks user input for all the options of printMenu()
    switch (option) {
    case '1' :
      attack();
      break;

    case '2' :
      inventory();
      break;
    
    case '3' :
      swap();
      break;
    
    case '4' :
      flee();
      break;

    default:
      cout << "Invalid Input" << endl;
      break;
    }
    cin.ignore(256, '\n'); //Clear cin

    //Opponent's turn:

    
  }

}
BattleMenu::BattleMenu(Player mainChar, Mythikin wildMythikin) {
}

BattleMenu::~BattleMenu() {}


void BattleMenu::printMenu() {
  cout << "(1) Attack\n(2) Inventory\n(3) Swap\n(4) Flee" << endl;
}

void BattleMenu::attack() { //Stubbed
  cout << "Not Done Yet: attack()" << endl;
}

void BattleMenu::inventory() { //Stubbed
  cout << "Not Done Yet: inventory()" << endl;
}

void BattleMenu::swap() { //Stubbed
  cout << "Not Done Yet: swap()" << endl;
}

void BattleMenu::flee() { //Stubbed
  cout << "Not Done Yet: flee()" << endl;
}


