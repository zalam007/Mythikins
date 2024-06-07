#include "../header/Character.h"
#include "../header/Item.h"

using std::string;


Character::~Character() {
  for (unsigned i = 0; i < items.size(); i++) {
    delete items.at(i);
  }
}

void Character::useItem(const string& itemBeingUsed, Mythikin& recipient) { //Feel like it'd be better to use the name of the item here
  for (unsigned i = 0; i < items.size(); i++) {
    if (items.at(i)->getName() == itemBeingUsed) { //Check if name of param matches name in inventory
        items.at(i)->use(recipient);
      if (items.at(i)->getQuantity() == 0) { //If quantity is zero, delete it from inventory
        items.erase(items.begin() + i);
      }
    }
  }
}