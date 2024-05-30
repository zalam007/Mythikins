#pragma once

#include <string>
#include "../Mythikin.h"

using std::string;

class Team {
  private:
    static const int MAX_SIZE = 4;
    Mythikin team[MAX_SIZE];
    int teamSize = 0;
  public:
    int getSize() const { return teamSize; }
    int getMaxSize() const { return MAX_SIZE; }
    Mythikin& getSlot(int index);

    void swapSlots(int slot1, int slot2);

    void addMythikin(Mythikin newMember);
    void removeMythikin(const string& name);

    

};