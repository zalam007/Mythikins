#include "../header/BattleMenu.h"
#include "../header/Potion.h"
#include "../header/Mythicube.h"


int main() {

  Attack fireBlast("Fire Blast", "fire", 100, 85, 5);
  Attack waterGun("Water Gun", "water", 40, 100, 25);
  Attack vineWhip("Vine Whip", "grass", 45, 100, 15);

    // Create two Mythikin creatures
  Mythikin charmander("Charmander", false, "fire", 5, 65, 200, 1.1);
  Mythikin bulbasaur("Bulbasaur", true, "grass", 5, 45, 220, 1.1);
  Mythikin squirtle("Squirtle", true, "water", 5, 45, 220, 1.1);

    // Add attacks to Mythikins
  charmander.addAttack(fireBlast);
  charmander.addAttack(vineWhip);

  bulbasaur.addAttack(waterGun);
  bulbasaur.addAttack(vineWhip);

  squirtle.addAttack(waterGun);


  Location testLocation = Location("Battle Test");
  Team playerTeam = Team();

  playerTeam.addMythikin(charmander);
  playerTeam.addMythikin(bulbasaur);
  vector<Item *> playerInventory;
  Item *potion = new Potion();
  Item *strongPotion = new Potion("Strong Potion", 1, 4, 50, 100);
  Item *mythicube = new Mythicube("Mythicube", 1, 4, 25, 80);

  Player mainChar = Player("Zami", testLocation, playerTeam, playerInventory, 25);
  mainChar.addItem(potion);
  mainChar.addItem(strongPotion);
  mainChar.addItem(mythicube);

  vector<string> dialogue;
  Team npcTeam = Team();
  npcTeam.addMythikin(squirtle);
  npcTeam.addMythikin(bulbasaur);

  NPC opp = NPC("Axel", npcTeam, dialogue, playerInventory, 20);

  BattleMenu battle = BattleMenu(mainChar, opp);
  battle.gameplay();
  
  

}




