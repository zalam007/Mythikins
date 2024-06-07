#include "../src/PC.cpp"
#include "../src/Player.cpp"
#include "../header/Mythikin.h"
#include "../src/Team.cpp"

#include "gtest/gtest.h"

using namespace std;

TEST(PCTests, testGetPCListAndPlaceMythikinToPC)
{
    PC pc;
    Mythikin mythikin;
    pc.placeMythikinToPC(mythikin);
    EXPECT_EQ(pc.getPCList()[0]->getName(), "Default-Munchikin");
}

TEST(PCTests, testWithdrawWentIntoTeam)
{
    PC pc;
    Mythikin mythikin;
    Player player;
    pc.placeMythikinToPC(mythikin);
    pc.withdrawMythikin("Default-Munchikin", player.getTeam());
    EXPECT_EQ(player.getTeam().getSlot(0).getName(), "Default-Munchikin");
}

TEST(PCTests, testWithdrawRemovedFromPC)
{
    PC pc;
    Mythikin mythikinOne;
    Mythikin mythikinTwo("Zamikin", false, "flora", 1, 1, 1, 1);
    Player player;
    pc.placeMythikinToPC(mythikinOne);
    pc.placeMythikinToPC(mythikinTwo);
    pc.withdrawMythikin("Zamikin", player.getTeam());
    bool isFound = false;
    for(int i = 0; i < pc.getPCList().size(); i++){
        if(pc.getPCList()[i]->getName() == "Zamikin"){
            isFound = true;
        }
    }
    EXPECT_FALSE(isFound);
}

TEST(PCTests, testDepositWentIntoTeam)
{
    PC pc;
    Mythikin mythikin;
    Mythikin mythikin2;
    Player player;
    player.getTeam().addMythikin(mythikin);
    player.getTeam().addMythikin(mythikin2);
    pc.depositMythikin(player.getTeam().getSlot(0), player.getTeam());
    EXPECT_EQ(pc.getPCList()[0]->getName(), "Default-Munchikin");
}

TEST(PCTests, testDepositRemovedFromTeam)
{
    PC pc;
    Mythikin mythikin;
    Mythikin mythikinTwo("Zamikin", false, "flora", 1, 1, 1, 1);
    Player player;
    player.getTeam().addMythikin(mythikin);
    player.getTeam().addMythikin(mythikinTwo);
    pc.depositMythikin(player.getTeam().getSlot(1), player.getTeam());

    bool isFound = false;
    for(int i = 0; i < player.getTeam().getSize(); i++){
        if(player.getTeam().getSlot(0).getName() == "Zamikin"){
            isFound = true;
        }
    }
    EXPECT_FALSE(isFound);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}