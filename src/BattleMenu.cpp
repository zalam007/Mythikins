#include "../header/BattleMenu.h"

#include <iostream>

using namespace std;

BattleMenu::BattleMenu(Player& mainChar, NPC& opponentNPC)
  : mainChar(mainChar), opponentNPC(opponentNPC) {
}

BattleMenu::~BattleMenu() {}


void BattleMenu::gameplay() {
  Battle playerVsNPC = Battle(mainChar.getTeam(), opponentNPC.getTeam());

  cout << "A battle is starting...\n" << endl;
  cout << mainChar.getName() << " chooses " << mainChar.getTeam().getSlot(0).getName() << "." << endl << endl;
  cout << opponentNPC.getName() << " chooses " << opponentNPC.getTeam().getSlot(0).getName() << "." << endl << endl;

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

    //PLAYER'S TURN:
    char option;

    while(!playerActed){
      printMenu();
      
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
    }
    playerActed = false;

    if(!playerVsNPC.isOver()){ // Check if the battle is over to prevent Opponent's turn
      //Opponent's turn:
      cout << "\n" << opponentNPC.getName() << "'s turn: " << endl;

      if((opponentNPC.findBattleItemByName("Potion") != nullptr && opponentNPC.findBattleItemByName("Potion")->getQuantity() > 0) && opponentNPC.getTeam().getSlot(0).getHP() < opponentNPC.getTeam().getSlot(0).getMaxHP()/2) {
        BattleItem* opponentItem = static_cast<BattleItem*>(opponentNPC.findBattleItemByName("Potion"));
        opponentItem->use(opponentNPC.getTeam().getSlot(0));

        cout << opponentNPC.getName() << " used a potion!" << endl;
      }
      else{
        playerVsNPC.AIAttack(opponentNPC.getTeam().getSlot(0), mainChar.getTeam().getSlot(0));
      }

      cout << "\n" << mainChar.getTeam().getSlot(0).getName() << "'s health: ";
      if (mainChar.getTeam().getSlot(0).getHP() < 0) {
        cout << "0" << endl << endl;
      } else {
        cout << mainChar.getTeam().getSlot(0).getHP() << endl << endl;
      }

      cout << "\nOpponent's " << opponentNPC.getTeam().getSlot(0).getName() << "'s health: ";
      if (opponentNPC.getTeam().getSlot(0).getHP() < 0) {
        cout << "0" << endl << endl;
      } else {
        cout << opponentNPC.getTeam().getSlot(0).getHP() << endl << endl;
      }
    }

  }

  //TODO: Print out what you gained from winning
  if (playerVsNPC.ifWon()) {
    cout << "You won the battle!" << endl << endl;

    cout << "You gained " << opponentNPC.getCoins() << " coins." << endl;

    mainChar.addCoins(opponentNPC.getCoins());

    playerWon = true;
  } else {
    cout << "You lost the battle!" << endl << endl;

    cout << "You lost " << mainChar.getCoins()/2 << " coins." << endl;

    playerWon = false;
  }
}



void BattleMenu::printMenu() {
  cout << "Battle Menu: " << endl;
  cout << "(1) Attack\n(2) Inventory\n(3) Swap " << endl;
}

void BattleMenu::attack(Battle& currBattle, Player& mainChar, NPC& opponentNPC) { 
  cout << "Choose an attack: " << endl;
  vector<Attack>& possibleAttacks = mainChar.getTeam().getSlot(0).getAttacks(); //Cache the attack vector
  for (unsigned i = 0; i < possibleAttacks.size(); i++) {
    cout << i + 1 << ".) " << possibleAttacks.at(i).getName() 
    << " MM " << possibleAttacks.at(i).getMM() << "/" << possibleAttacks.at(i).getMaxMM() << endl; // Print all attacks possible and MM
  }

  cout << "\nPress -1 to go back\n" 
  << endl;

  int option;
  while (true) { // Choosing attack  
    cin >> option;
    if(option > 0 && option <= possibleAttacks.size()) {
      playerActed = true;
      break;
    }
    else if (option == -1) {
      return;
    }
    cout << "Invalid attack input" << endl;

    for (unsigned i = 0; i < possibleAttacks.size(); i++) {
      cout << i + 1 << ".) " << possibleAttacks.at(i).getName() 
      << " MM " << possibleAttacks.at(i).getMM() << "/" << possibleAttacks.at(i).getMaxMM() << endl; // Print all attacks possible and MM
    }

    cin.clear();
    cin.ignore(256, '\n');
  }
  cout << endl;

  currBattle.stageAttack(mainChar.getTeam().getSlot(0), opponentNPC.getTeam().getSlot(0), possibleAttacks.at(option-1)); //Takes mythikin from slot 0 as main mythikin, and attack comes from user choice

}

void BattleMenu::inventory(Player& mainChar) { //Need to talk about PC in wildBattle
  if(mainChar.getBattleInventory().size() == 0) {
    cout << "Inventory Empty" << endl;
  }
  for (unsigned i = 0; i < mainChar.getBattleInventory().size(); i++) {
    cout << "(" << i + 1 << ") " << mainChar.getBattleInventory().at(i)->getName() << " x" << mainChar.getBattleInventory().at(i)->getQuantity() << endl;
  }

  cout << "\nPress -1 to go back\n" 
    << endl;

  int option;

  while (true) { // Choosing item from inventory
    cin >> option;
    if (option > 0 && option <= mainChar.getBattleInventory().size()) {
      playerActed = true;
      break;
    }
    else if (option == -1) {
      return;
    }
    cout << "Invalid Input" << endl << endl;

    for (unsigned i = 0; i < mainChar.getBattleInventory().size(); i++) {
      cout << "(" << i + 1 << ") " << mainChar.getBattleInventory().at(i)->getName() << " x" << mainChar.getBattleInventory().at(i)->getQuantity() << endl;
    }

    cout << "\nPress -1 to go back\n" 
      << endl;

    cin.clear();
    cin.ignore(256, '\n');
  }

  if (mainChar.getBattleInventory().at(option-1)->getName() == "Mythicube") {//Talk about how to implement this going forward
    cout << "You can't catch your opponent's mythikin." << endl << endl;
  } 
  else {
    mainChar.getBattleInventory().at(option-1)->use(mainChar.getTeam().getSlot(0)); //Use the item (Bug, health doesn't update)
    if (mainChar.getBattleInventory().at(option-1)->getQuantity() <= 0) { // If quantity is <= 0, remove it
      mainChar.removeItem(mainChar.getBattleInventory().at(option-1)->getName());
    }
  } 
}

void BattleMenu::swap(Player& mainChar) {
  if (mainChar.getTeam().getSize() == 1) { //Edge Case: Only one Mythikin on team
    cout << "No Mythikins to swap with" << endl;
    return;
  }

  cout << "Select a Mythikin to swap with: " << endl;
  for (int i = 0; i < mainChar.getTeam().getSize(); i++) {
    cout << "(" << i + 1 << ") "<< mainChar.getTeam().getSlot(i).getName(); //Prints out team minus first mythikin, since that is the main one
    if (mainChar.getTeam().getSlot(i).getHP() <= 0) {
      cout << " (Knocked Out) ";
    }
    cout << endl;
  }

  if(!mainChar.getTeam().getSlot(0).isKnocked()){ //Check if the mythikin is knocked out
    cout << "\nPress -1 to go back\n" << endl;
  }

  int option;
  while (true) { // Swap choices
    cin >> option;
    if(option > 0 && option <= mainChar.getTeam().getSize()) {
      if(mainChar.getTeam().getSlot(option-1).isKnocked()){ //Check if the mythikin is knocked out
        cout << "This Mythikin is knocked out" << endl;
        option = 0;
      }
      else {
        playerActed = true;
        break;
      }
    }
    else if(option == -1) {
      if(!mainChar.getTeam().getSlot(0).isKnocked()){ //Check if the mythikin is knocked out
        return;
      }
    }
    cout << "Invalid Input" << endl;

    cout << "Select a Mythikin to swap with: " << endl;
    for (int i = 0; i < mainChar.getTeam().getSize(); i++) {
      cout << "(" << i + 1 << ") "<< mainChar.getTeam().getSlot(i).getName(); //Prints out team minus first mythikin, since that is the main one
      if (mainChar.getTeam().getSlot(i).getHP() <= 0) {
        cout << " (Knocked Out) ";
      }
      cout << endl;
    }
    
    if(!mainChar.getTeam().getSlot(0).isKnocked()){ //Check if the mythikin is knocked out
      cout << "\nPress -1 to go back\n" << endl;
    }

    cin.clear();
    cin.ignore(256, '\n');
  }
  mainChar.getTeam().swapSlots(0, option-1);
  cout << "Swapped " << mainChar.getTeam().getSlot(0).getName() << " with " << mainChar.getTeam().getSlot(option-1).getName() << endl;
}

bool BattleMenu::getPlayerWon() {
  return playerWon;
}