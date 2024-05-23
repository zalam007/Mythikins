#pragma once

#include <string>
#include "../Mythikin.h"

using std::string;

class Team {
  private:
    static const int MAX_SIZE = 4; // Max size of the team
    Mythikin team[MAX_SIZE];  // Array to hold the team members
    int teamSize = 0;         // current size of the team
  public:
    int getSize() const { return teamSize; }    // Returns the current size of the team
    int getMaxSize() const { return MAX_SIZE; } 
    Mythikin& getSlot(int index); // Returns a reference to the Mythikin at the given index

    void swapSlots(int slot1, int slot2); // Swaps the Mythikins at the given indices

    void addMythikin(Mythikin newMember);     // Adds a new member to the team
    void removeMythikin(const string& name);  // Removes a member from the team by name
};