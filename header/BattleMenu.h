#pragma once

#include "Battle.h"
#include "Menu.h"
#include "Player.h"
#include "NPC.h"
#include "Mythikin.h"

class BattleMenu : public Menu {
  private:
    Player& mainChar;
    NPC& opponentNPC;
    bool playerActed = false; // help to check if player has acted before switching to opponent's turn
    bool playerWon = false; // help to check if player has won the battle
  public:
    BattleMenu() : mainChar(*(new Player())), opponentNPC(*(new NPC())) {}
    BattleMenu(Player& mainChar, NPC& opponentNPC);
    virtual ~BattleMenu(); //Don't ask why, it just fixes the compiler errors
    virtual void printMenu();
    void gameplay();;
    void attack(Battle&, Player&, NPC&);
    void inventory(Player&);
    void swap(Player&);
    bool getPlayerWon();
};