#include "../header/BattleMenu.h"
#include "../header/WildBattleMenu.h"
#include "../header/PC.h"
#include "../header/Potion.h"
#include "../header/PC.h"
#include "../header/Mythicube.h"

#include "gtest/gtest.h"

// Test isOver method
TEST(WildBattleTest, IsOver) {
    Mythikin player1("FireDragon", false, "fire", 10, 30, 100, 1.2);
    Team playerTeam;
    playerTeam.addMythikin(player1);
    Mythikin wildMythikin("Wildkin", "fire", 10, 100, 100);
    WildBattle wildBattle(playerTeam, wildMythikin);

    EXPECT_FALSE(wildBattle.isOver()); // Battle should not be over if wild Mythikin is not caught or knocked out
}

// Test ifWon method. 
// True if isOver is true and the player has at least one Mythikin alive or caught the wild Mythikin
TEST(WildBattleTest, IfWon) {
    Team playerTeam;
    Mythikin wildMythikin("Wild", "fire", 10, 100, 100);
    WildBattle wildBattle(playerTeam, wildMythikin);

    EXPECT_FALSE(wildBattle.ifWon()); // Player should not win if wild Mythikin is not caught
}

// Test that the player wins when the wild Mythikin is caught
TEST(WildBattleTest, IfWon_WildCaught) {
    Team playerTeam;
    Mythikin wildMythikin("Wild", "fire", 10, 100, 100);
    WildBattle wildBattle(playerTeam, wildMythikin);
    PC playerPC;
    Mythicube myMythicube;

    // Assume some condition that makes catching possible, ex: wildMythikin's health is low
    wildMythikin.setHP(1);
    wildBattle.catchMythikin(playerPC, myMythicube); // Catching should succeed

    EXPECT_TRUE(wildBattle.ifWon()); // Player should win
}

// Test catchMythikin method
TEST(WildBattleTest, CatchMythikin) {
    Team playerTeam;
    Mythikin wildMythikin("Wild", "fire", 10, 100, 100);
    WildBattle wildBattle(playerTeam, wildMythikin);
    PC playerPC;
    Mythicube myMythicube;

    EXPECT_FALSE(wildBattle.catchMythikin(playerPC, myMythicube)); // Catching should fail initially
}

// Test that a wild Mythikin can be caught when conditions are right
TEST(WildBattleTest, CatchMythikin_Success) {
    Team playerTeam;
    Mythikin wildMythikin("Wild", "fire", 10, 100, 100);
    WildBattle wildBattle(playerTeam, wildMythikin);
    PC playerPC;
    Mythicube myMythicube;

    // Assume some condition that makes catching possible, e.g., wildMythikin's health is low
    wildMythikin.setHP(1);

    EXPECT_TRUE(wildBattle.catchMythikin(playerPC, myMythicube)); // Catching should succeed
}

// Test Flee method
TEST(WildBattleTest, Flee) {
    Team playerTeam;
    Mythikin wildMythikin("Wild", "fire", 10, 100, 100);
    WildBattle wildBattle(playerTeam, wildMythikin);

    // Fleeing is random can't assert a specific outcome
    EXPECT_NO_FATAL_FAILURE(wildBattle.Flee());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}