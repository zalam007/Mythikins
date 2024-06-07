#include "../header/WildBattleMenu.h"


//To Implement: Inventory Override

void WildBattleMenu::wildGameplay() {
  WildBattle playerVsMythikin = WildBattle(mainChar.getTeam(), wildMythikin);

  cout << "A battle is starting...\n" << endl;

  cout << "A wild " << wildMythikin.getName() << " is attacking!" << endl << endl;
  cout << mainChar.getName() << " chooses " << mainChar.getTeam().getSlot(0).getName() << "." << endl << endl;

  
  while(!playerVsMythikin.isOver()) {

    if (mainChar.getTeam().getSlot(0).isKnocked()) { //Checks if main Mythikin was knocked, prompts swap if yes
      cout << mainChar.getTeam().getSlot(0).getName() << " was knocked out." << endl;
      swap(mainChar);
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
      attackWild(playerVsMythikin, mainChar, wildMythikin);
      break;

    case '2' :
      inventory(mainChar, playerVsMythikin);
      if (playerVsMythikin.isCaught == true) {
        cout << "You caught the " << wildMythikin.getName() << "!" << endl << endl;
        return;
      }
      break;
    
    case '3' :
      swap(mainChar);
      break;

    case '4' :
      if (playerVsMythikin.Flee()) {
        cout << mainChar.getName() << " fled successfully." << endl << endl;
        return;
      } else {
        cout << mainChar.getName() << " tried to flee, but failed." << endl << endl;
      } 
      break;

    default:
      cout << "Invalid Input" << endl;
      break;
    }
    cin.ignore(256, '\n'); //Clear cin
    

    //Opponent's turn:
    cout << "\n" << wildMythikin.getName() << "'s turn: " << endl;
    playerVsMythikin.AIAttack(wildMythikin, mainChar.getTeam().getSlot(0));

    cout << "\n" << mainChar.getTeam().getSlot(0).getName() << "'s health: ";
    if (mainChar.getTeam().getSlot(0).getHP() < 0) {
      cout << "0" << endl << endl;
    } else {
      cout << mainChar.getTeam().getSlot(0).getHP() << endl << endl;
    }

    cout << "\nOpponent's " << wildMythikin.getName() << "'s health: ";
    if (wildMythikin.getHP() < 0) {
      cout << "0" << endl << endl;
    } else {
      cout << wildMythikin.getHP() << endl << endl;
    }

    
  }

  //TODO: Print out what you gained from winning
  if (playerVsMythikin.ifWon()) {
    cout << "You Won!" << endl << endl;
  } else {
    cout << "You lost" << endl << endl;
  }
}



void WildBattleMenu::printMenu() {
  cout << "Wild Battle Menu: " << endl;
  cout << "(1) Attack\n(2) Inventory\n(3) Swap\n(4) Flee" << endl;
}

void WildBattleMenu::attackWild(WildBattle& playerVsMythikin, Player& mainChar, Mythikin& wildMythikin) {
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

  playerVsMythikin.stageAttack(mainChar.getTeam().getSlot(0), wildMythikin, possibleAttacks.at(option-1)); //Takes mythikin from slot 0 as main mythikin, and attack comes from user choice
}

void WildBattleMenu::inventory(Player& mainChar, WildBattle& playerVsMythikin) {
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

  if (mainChar.getInventory().at(option-1)->getName() == "Mythicube") {//If it's a mythicube, call catch
    catchMythikin(playerVsMythikin, wildMythikin, storedMythikin, dynamic_cast<Mythicube&>(*mainChar.getInventory().at(option-1))); // God this is stinky ass code, but it basically converts the item* type of inventory to a Mythikin &
  } else {
    mainChar.getInventory().at(option-1)->use(mainChar.getTeam().getSlot(0)); //Use the item (Bug, health doesn't update)
    mainChar.getInventory().at(option-1)->setQuantity(mainChar.getInventory().at(option-1)->getQuantity() - 1); // Decrease quantity by 1
    if (mainChar.getInventory().at(option-1)->getQuantity() <= 0) { // If quantity is <= 0, remove it
      mainChar.removeItem(mainChar.getInventory().at(option-1)->getName());
    }
  }
}

void WildBattleMenu::catchMythikin(WildBattle& playerVsMythikin, Mythikin& wildMythikin, PC& storedMythikin, Mythicube& usedMythicube) {
  playerVsMythikin.catchMythikin(storedMythikin, usedMythicube);
}

