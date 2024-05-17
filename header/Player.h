#pragma once

#include <string>
#include <vector>
#include "./Location.h"
#include "../mythikin.h"
#include "./Item.h"
using std::string;

class Player
{
private:
  string name;
  Location currentLocation;
  vector<Mythikin> team;
  vector<Item*> items;
  int mythicoins;

public:
  Player(const string &name = "No Name", const Location &currentLocation = Location(), const vector<Mythikin> &team = vector<Mythikin>(), const vector<Item*> &items = vector<Item*>(), int mythicoins = 0) 
   : name(name), currentLocation(currentLocation), team(team), items(items), mythicoins(mythicoins) // Parameterized with some default values
  {
  }

  

  const string &getName() const { return name; }
  const Location &getLocation() const { return currentLocation; }
  const vector<Mythikin> &getTeam() const { return team; }
  const vector<Item*> &getInventory() const { return items; }
  int getCoins() const { return mythicoins; }

  void setName(const string &newName) { name = newName; }
  void setLocation(const Location &newLocation) { currentLocation = newLocation; }
  void setTeam(vector<Mythikin> newTeam) { team = newTeam; }
  void setItems(vector<Item*> newInventory) { items = newInventory; }

  void addMythikin(Mythikin &newKin) { team.push_back(newKin); } // Adds the parameter Mythikin to the team
  void removeMythikin(const string &mythiName);                  // Uses the name of the mythikin to remove it from team

  void addItem(Item* newItem) { items.push_back(newItem); } // Adds the parameter item to items vector
  void removeItem(const string &itemName);                  // Uses the name of the item to remove it from the items vector

  void addCoins(int amnt) { mythicoins += amnt; }
  void removeCoins(int amnt) { mythicoins -= amnt; }
};