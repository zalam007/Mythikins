#include <iostream>
#include "Menu.h"
#include "Mythishop.h"
#include "Player.h"

using namespace std;

class ItemShopMenu : protected Menu
{
public:
    ItemShopMenu(Mythishop &shop, Player &shopper); // Constructor

    void printMenu(); // Main menu for item shop. User can sell or buy items.

private:
    // Helper functions. Sub-menus of printMenu.

    void buyMenu(Mythishop &shop, Player &shopper);

    void sellMenu(Player &shopper);
};