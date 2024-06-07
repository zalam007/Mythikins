#include "header/WildBattleMenu.h"
#include "header/BattleMenu.h"
#include "header/Item.h"
#include "header/PC.h"
#include "header/Potion.h"
#include "header/Mythicube.h"
#include "header/Player.h"
#include "header/Character.h"
#include "header/NPC.h"
#include "header/Menu.h"
#include "header/Location.h"

int main() {
  string name;
  {
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

  cout << "This is a demo of our text-based game \"Mythikins\", we will be doing a basic battle with a wild Mythikin" << endl << endl;

  Attack magmaATK1 = Attack("HoofSpark", "magma", 15, 90, 10);
  Attack magmaATK2 = Attack("FlameCharge", "magma", 20, 80, 15);
  Attack magmaATK3 = Attack("MagmaSmash", "magma", 25, 75, 10);

  Attack aquaATK1 = Attack("TidalFang", "aqua", 25, 85, 10);
  Attack aquaATK2 = Attack("AquaVortex", "aqua", 25, 80, 10);
  Attack aquaATK3 = Attack("Rippleclaw", "aqua", 15, 95, 10);

  Attack floraATK1 = Attack("RootSlap", "flora", 15, 90, 10);
  Attack floraATK2 = Attack("ThornSlash", "flora", 25, 80, 10);
  Attack floraATK3 = Attack("BuddingBlast", "flora", 25, 85, 5);

  Mythikin aquafin = Mythikin("Aquafin", "aqua", 1, 50, 100);
  Mythikin stemlet = Mythikin("Stemlet", "flora", 1, 50, 100);
  Mythikin blazehoof = Mythikin("Blazehoof", "magma", 1, 50, 100);
  Mythikin vinebeast = Mythikin("Vinebeast", "flora", 3, 90, 250);


  aquafin.addAttack(aquaATK1);
  aquafin.addAttack(aquaATK2);
  aquafin.addAttack(aquaATK3);

  stemlet.addAttack(floraATK1);
  stemlet.addAttack(floraATK2);
  stemlet.addAttack(floraATK3);

  blazehoof.addAttack(magmaATK1);
  blazehoof.addAttack(magmaATK2);
  blazehoof.addAttack(magmaATK3);


  vinebeast.addAttack(floraATK1);
  vinebeast.addAttack(floraATK2);
  vinebeast.addAttack(floraATK3);



  Item* healingPotion = new Potion("Health Potion", 2, 4, 25, 100);
  Item* catchCube = new Mythicube("Mythicube", 2, 4, 50, 50);

  vector<Item *> playerInventory;
  



  Location emptyLocation;
  Team playerTeam;
  PC placeholderPC;

  playerTeam.addMythikin(aquafin);
  playerTeam.addMythikin(blazehoof);
  playerTeam.addMythikin(stemlet);

  cout << "Choose a Mythikin to lead your team: " << endl << endl;
  cout << "(1) Aquafin\n(2) Stemlet\n(3) Blazehoof" << endl;

  int option;
  while(!(cin >> option) || option < 1 || option > 3) {
    cout << "Not a valid input";
    cin.ignore(256, '\n');
  }

  switch (option)
  {
  case 2:
    playerTeam.swapSlots(0, 2);
    break;
  
  case 3:
    playerTeam.swapSlots(0, 1);
    break;
  
  default:
    break;
  }

  Player mainChar(name, emptyLocation, playerTeam, playerInventory, 500);
  mainChar.addItem(healingPotion);
  mainChar.addItem(catchCube);

  WildBattleMenu demoBattle(mainChar, vinebeast, placeholderPC);

  demoBattle.wildGameplay();



  cout << "Thanks for playing our demo, more on the horizon." << endl;

  return 0;




}