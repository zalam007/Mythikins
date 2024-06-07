#include "gtest/gtest.h"
#include "../header/Location.h"
#include "../src/Location.cpp"
#include "../src/WildLocation.cpp"
#include "../src/Mythishop.cpp"
#include "../src/Mythicenter.cpp"

TEST(LocationsTests, testGetName) {
    Location village("village");
    EXPECT_EQ(village.getName(), "village");
}

TEST(LocationsTests, testGetNeighbors) {
    Location village("village");
    Location* forest = new Location("forest");
    village.addLocation(forest);
    EXPECT_EQ(village.getNeighbors()[0]->getName(), "forest");
}

TEST(LocationsTests, testGetNPCList) {
    Location village("village");
    NPC villager("Jesse");
    village.addNPC(villager);
    EXPECT_EQ(village.getNPCList()[0].getName(), "Jesse");
}

TEST(LocationsTests, testSetName) {
    Location village("village");
    village.setName("Forest");
    EXPECT_EQ(village.getName(), "Forest");
}

TEST(LocationsTests, testAddNPC) {
    Location village("village");
    NPC villager("Axel");
    village.addNPC(villager);
    EXPECT_EQ(village.getNPCList()[0].getName(), "Axel");
}

TEST(LocationsTests, testRemoveNPC) {
    Location village("village");
    NPC villager("Axel");
    village.addNPC(villager);
    village.removeNPC("Axel");
    EXPECT_EQ(village.getNPCList().size(), 0);
}

TEST(LocationsTests, testAddLocation) {
    Location village("village");
    Location* forest = new Location("Mythilab");
    village.addLocation(forest);
    EXPECT_EQ(village.getNeighbors()[0]->getName(), "Mythilab");
}

TEST(LocationsTests, testRemoveLocation) {
    Location village("village");
    Location* forest = new Location("Mythilab");
    village.addLocation(forest);
    village.removeLocation("Mythilab");
    EXPECT_EQ(village.getNeighbors().size(), 0);
}

TEST(WildLocationTests, testGetSpawnRate) {
    WildLocation forest("Forest");
    forest.setSpawnRate(25);
    EXPECT_EQ(forest.getSpawnRate(), 25);
}

TEST(WildLocationTests, testGetMythikinSpawn) {
    WildLocation forest("Forest");
     Mythikin Blazehoof("Cindercoon", false, "magma", 1, 50, 100, 1);
    forest.addMythikin(Blazehoof);
    EXPECT_EQ(forest.getMythikinSpawn()[0].getName(), "Cindercoon");
}

TEST(WildLocationTests, testSetSpawnRate) {
    WildLocation forest("Forest");
    forest.setSpawnRate(50);
    EXPECT_EQ(forest.getSpawnRate(), 50);
}

TEST(WildLocationTests, testAddMythikin) {
    WildLocation forest("Forest");
     Mythikin Blazehoof("Blazehoof", false, "magma", 1, 50, 100, 1);
    forest.addMythikin(Blazehoof);
    EXPECT_EQ(forest.getMythikinSpawn()[0].getName(), "Blazehoof");
}

TEST(WildLocationTests, testRemoveMythikin) {
    WildLocation forest("Forest");
     Mythikin Blazehoof("Blazehoof", false, "magma", 1, 50, 100, 1);
    forest.addMythikin(Blazehoof);
    forest.removeMythikin("Blazehoof");
    EXPECT_EQ(forest.getMythikinSpawn().size(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
