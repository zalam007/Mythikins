#include <iostream>
#include "Mythikin.h"
#include "Attack.h"
using namespace std;

int main() {
  // string name, bool wild, string type, int level, int speed, int HP, double attackX
  Mythikin Blazehoof("Blazehoof", false, "fire", 1, 90, 100, 1);
  cout << Blazehoof.getName() << endl; // Output: Blazehoof
  return 0;
}