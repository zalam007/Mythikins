#include <string>
#include "Mythikin.h"

#pragma once

using namespace std;

class Item
{
protected:
    string name;
    int quantity;
    int capacity;

public:
    Item(string name, int quant, int cap) : name(name), quantity(quant), capacity(cap){};

    // Accessor methods
    string getName() const { return name; }

    int getQuantity() const { return quantity; }
    
    int getCapacity() const { return capacity; }

    // Mutator methods
    void nameItem(string newName) { name = newName; }

    void changeQuantity(int newQuant)
    {
        if (newQuant >= 0)
        {
            quantity = newQuant;
        }
    }

    void changeCapacity(int newCap)
    {
        if (newCap >= quantity && newCap >= 0)
        {
            capacity = newCap;
        }
    }

    virtual void use(Mythikin &) = 0;
};