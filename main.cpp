#include <iostream>
#include "Mythikin.h"
#include "Attack.h"
#include "Mythidex.cpp"
using namespace std;

int main() {

    Mythidex dex;

    // Read Mythikins from file
    dex.readMythikinsFromFile("mythikins.txt");

    dex.printAllMythikinNames();

  return 0;
}