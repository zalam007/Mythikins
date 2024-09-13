#include <iostream>
#include "Menu.h"
#include "Mythicenter.h"
#include "Player.h"
#include "Team.h"

using namespace std;

class MythicenterMenu : public Menu
{
public:
    MythicenterMenu(Mythicenter* mythicenter, Player& patient) : mythicenter(mythicenter), patient(patient){} // Constructor

    void printMenu(); // User can heal mythikins, access PC, and leave.

    Player& getPatient() { return patient; }

    Mythicenter* getMythicenter() { return mythicenter; }

    void setMythicenter(Mythicenter* mythicenter) { this->mythicenter = mythicenter; }

private:

    Mythicenter* mythicenter;
    
    Player& patient;

    // Helper functions. Sub-menus of printMenu.
    void healMenu();

    void pcMenu();

    void PCDepositMenu();

    void PCWithdrawMenu();

};