#include "../header/NPC.h"


const string& NPC::talk() { // Returns a random dialogue in the dialogue vector
  return dialogue.at(rand() % dialogue.size()); // Returns a random string in vector
}
