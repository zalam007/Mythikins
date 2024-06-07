#pragma once

#include <string>
#include <vector>
#include "Mythikin.h"
#include "Item.h"
#include "Team.h"
#include <cstdlib>

using std::string;

class Character {
  protected:
    string name;
    Team team;
    vector<Item*> items;
    int mythicoins = 0;
  public:
    ~Character();

    string getName() const {return name;}
    Team& getTeam() {return team;}
    vector<Item*>& getInventory() {return items;}
    int getCoins() const { return mythicoins; }

    void setName(const string& newName) { name = newName; }
    void setTeam(Team newTeam) { team = newTeam; }

    void addMythikin(Mythikin newMythikin) {team.addMythikin(newMythikin); }
    void removeMythikin(const string& name) { team.removeMythikin(name);}

    void addCoins(int amnt) { mythicoins += amnt; }
    void removeCoins(int amnt) { mythicoins -= amnt; }

    void setItems(const vector<Item*> newItems) {items = newItems;}
    void useItem(const string&, Mythikin&);


};