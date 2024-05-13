#pragma once

#include <string>
#include <vector>
#include "./Location.h"
#include "../mythikin.h"
#include "./Item.h"
using std::string;

class Player {
  private:
    string name;
    Location currentLocation;
    vector<Item> items;
    int mythicoins;
  public:
    const string& getName() {return name;}
    const Location& getLocation() {return currentLocation;}
};