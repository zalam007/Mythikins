#include "../header/NPC.h"


const string& NPC::talk() { // Returns a random dialogue in the dialogue vector
  srand(5132024);
  return dialogue.at(rand() % dialogue.size()); // Returns a random string in vector
}

// void useItems() {
//   //Gonna need more deets on this
// }