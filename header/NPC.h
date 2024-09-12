#pragma once

#include <string>
#include <vector>
#include <cstdlib>
#include "Mythikin.h"
#include "Item.h"
#include "Character.h"
#include "map"
using namespace std;

class NPC : public Character { 
  private:
    vector<string> dialogue;
  public:
    NPC(string name = "No Name", Team team = Team(), vector<string> dialogue = vector<string>(), vector<BattleItem*> BattleItems = vector<BattleItem*>(), vector<Item*> items = vector<Item*>(), int mythicoins = 0) {
      Character::name = name;
      Character::team = team;
      Character::battleItems = battleItems;
      Character::items = items;
      Character::mythicoins = mythicoins;
      this->dialogue = dialogue;
    }

  ~NPC() {
    Character::battleItems.clear();
    Character::items.clear();
  }


    const string& talk(); //Changed this to return string, made more sense
    // void useItems(); TODO: Add later if time

    const vector<string>& getDialogue() {return dialogue;}

    void setDialogue(const vector<string>& newDialogue) {dialogue = newDialogue;}

    void addDialogue(const string& newDialogue) {dialogue.push_back(newDialogue);}
    
};

extern map<string, NPC*> npcs; //For later declaration in main.cpp