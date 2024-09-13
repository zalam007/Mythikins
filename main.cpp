#include "header/WildBattleMenu.h"
#include "header/BattleMenu.h"
#include "header/GameplayMenu.h"
#include "header/Item.h"
#include "header/PC.h"
#include "header/Potion.h"
#include "header/Mythicube.h"
#include "header/Player.h"
#include "header/Character.h"
#include "header/NPC.h"
#include "header/Menu.h"
#include "header/Location.h"
#include "header/WildLocation.h"
#include "header/Mythicenter.h"
#include "header/Mythishop.h"
#include "header/Mythidex.h"
#include "header/CutsceneManager.h"
#include "header/ItemShopMenu.h"
#include "header/MythicenterMenu.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

bool playerLost(Player& player) { // checks if player lost a battle
    bool lost = true;
    for(int i = 0; i < player.getTeam().getSize(); i++) {
        if(!player.getTeam().getSlot(i).isKnocked()) {
            return false;
        }
    }
    return lost;
}

int main() {
/*
    // File Reading    
    Mythidex mythidex;

    //Setup Player
    Player player("DAJZ");
    player.setLocation(locations["Basement"]);

    // Game Tools
    GameplayMenu gameMenu(player, mythidex);
    CutsceneManager cutsceneManager(player);
    PC pc;
    ItemShopMenu itemShopMenu(nullptr, player);
    MythicenterMenu mythicenterMenu(nullptr, player);


    //Main Menu
    cutsceneManager.MainMenu();

    // Introduction
    string name = cutsceneManager.IntroDreamScene();
    cutsceneManager.IntroWakeUpScene(name);
    player.setName(name);

*/

///*
    // ***Temp Story Skip***
    string name = "DAJZ";
    Player player(name);
    Mythidex mythidex;
    PC pc;
    ItemShopMenu itemShopMenu(nullptr, player);
    MythicenterMenu mythicenterMenu(nullptr, player);

    player.setLocation(locations["Basement"]);

    GameplayMenu gameMenu(player, mythidex);
    CutsceneManager cutsceneManager(player);
//*/

    // Story Data (Prevent repeat cutscenes)
    bool HomeSceneDone, ProfAlderLabSceneDone = false;

    bool JexseeStopsPlayerSceneDone, JexseeLetsPlayerGoSceneDone = false;

    bool DunefallAcademySceneDone, OjadaAcademySceneDone, AvaloraBayAcademySceneDone = false;

    bool DunefallAcademyDone, OjadaAcademyDone, AvaloraBayAcademyDone = false;

    bool MythicTowerDone = false;

    Location* resetLocation; // For safety in case player loses

    // Ignore this! Just for testing
    // fast start
    player.addMythikin(*mythikins["Cindercoon"]);
    player.addMythikin(*mythikins["Cindercoon"]);
    player.addMythikin(*mythikins["Cindercoon"]);
    player.addMythikin(*mythikins["Cindercoon"]);
    locations["Oxvale"]->addNeighbor(*locations["Arid Crescent"]);
    player.setLocation(locations["Los Solara"]);


    // Playing the game
    while(true) {
        // Player Event: they lost a battle
        if(player.getTeam().getSize() > 0 && playerLost(player)) {
            chrono::seconds(1);
            cout << "You blacked out!" << endl;
            chrono::seconds(2);
            player.setLocation(resetLocation);
            for(int i = 0; i < player.getTeam().getSize(); i++) {
                player.getTeam().getSlot(i).setHP(player.getTeam().getSlot(i).getMaxHP());
            }

            cout << "You are back at " << player.getLocation()->getName() << "!" << endl;
        }

        // Player closest city
        if(player.getLocation() == locations["Oxvale"] || player.getLocation() == locations["Dunefall"] || 
            player.getLocation() == locations["Ojada"] || player.getLocation() == locations["Avalora Bay"] || 
            player.getLocation() == locations["Los Solara"] 
            && resetLocation != player.getLocation()){
            resetLocation = player.getLocation(); // most recent reset location
        }

        // Player controller
        gameMenu.printMenu();

        // Story Events
        if(!HomeSceneDone && (*player.getLocation()).getName() == "Home"){ // Mom moment
            cutsceneManager.HomeScene(name);
            HomeSceneDone = true;
        }
        
        if((*player.getLocation()).getName() == "The Gate of Sun and Shore"){ // The gate to Los Solara route (Endgame)
            if(!JexseeStopsPlayerSceneDone && (player.findItemByName("Liquid Medallion") == nullptr && player.findItemByName("Soil Medallion") == nullptr && (player.findItemByName("Ash Medallion") == nullptr))){ // You don't have all 3 Medallions
                cutsceneManager.JexseeStopsPlayerScene(name);
                JexseeStopsPlayerSceneDone = true;
            }

            if(!JexseeLetsPlayerGoSceneDone && (player.findItemByName("Liquid Medallion") != nullptr && player.findItemByName("Soil Medallion") != nullptr && (player.findItemByName("Ash Medallion") != nullptr))){ // You have all 3 Medallions
                cutsceneManager.JexseeLetsPlayerGoScene(name);
                JexseeLetsPlayerGoSceneDone = true;

                //Opens the endgame location. To Los Solara!
                locations["The Gate of Sun and Shore"]->addNeighbor(*locations["Vastblue Shore"]);
            }
        }

        if(!ProfAlderLabSceneDone && (*player.getLocation()).getName() == "Professor Alder's Lab"){ // You meet Professor Alder
            cutsceneManager.ProfessorAlderLabScene(name);
            for(int i = 0; i < 5; i++) {
                player.addItem(new Item(*items["Mythicube"]));
            }
           
            ProfAlderLabSceneDone = true;

            //Opens the world, the game finally begins!
            locations["Oxvale"]->addNeighbor(*locations["Arid Crescent"]);
            locations["Oxvale"]->addNeighbor(*locations["Santa Lilac Island"]);
            locations["Oxvale"]->addNeighbor(*locations["Arroyo Verde"]);
        }

        if((*player.getLocation()).getType() == "WildLocation"){ // Wild Location
            Location* location = player.getLocation();
            WildLocation* wildLocation = dynamic_cast<WildLocation*>(location);
            if (wildLocation != nullptr) {
                wildLocation->encounter(player, pc);
            }
        }

        if(player.getLocation()->getName().size() >= 7 && 
            player.getLocation()->getName().substr(player.getLocation()->getName().size() - 7) == "Academy") { // Academy

            if(player.getLocation()->getName() == "Dunefall Academy"){
                //cutscene
                if(!DunefallAcademySceneDone){
                    cutsceneManager.DunefallAcademyScene(name);
                    DunefallAcademySceneDone = true;
                }

                //Boss battle
                if(!DunefallAcademyDone){
                    BattleMenu trainerBattle(player, *locations["Dunefall Academy"]->getNPC("Ignatius Kael"));
                    trainerBattle.gameplay();

                    if(playerLost(player)){
                        for(int i = 0; i < (*locations["Dunefall Academy"]->getNPC("Ignatius Kael")).getTeam().getSize(); i++) {
                            player.getTeam().getSlot(i).setHP(player.getTeam().getSlot(i).getMaxHP());
                        }
                    }
                    else{
                        cutsceneManager.DunefallAcademyEndScene(name);
                        player.addItem(new Item(*items["Ash Medallion"])); // REWARD
                        DunefallAcademyDone = true;
                    }
                }
            }
            else if(player.getLocation()->getName() == "Ojada Academy"){
                //cutscene
                if(!OjadaAcademySceneDone){
                    cutsceneManager.OjadaAcademyScene(name);
                    OjadaAcademySceneDone = true;
                }

                //Boss battle
                if(!OjadaAcademyDone){
                    BattleMenu trainerBattle(player, *locations["Ojada Academy"]->getNPC("Sylvaine Marrowood"));
                    trainerBattle.gameplay();

                    if(playerLost(player)){
                        for(int i = 0; i < (*locations["Ojada Academy"]->getNPC("Sylvaine Marrowood")).getTeam().getSize(); i++) {
                            player.getTeam().getSlot(i).setHP(player.getTeam().getSlot(i).getMaxHP());
                        }
                    }
                    else{
                        cutsceneManager.OjadaAcademyEndScene(name);
                        player.addItem(new Item(*items["Soil Medallion"])); // REWARD
                        OjadaAcademyDone = true;
                    }
                }
            }
            else if(player.getLocation()->getName() == "Avalora Bay Academy"){
                //cutscene
                if(!AvaloraBayAcademySceneDone){
                    cutsceneManager.AvaloraBayAcademyScene(name);
                    AvaloraBayAcademySceneDone = true;
                }

                //Boss battle
                if(!AvaloraBayAcademyDone){
                    BattleMenu trainerBattle(player, *locations["Avalora Bay Academy"]->getNPC("Maris Tidecaller"));
                    trainerBattle.gameplay();

                    if(playerLost(player)){
                        for(int i = 0; i < (*locations["Avalora Bay Academy"]->getNPC("Maris Tidecaller")).getTeam().getSize(); i++) {
                            player.getTeam().getSlot(i).setHP(player.getTeam().getSlot(i).getMaxHP());
                        }
                    }
                    else{
                        cutsceneManager.AvaloraBayAcademyEndScene(name);
                        player.addItem(new Item(*items["Liquid Medallion"])); // REWARD
                        AvaloraBayAcademyDone = true;
                    }
                }
            }
        }

        if(player.getLocation()->getName() == "Mythikin Tower") { // Mythic Tower Battles
            if(!MythicTowerDone){
                // Fight Jax
                cutsceneManager.FightingJax(name);
                BattleMenu trainerBattle(player, *locations["Mythikin Tower"]->getNPC("Master Jax"));
                trainerBattle.gameplay();

                if(!playerLost(player)){ // Won Jax Battle
                    // Fight Dean
                    cutsceneManager.FightingDean(name);
                    BattleMenu trainerBattle(player, *locations["Mythikin Tower"]->getNPC("Master Dean"));
                    trainerBattle.gameplay();

                    if(!playerLost(player)){ // Won Dean Battle
                        // Fight Zane
                        cutsceneManager.FightingZane(name);
                        BattleMenu trainerBattle(player, *locations["Mythikin Tower"]->getNPC("Master Zane"));
                        trainerBattle.gameplay();

                        if(!playerLost(player)){ // Won Zane Battle
                            // Player wins the game
                            cout << "You have defeated the Mythikin Masters!" << endl;
                            cout << "You are now the Mythic Master!" << endl;
                            cout << "Thank you for playing!" << endl;
                            MythicTowerDone = true;
                        }
                        else{
                            (*locations["Mythikin Tower"]->getNPC("Master Jax")).resetTeamHP();
                            (*locations["Mythikin Tower"]->getNPC("Master Dean")).resetTeamHP();
                            (*locations["Mythikin Tower"]->getNPC("Master Zane")).resetTeamHP();
                        }
                    }
                    else {
                        (*locations["Mythikin Tower"]->getNPC("Master Jax")).resetTeamHP();
                        (*locations["Mythikin Tower"]->getNPC("Master Dean")).resetTeamHP();
                    }
                }
                else{
                    (*locations["Mythikin Tower"]->getNPC("Master Jax")).resetTeamHP();
                }
            }
        }

        if(player.getLocation()->getType() == "Mythicenter") { // Mythicenter
            Location* location = player.getLocation();
            Mythicenter* mythicenter = dynamic_cast<Mythicenter*>(location);

            mythicenter->changePC(pc);

            mythicenterMenu.setMythicenter(mythicenter);

            mythicenterMenu.printMenu();

            player.setLocation(resetLocation); // kick player out of mythicenter
        }

        if(player.getLocation()->getType() == "Mythishop") { // Mythishop
            Location* location = player.getLocation();
            Mythishop* mythishop = dynamic_cast<Mythishop*>(location);

            itemShopMenu.setShop(mythishop);  

            itemShopMenu.printMenu();

            player.setLocation(resetLocation); // kick player out of mythishop
        }
    }

  return 0;
}