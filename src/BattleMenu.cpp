#include "../header/BattleMenu.h"

#include <iostream>

using namespace std;

BattleMenu::BattleMenu(Player& mainChar, NPC& opponentNPC) {
  Battle playerVsNPC = Battle(mainChar.getTeam(), opponentNPC.getTeam());
  while(!playerVsNPC.isOver()) {

    if (mainChar.getTeam().getSlot(0).isKnocked()) { //Checks if main Mythikin was knocked, prompts swap if yes
      cout << mainChar.getTeam().getSlot(0).getName() << " was knocked out." << endl;
      swap(mainChar);
    }

    if (opponentNPC.getTeam().getSlot(0).isKnocked()) {
      cout << opponentNPC.getName() << "'s "<< opponentNPC.getTeam().getSlot(0).getName() << " was knocked out." << endl;
      for (int i = 1; i < opponentNPC.getTeam().getSize(); i++) {
        if (!opponentNPC.getTeam().getSlot(i).isKnocked()) {
          opponentNPC.getTeam().swapSlots(0, i);
          cout << opponentNPC.getName() << " chose " << opponentNPC.getTeam().getSlot(0).getName() << endl;
        }
      }
      
    }

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
      attack(playerVsNPC, mainChar, opponentNPC);
      break;

    case '2' :
      inventory(mainChar);
      break;
    
    case '3' :
      swap(mainChar);
      break;

    default:
      cout << "Invalid Input" << endl;
      break;
    }
    cin.ignore(256, '\n'); //Clear cin
    

    //Opponent's turn:
    cout << "\n" << opponentNPC.getName() << "'s turn: " << endl;
    playerVsNPC.AIAttack(opponentNPC.getTeam().getSlot(0), mainChar.getTeam().getSlot(0));

    cout << "\n" << mainChar.getTeam().getSlot(0).getName() << "'s health: " << mainChar.getTeam().getSlot(0).getHP();
    cout << "\nOpponent's " << opponentNPC.getTeam().getSlot(0).getName() << "'s health: " << opponentNPC.getTeam().getSlot(0).getHP() << endl << endl;

    
  }

  //TODO: Print out what you gained from winning
  if (playerVsNPC.ifWon()) {
    cout << "You Won!" << endl << endl;
  } else {
    cout << "You lost" << endl << endl;
  }

}
BattleMenu::BattleMenu(Player& mainChar, Mythikin& wildMythikin) {
  // Battle playerVsWild = Battle(mainChar.getTeam(), wildMythikin); // Talk about redoing WildBattle
}

BattleMenu::~BattleMenu() {}


void BattleMenu::printMenu() {
  cout << "Battle Menu: " << endl;
  cout << "(1) Attack\n(2) Inventory\n(3) Swap " << endl;
}

void BattleMenu::printWildBattleMenu() {
  cout << "Wild ";
  printMenu();
  cout << "(4) Flee " << endl; 
}

void BattleMenu::attack(Battle& currBattle, Player& mainChar, NPC& opponentNPC) { 
  cout << "Choose an attack: " << endl;
  vector<Attack> possibleAttacks = mainChar.getTeam().getSlot(0).getAttacks(); //Cache the attack vector
  for (unsigned i = 0; i < possibleAttacks.size(); i++) {
    cout << i + 1 << ".) " << possibleAttacks.at(i).getName() << endl; // Print out every attack possible 
  }


  int option;
  while (!(cin >> option) || option < 1 || option > possibleAttacks.size()) { //Bounds Checking  
    cout << "Invalid Input" << endl;
    cin.clear();
    cin.ignore(256, '\n');
  }

  currBattle.stageAttack(mainChar.getTeam().getSlot(0), opponentNPC.getTeam().getSlot(0), possibleAttacks.at(option-1)); //Takes mythikin from slot 0 as main mythikin, and attack comes from user choice

}

void BattleMenu::inventory(Player& mainChar) { //Need to talk about PC in wildBattle
  
  if(mainChar.getInventory().size() == 0) {
    cout << "Inventory Empty" << endl;
  }
  for (unsigned i = 0; i < mainChar.getInventory().size(); i++) {
    cout << "(" << i + 1 << ") " << mainChar.getInventory().at(i)->getName() << " x" << mainChar.getInventory().at(i)->getQuantity() << endl;
  }

  int option;
  while (!(cin >> option) || option < 1 || option > mainChar.getInventory().size()) { //Bounds Checking  
    cout << "Invalid Input" << endl;
    cin.clear();
    cin.ignore(256, '\n');
  } 

  if (mainChar.getInventory().at(option-1)->getName() == "Mythicube") {//Talk about how to implement this going forward
    cout << "Cannot catch an opponent's Mythikin" << endl; 
  } else {
    mainChar.getInventory().at(option-1)->use(mainChar.getTeam().getSlot(0)); //Use the item (Bug, health doesn't update)
    mainChar.getInventory().at(option-1)->setQuantity(mainChar.getInventory().at(option-1)->getQuantity() - 1); // Decrease quantity by 1
    if (mainChar.getInventory().at(option-1)->getQuantity() <= 0) { // If quantity is <= 0, remove it
      mainChar.removeItem(mainChar.getInventory().at(option-1)->getName());
    }
  } 
}

void BattleMenu::swap(Player& mainChar) {
  if (mainChar.getTeam().getSize() == 1) { //Edge Case: Only one Mythikin on team
    cout << "No Mythikins to swap with" << endl;
    return;
  }

  cout << "Select a Mythikin to swap with: " << endl;
  for (int i = 1; i < mainChar.getTeam().getSize(); i++) {
    cout << "(" << i << ") "<< mainChar.getTeam().getSlot(i).getName() << endl; //Prints out team minus first pokemon, since that is the main one
  }
  
  int option;
  while (!(cin >> option) || option < 1 || option > mainChar.getTeam().getSize()) { //Bounds Checking  
    cout << "Invalid Input" << endl;
    cin.clear();
    cin.ignore(256, '\n');
  }
  mainChar.getTeam().swapSlots(0, option); 
}

void BattleMenu::flee(WildBattle& currBattle) { //Stubbed
  cout << "Not Done Yet: flee()" << endl;
}


