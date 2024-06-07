#include "../header/Team.h"
#include <stdexcept>

Mythikin& Team::getSlot(int index) {
  if (index < 0 || index > teamSize) //Bound checking, but hopefully not needed
  {
    throw runtime_error("Index out of bounds"); 
  }
  return team[index];
}

void Team::swapSlots(int slot1, int slot2) {
  if (slot1 < 0 || slot1 > teamSize || slot2 < 0 || slot2 > teamSize) {
    cerr << "Invalid swap: Index out of bounds." << endl;
    return;
  }

  // Perform swap
  Mythikin oldMythikin = team[slot1];
  team[slot1] = team[slot2];
  team[slot2] = oldMythikin;
}

void Team::addMythikin(Mythikin newMember) {
  if (teamSize == MAX_SIZE) throw runtime_error("Team Full"); //Check if full
  team[teamSize] = newMember;
  teamSize++;
}

void Team::removeMythikin(const string& name) {
  for (int i = 0; i < teamSize; i++) {
    if(team[i].getName() == name)
    {
      for (int j = i; j < teamSize - 1; j++) { // Deletes the element at i
        team[j] = team[j+1]; 
      }
      teamSize--;
    }
  }
  //Does nothing if name not found
}