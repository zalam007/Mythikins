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
  Location* currentLocation = new Location("No Name"); //Needed to have a default value for location, this was the only way

public:
  Player(const string &name = "No Name", Location* currentLocation = new Location("No Name"), Team team = Team(), const vector<BattleItem*> &battleItems = vector<BattleItem*>(), const vector<Item*> &items = vector<Item*>(), int mythicoins = 0) {
    Character::name = name;
    Character::team = team;
    Character::battleItems = battleItems;
    Character::items = items;
    Character::mythicoins = mythicoins;
    this->currentLocation = currentLocation;
  }

  ~Player() {
    Character::battleItems.clear();
    Character::items.clear();
  }

  const string &getName() const { return Character::name; }
  Location* getLocation()  { return currentLocation; }
  Team &getTeam() { return Character::team; }
  vector<BattleItem*>& getBattleInventory() {return Character::battleItems;}
  vector<Item*>& getItemInventory() {return Character::items;}

  void setLocation(Location* newLocation) { currentLocation = newLocation; }
  
  void addItem(Item* newItem) { Character::items.push_back(newItem); } // Adds the parameter item to items vector
  void addBattleItem(BattleItem* newBattleItem) { Character::battleItems.push_back(newBattleItem); } // Adds the parameter item to items vector
  void removeItem(const string &itemName); // Uses the name of the item to remove it from the items vector

  Item* findItemByName(const string &itemName);
};