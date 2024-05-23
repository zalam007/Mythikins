#pragma once

#include <string>
#include <vector>
#include <cstdlib>
#include "../mythikin.h"
#include "./Item.h"
#include "./Character.h"

using std::string;

class NPC : public Character { 
  private:
    vector<string> dialogue;
  public:
    NPC(string name = "No Name", Team team = Team(), vector<string> dialogue = vector<string>(), vector<Item*> items = vector<Item*>(), int mythicoins = 0) {
      Character::name = name;
      Character::team = team;
      Character::items = items;
      Character::mythicoins = mythicoins;
      this->dialogue = dialogue;
    }

    
    const string& talk(); //Changed this to return string, made more sense
    // void useItems(); TODO: Add later if time

    const vector<string>& getDialogue() {return dialogue;}


    void setDialogue(const vector<string>& newDialogue) {dialogue = newDialogue;}
    






};