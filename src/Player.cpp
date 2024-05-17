#include "../header/Player.h"

void Player::removeMythikin(const string& mythiName) {
  for (unsigned i = 0; i < team.size(); i++) {
    if(team.at(i).getName() == mythiName) {
      team.erase(team.begin() + i);
    }
  }
  //Does nothing if name not found
}

void Player::removeItem(const string& itemName) {
  for (unsigned i = 0; i < items.size(); i++) {
    if(items.at(i)->getName() == itemName) {
      items.erase(items.begin() + i);
    }
  }
  //Does nothing if name not found
}