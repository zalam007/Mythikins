#pragma once
#include <string>
#include <iostream>
#include <map>
#include "Player.h"
#include "BattleItem.h"
using namespace std;

class CutsceneManager
{
    private:
        string continueBTN;
        Player& player;

    public:
        CutsceneManager(Player& player) : player(player){}

        void pressAnyKey(string& continueBTN);

        void MainMenu();

        // Main Story Scenes

        string IntroDreamScene();

        void IntroWakeUpScene(string& name);

        void HomeScene(string& name);

        void ProfessorAlderLabScene(string& name);

        // Academies scenes

        void DunefallAcademyScene(string& name);

        void DunefallAcademyEndScene(string& name);

        void OjadaAcademyScene(string& name);

        void OjadaAcademyEndScene(string& name);

        void AvaloraBayAcademyScene(string& name);

        void AvaloraBayAcademyEndScene(string& name);

        // Mythic Tower Scenes
        void FightingJax(string& name);

        void FightingDean(string& name);

        void FightingZane(string& name);

        // Side Scenes

        void JexseeStopsPlayerScene(string& name);

        void JexseeLetsPlayerGoScene(string& name);
};