#include "header/Mythishop.h"

vector<Item *> Mythishop::getStock() const
{
    return stock;
}

void Mythishop::addItem(Item *item)
{
    stock.push_back(item);
}

void Mythishop::removeItem(const string &itemName)
{
    for (int i = 0; i < stock.size(); ++i)
    {
        if (stock[i]->getName() == itemName)
        {
            delete stock[i];
            stock.erase(stock.begin() + i);
        }
    }
}

Item *Mythishop::getItem(int index) const
{
    return stock[index];
}