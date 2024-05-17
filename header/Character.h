#pragma once

#include <string>
#include <vector>
#include "../mythikin.h"
#include "./Item.h"
#include <cstdlib>

using std::string;

class Character {
  private:
    string name;
    vector<Mythikin> team;
    vector<Item*> items;
    int mythicoins;
  public:
    string getName() const {return name;}
    const vector<Mythikin>& getTeam() const {return team;}
    const vector<Item*>& getInventory() const {return items;}
    int getCoins() const { return mythicoins; }

    void setName(const string& newName) { name = newName; }
    void addMythikin(const Mythikin& newMythikin);
    void removeMythikin(const string& name);

    void addCoins(int amnt) { mythicoins += amnt; }
    void removeCoins(int amnt) { mythicoins -= amnt; }

    void useItem(Item*);


};