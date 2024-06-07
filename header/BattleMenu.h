#pragma once

#include "Battle.h"
#include "Menu.h"
#include "Player.h"
#include "NPC.h"
#include "Mythikin.h"

class BattleMenu : public Menu {
  private:
    Player mainChar;
    NPC opponentNPC;
  public:
    BattleMenu() {}
    BattleMenu(Player& mainChar, NPC& opponentNPC);
    virtual ~BattleMenu(); //Don't ask why, it just fixes the compiler errors
    virtual void printMenu();
    void gameplay();;
    void attack(Battle&, Player&, NPC&);
    void inventory(Player&);
    void swap(Player&);
};