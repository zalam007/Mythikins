#pragma once

#include <string>
#include <vector>
#include "Mythikin.h"
#include "Item.h"
#include "BattleItem.h"
#include "Team.h"
#include <cstdlib>

using std::string;

class Character {
  protected:
    string name;
    Team team;
    vector<BattleItem*> battleItems; // Usable items in battles (EX: potions & Mythicubes)
    vector<Item*> items; //Items that can't be used (EX: Medallions and story items)
    int mythicoins = 0;
  public:
    ~Character() { 
      for (unsigned i = 0; i < battleItems.size(); i++) {
        delete battleItems.at(i);
      }
      for (unsigned i = 0; i < items.size(); i++) {
        delete items.at(i);
      }
    }

    string getName() const {return name;}
    Team& getTeam() {return team;}
    vector<BattleItem*>& getBattleInventory() {return battleItems;}
    vector<Item*>& getItemInventory() {return items;}
    int getCoins() const { return mythicoins; }

    void setName(const string& newName) { name = newName; }
    void setTeam(Team newTeam) { team = newTeam; }

    void addMythikin(Mythikin newMythikin) {team.addMythikin(newMythikin); }
    void removeMythikin(const string& name) { team.removeMythikin(name);}

    void addCoins(int amnt) { mythicoins += amnt; }
    void removeCoins(int amnt) { mythicoins -= amnt; }

    void setBattleItems(const vector<BattleItem*> newBattleItems) {battleItems = newBattleItems;}
    void setItems(const vector<Item*> newItems) {items = newItems;}
    void useItem(const string&, Mythikin&);


};