#include "../header/WildBattleMenu.h"


//To Implement: Inventory Override

void WildBattleMenu::wildGameplay() {
  WildBattle playerVsMythikin = WildBattle(mainChar.getTeam(), wildMythikin); //Create a battle between the player and the wild mythikin

  //Print out the battle starting
  this_thread::sleep_for(chrono::milliseconds(500));  // Delay for cout
  cout << "\nA battle is starting";
  this_thread::sleep_for(chrono::seconds(1));
  cout << "...\n" << endl;
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << "A Wild " << wildMythikin.getName() << " is attacking!\n" << endl;
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << mainChar.getName() << " chooses " << mainChar.getTeam().getSlot(0).getName() << "." << endl << endl;

  // While the battle is not over, keep looping
  while(!playerVsMythikin.isOver()) {

    //Checks if main Mythikin was knocked, prompts swap if yes
    if (mainChar.getTeam().getSlot(0).isKnocked()) {
      this_thread::sleep_for(chrono::milliseconds(500));
      cout << mainChar.getTeam().getSlot(0).getName() << " was knocked out." << endl;
      swap(mainChar);
    }

    printMenu();  //(1) Attack (2) Inventory (3) Swap (4) Flee

    //Get player menu input
    char menuInput;
    if (!(cin >> menuInput)) { //If invalid input, print error and start over loop 
      cerr << "Invalid Input." << endl;
      cin.clear();
      cin.ignore(256, '\n');
      continue;
    }
    cout << endl;

    //Checks user input for all the options of printMenu()
    switch (menuInput) {
    case '1' :
      attackWild(playerVsMythikin, mainChar, wildMythikin);
      break;

    case '2' :
      inventory(mainChar, playerVsMythikin);
      if (playerVsMythikin.isCaught == true) {
        cout << "You caught the " << wildMythikin.getName() << "!" << endl << endl;
        return;
      } else {
        cout << wildMythikin.getName() << " escaped the mythicube." << endl << endl;
      }
      break;
    
    case '3' :
      swap(mainChar);
      break;

    case '4' :
      if (playerVsMythikin.Flee()) {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << mainChar.getName() << " fled successfully." << endl << endl;
        return;
      } else {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << mainChar.getName() << " tried to flee, but failed." << endl << endl;
      } 
      break;

    default:
      cerr << "Invalid number" << endl;
      break;
    }
    cin.ignore(256, '\n'); //Clear cin
    

    //OPPENTENTS TURN:
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\n" << wildMythikin.getName() << "'s turn: " << endl;
    playerVsMythikin.AIAttack(wildMythikin, mainChar.getTeam().getSlot(0));

    // Print players health
    cout << "\n" << mainChar.getTeam().getSlot(0).getName() << "'s health: ";
    if (mainChar.getTeam().getSlot(0).getHP() < 0) {
      cout << "0" << endl << endl;
    } else {
      cout << mainChar.getTeam().getSlot(0).getHP() << endl << endl;
    }

    // Print opponents health
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


//(1) Attack
void WildBattleMenu::attackWild(WildBattle& playerVsMythikin, Player& mainChar, Mythikin& wildMythikin) {
  cout << "Choose an attack: " << endl;
  vector<Attack> possibleAttacks = mainChar.getTeam().getSlot(0).getAttacks(); //Cache the attack vector
  for (unsigned i = 0; i < possibleAttacks.size(); i++) {
    cout << i + 1 << ".) " << possibleAttacks.at(i).getName() 
    << " MM " << possibleAttacks.at(i).getMM() << "/" << possibleAttacks.at(i).getMaxMM() << endl; // Print all attacks possible and MM
  }

  int attackInput;
  while (!(cin >> attackInput) || attackInput < 1 || attackInput > possibleAttacks.size()) { //Bounds Checking  
    cout << "Invalid attack input" << endl;
    cin.clear();
    cin.ignore(256, '\n');
  }
  cout << endl;

  playerVsMythikin.stageAttack(mainChar.getTeam().getSlot(0), wildMythikin, possibleAttacks.at(attackInput-1)); //Takes mythikin from slot 0 as main mythikin, and attack comes from user choice
}


//(2) Inventory
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
    if (mainChar.getInventory().at(option-1)->getQuantity() <= 0) { // If quantity is <= 0, remove it
      mainChar.removeItem(mainChar.getInventory().at(option-1)->getName());
    }
  }
}



//catchMythikin helper
void WildBattleMenu::catchMythikin(WildBattle& playerVsMythikin, Mythikin& wildMythikin, PC& storedMythikin, Mythicube& usedMythicube) {
  playerVsMythikin.catchMythikin(storedMythikin, usedMythicube);
}

//print attack menu options
void WildBattleMenu::printMenu() {
  this_thread::sleep_for(chrono::seconds(1));
  cout << "Lv. " << mainChar.getTeam().getSlot(0).getLevel() << " " << mainChar.getTeam().getSlot(0).getName() << "  HP " << mainChar.getTeam().getSlot(0).getHP() << endl;
  cout << "What will " << mainChar.getTeam().getSlot(0).getName() << " do?" << endl;
  cout << "(1) Attack\n(2) Inventory\n(3) Swap\n(4) Flee" << endl;
}