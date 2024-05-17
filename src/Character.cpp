#include "../header/Character.h"
#include "../header/Item.h"

using std::string;

void Character::addMythikin(const Mythikin& newMythikin) {
  team.push_back(newMythikin);
}

void Character::removeMythikin(const string& name) {
  for (unsigned i = 0; i < team.size(); i++) {
    if(team.at(i).getName() == name) {
      team.erase(team.begin() + i);
    }
  }
  //Does nothing if name not found
}

void Character::useItem(Item* itemBeingUsed) { //Feel like it'd be better to use the name of the item here
  for (unsigned i = 0; i < items.size(); i++) {
    if (items.at(i)->getName() == itemBeingUsed->getName()) { //Check if name of param matches name in inventory
      //items.at(i)->use();   //use function requires a mythikin param, but idk which to call on
      items.at(i)->changeCapacity(items.at(i)->getCapacity() - 1); //Reduce quantity by 1
      if (items.at(i)->getQuantity() == 0) { //If quantity is zero, delete it from inventory
        items.erase(items.begin() + i);
      }
    }
  }
}