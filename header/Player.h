#pragma once

#include <string>
#include <vector>
#include "./Location.h"
#include "../mythikin.h"
#include "./Item.h"
#include "./Character.h"
using std::string;

class Player : public Character
{
private:
  Location currentLocation;

public:
  Player(const string &name = "No Name", const Location &currentLocation = Location(), Team team = Team(), const vector<Item*> &items = vector<Item*>(), int mythicoins = 0) {
    Character::name = name;
    Character::team = team;
    Character::items = items;
    Character::mythicoins = mythicoins;
    this->currentLocation = currentLocation;
  }

  

  const string &getName() const { return Character::name; }
  const Location &getLocation() const { return currentLocation; }
  Team &getTeam()  { return Character::team; }
  const vector<Item*> &getInventory() const { return Character::items; }


  void setLocation(const Location &newLocation) { currentLocation = newLocation; }
  


  void addItem(Item* newItem) { Character::items.push_back(newItem); } // Adds the parameter item to items vector
  void removeItem(const string &itemName);                  // Uses the name of the item to remove it from the items vector


};