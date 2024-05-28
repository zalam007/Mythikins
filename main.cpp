#include <iostream>
#include "Battle.h" // includes Mythikin.h & Attack.h
#include "Mythidex.h" //
#include "header/Player.h"
using namespace std;

string askForName() {
  string name;
  string confirm;
  while (true) {
    cout << "Please enter your name: ";
    getline(cin, name);
    cout << "You're name is " << name << ". Is this correct? (yes/no): ";
    getline(cin, confirm);
    if (confirm == "yes") { break; }
  }
  cout << "Welcome, " << name << "!\n";
  return name;
}

int main() {

  // Create Mythidex, Read Mythikins & Moves from files
  Mythidex mythidex;
  mythidex.readMythikinsFromFile("mythikins.txt");
  mythidex.readMovesFromFile("moves.txt");

  string playerName = askForName(); // get player's name
  
  Location home("Home"); 

  Player player(playerName, home); // create player

  if(player.getLocation().getName() == "Home") {
    cout << "Mom: Honey, it's time we talk about your… 'extended vacation' at home" << endl;
    cout << player.getName() << ": What about it, Mom? I’m just taking a break from the hustle and bustle of life. " << endl;
    cout << "Mom: Well, that ‘break' has turned into a decade, and the only thing hustling is the fridge door every time you're hungry." << endl;
    cout << player.getName() << ": I'm in deep thought, planning my next big move!" << endl;
    cout << "Mom: The only 'move' I've seen is you moving from the couch to your bed. It's time to find a job!" << endl; 
    cout << "Mom: You're already 30 years old, but all you do is play Valorant, Tekken, and watch looksmaxxing edits on TikTok!!!" << endl;
    cout << "Mom: You should be more like your younger brother Jesse. Jesse's only 18, but he already has a 6-figure job as a software developer at Mythicorp and the sharpest jawline known to man." << endl;
    cout << player.getName() << ": I'll show you mummy!!! I'll defeat the Mythikin Masters become the greatest Mythikin trainer like I always dreamed of when I was younger!!" << endl;
    cout << "Mom: While you're at it, maybe train one to do interviews. Off you go, champ!" << endl;
  }


  return 0;
}