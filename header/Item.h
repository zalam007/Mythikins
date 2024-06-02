#pragma once

#include <string>
#include "Mythikin.h"

using namespace std;

class Item
{
protected:
    string name;
    unsigned quantity;
    unsigned capacity;
    unsigned price;

public:
    // Constructor for Item
    Item(string name, unsigned quant, unsigned cap, unsigned price) : name(name), quantity(quant), capacity(cap), price(price)
    {
        // capacity can not be less that quanitity
        if (capacity < quantity)
        {
            capacity = quantity;
        }
    };

    // Accessor methods
    const string getName() const { return name; }

    const unsigned getQuantity() const { return quantity; }

    const unsigned getCapacity() const { return capacity; }

    const unsigned getPrice() const { return price; }

    // Mutator methods
    void setName(string newName) const { name = newName; }

    void setQuantity const(unsigned newQuant) { quantity = newQuant; }

    void setCapacity const(unsigned newCap)
    {
        if (newCap >= quantity)
        {
            capacity = newCap;
        }
    }

    void setPrice() const { price = newPrice; }

    virtual void use const(Mythikin &) = 0; // Special user of the item.
};