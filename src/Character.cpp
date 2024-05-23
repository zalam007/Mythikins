#include "../header/Character.h"
#include "../header/Item.h"

using std::string;

void Character::useItem(const string& itemBeingUsed, const string& mythikinName) { //Feel like it'd be better to use the name of the item here
  for (unsigned i = 0; i < items.size(); i++) {
    if (items.at(i)->getName() == itemBeingUsed) { //Check if name of param matches name in inventory
      for (unsigned j = 0; j < team.getSize(); j++) { //Searches team for the right mythikin the item will be used on
        items.at(i)->use(team.getSlot(j));
      }
      if (items.at(i)->getQuantity() == 0) { //If quantity is zero, delete it from inventory
        items.erase(items.begin() + i);
      }
    }
  }
}