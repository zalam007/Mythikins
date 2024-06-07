#include "../header/Battle.h"
#include "../header/Mythikin.h"
#include "../header/Attack.h"
#include "../header/Team.h"

#include "gtest/gtest.h"

// Test stageAttack method
TEST(BattleTest, StageAttack) {
    Team playerTeam;
    Team npcTeam;
    //string name, string type, int level, int speed, int HP
    Mythikin attacker("Attacker", "magma", 10, 100, 100);
    Mythikin defender("Defender", "magma", 10, 100, 100);
    //string name, string type, int power, int accuracy, int MM
    Attack move("Fireball", "magma", 50, 100, 10);
    Battle battle(playerTeam, npcTeam);

    battle.stageAttack(attacker, defender, move);
    EXPECT_EQ(defender.getHP(), 50); // Defender should have less HP after the attack
}

// Test AIAttack method
TEST(BattleTest, AIAttack) {
    // Create player Mythikins
    //string name, string type, int level, int speed, int HP
    Mythikin player1("FireDragon", false, "fire", 10, 30, 100, 1);

    // Create NPC Mythikins
    Mythikin npc1("GrassBeast", true, "grass", 9, 28, 95, 1.15);
    //string name, string type, int power, int accuracy, int MM
    npc1.addAttack(Attack("VineWhip", "grass", 35, 100, 10));
    npc1.addAttack(Attack("LeafStorm", "grass", 45, 100, 5));

    Mythikin npc2("RockGolem", true, "rock", 7, 20, 110, 1.0);
    npc2.addAttack(Attack("RockThrow", "rock", 40, 100, 10));
    npc2.addAttack(Attack("StoneEdge", "rock", 50, 100, 5));

    // Create teams
    Team playerTeam;
    playerTeam.addMythikin(player1);

    Team npcTeam;
    npcTeam.addMythikin(npc1);
    npcTeam.addMythikin(npc2);

    // Start the battle
    Battle battle(playerTeam, npcTeam);

    battle.AIAttack(npc1, player1);
    EXPECT_LT(player1.getHP(), 100); // Player should have less HP after the attack
}

// Test swapSlots method
TEST(BattleTest, SwapSlots) {
    Team playerTeam;
    Team npcTeam;
    Mythikin mythikin1("Mythikin1", "fire", 10, 100, 100);
    Mythikin mythikin2("Mythikin2", "water", 10, 100, 100);
    playerTeam.addMythikin(mythikin1);
    playerTeam.addMythikin(mythikin2);
    Battle battle(playerTeam, npcTeam);

    battle.swapSlots(0, 1);
    EXPECT_EQ(playerTeam.getSlot(0).getName(), "Mythikin2");
    EXPECT_EQ(playerTeam.getSlot(1).getName(), "Mythikin1");
}

// Test isOver method
TEST(BattleTest, IsOver) {
    Team playerTeam;
    Team npcTeam;
    Battle battle(playerTeam, npcTeam);

    EXPECT_TRUE(battle.isOver()); // Battle should be over if no Mythikins are added to the teams
}

// Test ifWon method
TEST(BattleTest, IfWon) {
    Team playerTeam;
    Team npcTeam;
    Mythikin playerMythikin("Player", "fire", 10, 100, 100);
    playerTeam.addMythikin(playerMythikin);
    Battle battle(playerTeam, npcTeam);

    EXPECT_TRUE(battle.ifWon()); // Player should win if NPC team has no Mythikins
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}