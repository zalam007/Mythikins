#pragma once

#include "Battle.h"
#include "WildBattle.h"
#include "Menu.h"
#include "Player.h"
#include "NPC.h"
#include "Mythikin.h"

class BattleMenu : public Menu {
  private:
    Player mainChar;
    NPC opponentNPC;
    Mythikin wildMythikin;
  public:
    BattleMenu(Player& mainChar, NPC& opponentNPC);
    BattleMenu(Player& mainChar, Mythikin& wildMythikin);
    virtual ~BattleMenu(); //Don't ask why, it just fixes the compiler errors
    virtual void printMenu();
    void printWildBattleMenu();
    void attack(Battle&, Player&, NPC&);
    void inventory(Player&);
    void swap(Player&);
    void flee(WildBattle&);
};