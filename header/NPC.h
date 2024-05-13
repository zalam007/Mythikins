#pragma once

#include <string>
#include <vector>
#include "../mythikin.h"
#include "./Item.h"
#include <cstdlib>

using std::string;

class NPC {
  private:
    string name;
    vector<Mythikin> team;
    vector<string> dialogue;
    vector<Item> items;
  public:
    NPC(string name, vector<Mythikin> team, vector<string> dialogue, vector<Item> items) : name(name), team(team), dialogue(dialogue), items(items) { }
    NPC() : name("No Name") {}
    
    const string& talk(); //Changed this to return string, made more sense
    void useItems();

    string getName() {return name;}
    const vector<Mythikin>& getTeam() {return team;}
    const vector<string>& getDialogue() {return dialogue;}
    const vector<Item>& getItems() {return items;}

    void setName(const string& newName) {name = newName;}
    void setTeam(const vector<Mythikin>& newTeam) {team = newTeam;}
    void setDialogue(const vector<string>& newDialogue) {dialogue = newDialogue;}
    void setItems(const vector<Item> newItems) {items = newItems;}







};