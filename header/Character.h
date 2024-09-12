#pragma once

#include <string>
#include <vector>
#include "Mythikin.h"
#include "Item.h"
#include "Potion.h"
#include "Mythicube.h"
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

    void addItem(Item* newItem) {
        bool itemExists = false;
        for (unsigned i = 0; i < items.size(); i++) {
            if (items.at(i)->getName() == newItem->getName()) {
                // Item exists, update quantity
                items.at(i)->setQuantity(items.at(i)->getQuantity() + newItem->getQuantity());
                itemExists = true;
                break; // Exit loop once the item is found and updated
            }
        }
        
        if (!itemExists) {
            // Item doesn't exist, add new item
            items.push_back(newItem);
        }
    }


    // Adding battle items to NPC
    void addBattleItem(BattleItem* newBattleItem) {
        bool itemExists = false;
        for (unsigned i = 0; i < battleItems.size(); i++) {
            if (battleItems.at(i)->getName() == newBattleItem->getName()) {
                // Battle item exists, update quantity
                battleItems.at(i)->setQuantity(battleItems.at(i)->getQuantity() + newBattleItem->getQuantity());
                itemExists = true;
                break; // Exit loop once the item is found and updated
            }
        }
        
        if (!itemExists) {
            // Battle item doesn't exist, add new battle item
            battleItems.push_back(newBattleItem);
        }
    }

  Item* findItemByName(const string &itemName) {
    for (Item* item : items) {
        if (item->getName() == itemName) {
            return item;
        }
    }
    return nullptr; // Return nullptr if the item is not found
  }

  BattleItem* findBattleItemByName(const string &itemName) {
    for (BattleItem* item : battleItems) {
        if (item->getName() == itemName) {
            return item;
        }
    }
    return nullptr; // Return nullptr if the item is not found
  }

    void useItem(const string&, Mythikin&);
};