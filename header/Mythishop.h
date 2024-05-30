#pragma once

#include "Location.h"
#include "Item.h"

class Mythishop : protected Location
{
private:
    vector<Item *> stock;

public:
    Mythishop(const string &name, const vector<Location *> &neighbors, const vector<Item *> stock) : Location(name, neighbors), stock(stock) {}

    Mythishop(const string &name, const vector<Location *> &neighbors, const vector<NPC> &npcs, const vector<Item *> stock) : Location(name, neighbors, npcs), stock(stock) {}

    vector<Item *> getStock() const;

    void addItem(Item *item);

    void removeItem(const string &itemName);

    Item *getItem(int index) const;
};