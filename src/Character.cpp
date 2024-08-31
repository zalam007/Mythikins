#include "../header/Character.h"
#include "../header/Item.h"

using std::string;



void Character::useItem(const string& itemBeingUsed, Mythikin& recipient) { //Feel like it'd be better to use the name of the item here
  for (unsigned i = 0; i < battleItems.size(); i++) {
    if (battleItems.at(i)->getName() == itemBeingUsed) { //Check if name of param matches name in inventory
        battleItems.at(i)->use(recipient);
      if (battleItems.at(i)->getQuantity() == 0) { //If quantity is zero, delete it from inventory
        battleItems.erase(battleItems.begin() + i);
      }
    }
  }
}