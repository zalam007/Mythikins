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
    void setName(string newName) { name = newName; }

    void setQuantity(unsigned newQuant) { quantity = newQuant; }

    void setCapacity(unsigned newCap)
    {
        if (newCap >= quantity)
        {
            capacity = newCap;
        }
    }

    void setPrice(unsigned newPrice) { price = newPrice; }

    virtual void use(Mythikin &) = 0; // Special user of the item.
};