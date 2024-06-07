#include "../src/Mythicube.cpp"
#include "../src/Potion.cpp"
#include "../header/Mythikin.h"

#include "gtest/gtest.h"

using namespace std;

TEST(ItemTests, testGetName) {
    Mythicube cube;
    EXPECT_EQ(cube.getName(), "Mythicube");
}

TEST(ItemTests, testSetName) {
    Mythicube cube;
    cube.setName("Magmasaur");
    EXPECT_EQ(cube.getName(), "Magmasaur");
}

TEST(ItemTests, testGetQuantity) {
    Mythicube cube;
    EXPECT_EQ(cube.getQuantity(), 1);
}

TEST(ItemTests, testSetQuantity) {
    Mythicube cube;
    cube.setQuantity(5);
    EXPECT_EQ(cube.getQuantity(), 5);
}


TEST(ItemTests, testGetCapacity) {
    Mythicube cube;
    EXPECT_EQ(cube.getCapacity(), 1);
}

TEST(ItemTests, testSetCapacity) {
    Mythicube cube;
    cube.setCapacity(5);
    EXPECT_EQ(cube.getCapacity(), 5);
}

TEST(ItemTests, testSetCapacityBelowQuantity) {
    Mythicube cube;
    cube.setQuantity(5);
    cube.setCapacity(2);
    EXPECT_EQ(cube.getCapacity(), 5);
}

TEST(ItemTests, testGetPrice) {
    Mythicube cube;
    EXPECT_EQ(cube.getPrice(), 100);
}

TEST(ItemTests, testSetPrice) {
    Mythicube cube;
    cube.setPrice(2000);
    EXPECT_EQ(cube.getPrice(), 2000);
}

TEST(MythicubeTests, testGetCatchRate) {
    Mythicube cube;
    EXPECT_EQ(cube.getCatchRate(), 1);
}

TEST(MythicubeTests, testSetCatchRate) {
    Mythicube cube;
    cube.setCatchRate(2);
    EXPECT_EQ(cube.getCatchRate(), 2);
}

TEST(MythicubeTests, testGetCapturedMythikin) {
    Mythicube cube;
    EXPECT_EQ(cube.getCapturedMythikin(), nullptr);
}

TEST(MythicubeTests, testSetEmptyMythicube) {
    Mythicube cube;
    cube.emptyMythicube();
    EXPECT_EQ(cube.getCapturedMythikin(), nullptr);
}

TEST(MythicubeTests, testUseFailedCatch) {
    Mythicube cube;
    Mythikin victim;
    cube.use(victim);
    EXPECT_EQ(cube.getCapturedMythikin(), nullptr);
}

TEST(MythicubeTests, testUseSuccessfulCatch) {
    Mythicube cube;
    Mythikin victim;
    victim.setHP(1);
    Mythikin *victimPointer = new Mythikin(victim);
    cube.use(victim);
    EXPECT_EQ(cube.getCapturedMythikin()->getName(), victimPointer->getName());
}

TEST(PotionTests, testGetHealPowerPercent) {
    Potion potion;
    EXPECT_EQ(potion.getHealPowerPercent(), 25);
}

TEST(PotionTests, testSetHealPowerPercent) {
    Potion potion;
    potion.setHealPowerPercent(50);
    EXPECT_DOUBLE_EQ(potion.getHealPowerPercent(), 50.0);
}

TEST(PotionTests, testUsePotion) {
    Potion potion;
    Mythikin patient;
    patient.setHP(1);
    potion.use(patient);
    EXPECT_EQ(patient.getHP(), 26);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}