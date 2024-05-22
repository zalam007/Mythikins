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

void Character::useItem(Item* itemBeingUsed, const string& mythikinName) { //Feel like it'd be better to use the name of the item here
  for (unsigned i = 0; i < items.size(); i++) {
    if (items.at(i)->getName() == itemBeingUsed->getName()) { //Check if name of param matches name in inventory
      for (unsigned i = 0; i < team.size(); i++) { //Searches team for the right mythikin the item will be used on
        if (team.at(i).getName() == mythikinName) {
          items.at(i)->use(team.at(i));
        }
      }
      if (items.at(i)->getQuantity() == 0) { //If quantity is zero, delete it from inventory
        items.erase(items.begin() + i);
      }
    }
  }
}