#include <iostream>
#include "Menu.h"
#include "Mythishop.h"
#include "Player.h"

using namespace std;

class ItemShopMenu : protected Menu
{
public:
    void printMenu(Mythishop &shop, Player &shopper);

private:
    void buyMenu(Mythishop &shop, Player &shopper);

    void sellMenu(Player &shopper);
};