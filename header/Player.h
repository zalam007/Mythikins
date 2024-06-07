#pragma once

#include <string>
#include <vector>
#include "../header/Location.h"
#include "../header/Mythikin.h"
#include "../header/Item.h"
#include "../header/Character.h"
using std::string;

class Player : public Character
{
private:
  Location currentLocation = Location("No Name"); //Needed to have a default value for location, this was the only way

public:
  Player(const string &name = "No Name",Location currentLocation = Location("No Name"),Team team = Team(), const vector<Item*> &items = vector<Item*>(), int mythicoins = 0) {
    Character::name = name;
    Character::team = team;
    Character::items = items;
    Character::mythicoins = mythicoins;
    this->currentLocation = currentLocation;
  }


  const string &getName() const { return Character::name; }
  const Location &getLocation() const { return currentLocation; }
  Team &getTeam()  { return Character::team; }
  vector<Item*> &getInventory() { return Character::items; }


  void setLocation(const Location &newLocation) { currentLocation = newLocation; }
  


  void addItem(Item* newItem) { Character::items.push_back(newItem); } // Adds the parameter item to items vector
  void removeItem(const string &itemName);                  // Uses the name of the item to remove it from the items vector


};