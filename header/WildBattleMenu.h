#pragma once

#include "WildBattle.h"
#include "BattleMenu.h"
#include "Menu.h"
#include "Player.h"
#include "NPC.h"
#include "Mythikin.h"


class WildBattleMenu : public BattleMenu {
  private:
    Player& mainChar;
    Mythikin& wildMythikin;
    PC& storedMythikin;
  public:
    WildBattleMenu(Player& mainChar, Mythikin& wildMythikin, PC& storedMythikin) : mainChar(mainChar), wildMythikin(wildMythikin), storedMythikin(storedMythikin) {  }
    void printMenu();
    void inventory(Player& mainChar, WildBattle& playerVsMythikin);
    void wildGameplay();
    void attackWild(WildBattle&, Player&, Mythikin&);
    void catchMythikin(WildBattle&, Mythikin&, PC&, Mythicube&);
    
};