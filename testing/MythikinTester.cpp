#include "../header/Mythikin.h"
#include "../header/Attack.h"

#include "gtest/gtest.h"

TEST(Mythikin, mythikinGetName) {
    Mythikin Blazehoof("Blazehoof", false, "magma", 1, 50, 100, 1);
    EXPECT_EQ(Blazehoof.getName(), "Blazehoof");
}

TEST(Mythikin, mythikinSetName) {
    Mythikin newMythikin;
    newMythikin.setName("Blazehoof");
    EXPECT_EQ(newMythikin.getName(), "Blazehoof");
}

TEST(Mythikin, mythikinIsWild) {
    Mythikin Blazehoof("Blazehoof", false, "magma", 1, 50, 100, 1);
    EXPECT_EQ(Blazehoof.isWild(), false);
}

TEST(Mythikin, mythikinSetWild) {
    Mythikin newMythikin;
    newMythikin.setWild(true);
    EXPECT_EQ(newMythikin.isWild(), true);
}

TEST(Mythikin, mythikinGetType) {
    Mythikin Blazehoof("Blazehoof", false, "magma", 1, 50, 100, 1);
    EXPECT_EQ(Blazehoof.getType(), "magma");
}

TEST(Mythikin, mythikinSetType) {
    Mythikin newMythikin;
    newMythikin.setType("magma");
    EXPECT_EQ(newMythikin.getType(), "magma");
}

TEST(Mythikin, mythikinGetLevel) {
    Mythikin Blazehoof("Blazehoof", false, "magma", 1, 50, 100, 1);
    EXPECT_EQ(Blazehoof.getLevel(), 1);
}

TEST(Mythikin, mythikinSetLevel) {
    Mythikin newMythikin;
    newMythikin.setLevel(2);
    EXPECT_EQ(newMythikin.getLevel(), 2);
}

TEST(Mythikin, mythikinGetSpeed) {
    Mythikin Blazehoof("Blazehoof", false, "magma", 1, 50, 100, 1);
    EXPECT_EQ(Blazehoof.getSpeed(), 50);
}

TEST(Mythikin, mythikinSetSpeed) {
    Mythikin newMythikin;
    newMythikin.setSpeed(60);
    EXPECT_EQ(newMythikin.getSpeed(), 60);
}

TEST(Mythikin, mythikinGetHP) {
    Mythikin Blazehoof("Blazehoof", false, "magma", 1, 50, 100, 1);
    EXPECT_EQ(Blazehoof.getHP(), 100);
}

TEST(Mythikin, mythikinSetHP) {
    Mythikin newMythikin;
    newMythikin.setHP(90);
    EXPECT_EQ(newMythikin.getHP(), 90);
}

TEST(Mythikin, mythikinSetHPMaxHPNotChanged) {
    Mythikin Blazehoof("Blazehoof", false, "magma", 1, 50, 100, 1);
    Blazehoof.setHP(90);
    EXPECT_EQ(Blazehoof.getMaxHP(), 100);
}

TEST(Mythikin, mythikinGetMaxHP) {
    Mythikin Blazehoof("Blazehoof", false, "magma", 1, 50, 100, 1);
    EXPECT_EQ(Blazehoof.getMaxHP(), 100);
}

TEST(Mythikin, mythikinSetMaxHP) {
    Mythikin newMythikin;
    newMythikin.setMaxHP(110);
    EXPECT_EQ(newMythikin.getMaxHP(), 110);
}

TEST(Mythikin, mythikinIsKnocked) {
    Mythikin Blazehoof("Blazehoof", false, "magma", 1, 50, 100, 1);
    EXPECT_EQ(Blazehoof.isKnocked(), false);
}

TEST(Mythikin, mythikinGetAttackX) {
    Mythikin Blazehoof("Blazehoof", false, "magma", 1, 50, 100, 1.1);
    EXPECT_EQ(Blazehoof.getAttackX(), 1.1);
}

TEST(Mythikin, mythikinSetAttackX) {
    Mythikin newMythikin;
    newMythikin.setAttackX(1.2);
    EXPECT_EQ(newMythikin.getAttackX(), 1.2);
}

TEST(Mythikin, mythikinAttacks) {
    Mythikin Blazehoof("Blazehoof", false, "magma", 1, 50, 100, 1);
    Attack hoofSpark("HoofSpark", "magma", 15, 90, 10);
    Attack flameCharge("FlameCharge", "magma", 20, 80, 15);
    Blazehoof.addAttack(hoofSpark);
    Blazehoof.addAttack(flameCharge);
    vector<Attack> attacks = Blazehoof.getAttacks();
    EXPECT_EQ(attacks.size(), 2);
    EXPECT_EQ(attacks[0].getName(), "HoofSpark");
    EXPECT_EQ(attacks[1].getName(), "FlameCharge");
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}