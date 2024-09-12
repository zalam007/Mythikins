#pragma once
#include <iostream>
#include "Menu.h"
#include "Location.h"
#include "Player.h"
#include "Mythidex.h"

class GameplayMenu : protected Menu
{
public:
    GameplayMenu(Player& mainCharacter, Mythidex& mythidex);
    void printMenu();

private:
    Player& mainCharacter;
    Mythidex& mythidex;
    void printLocations();
    void goTo(Location *destination);
    void viewInventory();
    void viewMythidex() const;
    void viewTeam();
    void viewNPCs();
    
};