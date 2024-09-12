#include <iostream>
#include "Menu.h"
#include "Mythishop.h"
#include "Player.h"

using namespace std;

class ItemShopMenu : public Menu
{
public:
    ItemShopMenu(Mythishop* shop, Player &shopper) : shop(shop), shopper(shopper) {} // Constructor

    void printMenu(); // Main menu for item shop. User can sell or buy items.

    void setShop(Mythishop* newShop){ shop = newShop;} // Set the shop for the menu.

    Mythishop* getShop(){ return shop;} // Get the shop for the menu.

    Player& getShopper(){ return shopper;} // Get the shopper for the menu.

private:
    Mythishop* shop;
    Player &shopper;

    // Helper functions. Sub-menus of printMenu.
    void buyMenu(Mythishop &shop, Player &shopper);

    void sellMenu(Player &shopper);
};