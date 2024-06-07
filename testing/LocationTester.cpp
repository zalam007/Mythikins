#include "gtest/gtest.h"
#include "../header/Location.h"
#include "../src/Location.cpp"

TEST(LocationsTest, testGetName) {
    Location village("village");
    EXPECT_EQ(village.getName(), "village");
}

TEST(LocationsTest, testGetNeighbors) {
    Location village("village");
    Location* forest = new Location("forest");
    village.addLocation(forest);
    EXPECT_EQ(village.getNeighbors()[0]->getName(), "forest");
}

TEST(LocationsTest, testGetNPCList) {
    Location village("village");
    NPC villager("Jesse");
    village.addNPC(villager);
    EXPECT_EQ(village.getNPCList()[0].getName(), "Jesse");
}

TEST(LocationsTest, testSetName) {
    Location village("village");
    village.setName("Forest");
    EXPECT_EQ(village.getName(), "Forest");
}

TEST(LocationsTest, testAddNPC) {
    Location village("village");
    NPC villager("Axel");
    village.addNPC(villager);
    EXPECT_EQ(village.getNPCList()[0].getName(), "Axel");
}

TEST(LocationsTest, testRemoveNPC) {
    Location village("village");
    NPC villager("Axel");
    village.addNPC(villager);
    village.removeNPC("Axel");
    EXPECT_EQ(village.getNPCList().size(), 0);
}

TEST(LocationsTest, testAddLocation) {
    Location village("village");
    Location* forest = new Location("Mythilab");
    village.addLocation(forest);
    EXPECT_EQ(village.getNeighbors()[0]->getName(), "Mythilab");
}

TEST(LocationsTest, testRemoveLocation) {
    Location village("village");
    Location* forest = new Location("Mythilab");
    village.addLocation(forest);
    village.removeLocation("Mythilab");
    EXPECT_EQ(village.getNeighbors().size(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
