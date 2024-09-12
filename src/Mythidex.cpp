#include "../header/Mythidex.h"
#include "../header/Mythicenter.h"
#include "../header/Mythishop.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Mythidex::Mythidex() {
    readMoves("GameData/Moves.txt");
    readMythikin("GameData/Mythikins.txt");
    readItems("GameData/Items.txt");
    readLocations("GameData/Locations.txt");
    readNPCs("GameData/NPCs.txt");
}

map<string, Location*> locations;
void Mythidex::readLocations(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') {
            continue; // Skip empty lines and comments
        }

        stringstream ss(line);
        string type, name, neighbors, additionalData; // Add mythikins for wild locations
        getline(ss, type, ';');
        getline(ss, name, ';');
        getline(ss, neighbors, ';');
        getline(ss, additionalData, ';');  // More data for WildLocations/MythiShops

        Location* location = nullptr;  // Base location pointer

        // Check if the location already exists, if not create it
        if (locations.find(name) == locations.end()) {
            if (type == "w") {  // WildLocation
                WildLocation* wildLocation = new WildLocation(name);

                // Process additionalData for WildLocation
                stringstream additionalStream(additionalData);
                string mythikinList, spawnRateStr;

                getline(additionalStream, mythikinList, ';');
                getline(additionalStream, spawnRateStr, ';');

                // Parse and add Mythikins
                if (!mythikinList.empty()) {
                    stringstream mythikinStream(mythikinList);
                    string mythikinName;
                    while (getline(mythikinStream, mythikinName, ',')) {
                        if (!mythikinName.empty()) {
                            auto mythikinIt = mythikins.find(mythikinName);
                            if (mythikinIt != mythikins.end()) {
                                auto mythikinCopy = make_unique<Mythikin>(*(mythikinIt->second));
                                mythikinCopy->setWild(true);
                                wildLocation->addMythikin(*mythikinCopy);
                            } else {
                                cerr << "Mythikin " << mythikinName << " not found!" << endl;
                            }
                        }
                    }
                }

                if (!spawnRateStr.empty()) {
                    wildLocation->setSpawnRate(stoi(spawnRateStr));
                }

                location = wildLocation;
            }
            else if(type == "mc"){ // Mythicenter
                Mythicenter* mythicenter = new Mythicenter(name);
                location = mythicenter;
            }
            else if(type == "ms"){ // Mythishop
                Mythishop* mythishop = new Mythishop(name);

                // Process additionalData for WildLocation
                stringstream additionalStream(additionalData);
                string ItemList;

                getline(additionalStream, ItemList, ';');

                // Parse and add Mythikins
                if (!ItemList.empty()) {
                    stringstream ItemStream(ItemList);
                    string ItemName;
                    while (getline(ItemStream, ItemName, ',')) {
                        if (!ItemName.empty()) {
                            mythishop->addItem(items[ItemName]);
                        }
                    }
                }
                location = mythishop;
            } 
            else {  // Regular Location
                location = new Location(name);
            }

            locations[name] = location;  // Add to the locations map
        } 
        else {
            location = locations[name];  // Retrieve the existing location
        }

        // Parse and link neighbors
        stringstream neighborStream(neighbors);
        string neighborName;
        while (getline(neighborStream, neighborName, ',')) {
            if (!neighborName.empty()) {
                Location* neighborLocation;
                if (locations.find(neighborName) == locations.end()) {
                    neighborLocation = new Location(neighborName);
                    locations[neighborName] = neighborLocation;
                } else {
                    neighborLocation = locations[neighborName];
                }

                // Add the neighbor to the location
                location->addNeighbor(*neighborLocation);
            }
        }
    }

    file.close();
}


map<string, Item*> items;
void Mythidex::readItems(const string& filename) 
{
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') {
            continue; // Skip empty lines and comments
        }

        stringstream ss(line);
        string name, quantity, capacity, price, power;
        getline(ss, name, '|');
        getline(ss, quantity, '|');
        getline(ss, capacity, '|');
        getline(ss, price, '|');
        getline(ss, power, ';');

        if (!name.empty()) {
            // Create a new battle item depending on the name
            Item* item;
            if(power.empty()) {
                item = new Item(name, stoi(quantity), stoi(capacity), stoi(price));
            }
            else if(name == "Mythicube") {
                item = new Mythicube(name, stoi(quantity), stoi(capacity), stoi(price), stof(power));
            } 
            else if(name == "Potion") {
                item = new Potion(name, stoi(quantity), stoi(capacity), stoi(price), stof(power));
            }
            else {
                cerr << "Unknown battle item type: " << name << endl;
            }

            items[name] = item;
        }
    }

    file.close();
}

map<string, NPC*> npcs;
void Mythidex::readNPCs(const string& filename) 
{
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') {
            continue; // Skip empty lines and comments
        }

        stringstream ss(line);
        string name, team, dialogue, battleItemsName, itemsName, mythicoins, location, isBattler;
        getline(ss, name, ';');
        getline(ss, team, ';');
        getline(ss, dialogue, ';');
        getline(ss, battleItemsName, ';');
        getline(ss, itemsName, ';');
        getline(ss, mythicoins, ';');
        getline(ss, location, ';');
        getline(ss, isBattler, ';');

        // Create a new NPC with the given name
        NPC* npc = new NPC(name);

        // Parse Team (Mythikins)
        stringstream teamStream(team);
        string mythikinName;
        while (getline(teamStream, mythikinName, ',')) {
            if (!mythikinName.empty()) {
                // Find the Mythikin in the global mythikins map
                if (mythikins.find(mythikinName) != mythikins.end()) {
                    // Create a new copy of the Mythikin and add it to the NPC's team
                    Mythikin* mythikinCopy = new Mythikin(*mythikins[mythikinName]);
                    npc->addMythikin(*mythikinCopy);  // Add the copied Mythikin to the NPC
                } else {
                    cerr << "Mythikin " << mythikinName << " not found in the map!" << endl;
                }
            }
        }

        // Parse Dialogues
        stringstream dialogueStream(dialogue);
        string text;
        while (getline(dialogueStream, text, ',')) {
            if (!text.empty()) {
                npc->addDialogue(text);
            }
        }

        // Parse Battle Items
        stringstream battleItemStream(battleItemsName);
        string battleItem;

        while (getline(battleItemStream, battleItem, ',')) {
            stringstream itemStream(battleItem);
            //string itemName;
            if (!battleItem.empty()) {
                // Add existing battleItem to the NPC's battle items
                npc->addBattleItem(static_cast<BattleItem*>(items[battleItem]));
            }
        }

        // Parse Items
        stringstream itemStream(itemsName);
        string item;
        while (getline(itemStream, item, ',')) {
            stringstream itemDetailStream(item);
            if (!item.empty()) {
                // Add existing item to the NPC's battle items
                npc->addItem(static_cast<Item*>(items[item]));
            }
        }

        // Parse and add Mythicoins
        npc->addCoins(stoi(mythicoins));

        // Add the NPC to the global NPC map
        npcs[name] = npc;

        // Parse Location and add NPC to the location
        if (locations.find(location) != locations.end()) {
            if(isBattler == "true") {
                WildLocation* wildLocation = dynamic_cast<WildLocation*>(locations[location]);
                wildLocation->addBattler(*npcs[name]); // Add NPC to the location's Battler list
            }
            else if(isBattler == "false") {
                locations[location]->addNPC(npcs[name]); // Add NPC to the location's NPC list
            }
            else{
                cerr << "NPC " << name << " is unknown if its a battler!" << endl;
            }
            
        } else {
            cerr << "Location " << location << " not found!" << endl;
        }
    }

    file.close();
}

//Read the Mythikins from the file and add them to the allMythikins vector
map<string, Mythikin*> mythikins;
void Mythidex::readMythikin(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') {
            continue; // Skip empty lines and comments
        }

        stringstream ss(line);
        string name, type, level, speed, HP, moves;
        getline(ss, name, ';');
        getline(ss, type, ';');
        getline(ss, level, ';');
        getline(ss, speed, ';');
        getline(ss, HP, ';');
        getline(ss, moves, ';');

        if (!name.empty()) {
            // Create a new Mythikin depending on the name
            Mythikin* mythikin = new Mythikin(name, false, type, stoi(level), stoi(speed), stoi(HP));

            // Parse and add moves
            stringstream moveStream(moves);
            string moveName;
            while (getline(moveStream, moveName, ',')) {
                if (!moveName.empty()) {
                    // Find the move in the global moves map
                    if (attacks.find(moveName) != attacks.end()) {
                        // Create a new copy of the move and add it to the Mythikin's moves
                        Attack* moveCopy = new Attack(*attacks[moveName]);
                        mythikin->addAttack(*moveCopy);  // Add the copied move to the Mythikin
                    } else {
                        cerr << "Move " << moveName << " not found in the map!" << endl;
                    }
                }
            }

            mythikins[name] = mythikin;
        }
    }

    file.close();
}

map<string, Attack*> attacks;
//Read the moves from the file and add them to the allMoves vector
void Mythidex::readMoves(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') {
            continue; // Skip empty lines and comments
        }

        stringstream ss(line);
        string name, type, power, accuracy, MM;
        getline(ss, name, ';');
        getline(ss, type, ';');
        getline(ss, power, ';');
        getline(ss, accuracy, ';');
        getline(ss, MM, ';');

        if (!name.empty()) {
            // Create a new move depending on the name
            Attack* move = new Attack(name, type, stoi(power), stoi(accuracy), stoi(MM));
            attacks[name] = move;
        }
    }

    file.close();
}

//Print Data

void Mythidex::printAllMythikinNames() const 
{
    int i = 0;
    for (auto& mythikin : mythikins) {
        i++;
        cout << i << " - " << mythikin.second->getName() << " ("  << mythikin.second->getType() << ")" << endl;
    }
}

void Mythidex::printAllMoveNames() const {
    int i = 0;
    for (auto& attack : attacks) {
        i++;
        cout << i << " - " << attack.second->getName() << " ("  << attack.second->getType() << ")" << endl;
    }
}