#include "../header/Player.h"
#include "../src/Team.cpp"
#include "gtest/gtest.h"


TEST(PlayerTestSuite, getNameTestDefaultConstructor) {
  Player defaultConstruct;
  EXPECT_EQ(defaultConstruct.getName(), "No Name");
}


TEST(PlayerTestSuite, getNameTestConstructorWithParam) {
  Mythikin testKin = Mythikin("TestKin", "TestType", 1, 20, 100);
  Team testTeam;
  testTeam.addMythikin(testKin);

  Location testLocation;

  vector<Item *> testInventory;

  Player testPlayer = Player("TestName", testLocation, testTeam, testInventory, 25);
  EXPECT_EQ(testPlayer.getName(), "TestName");
}


TEST(PlayerTestSuite, getTeamTest) {
  Mythikin testKin = Mythikin("TestKin", "TestType", 1, 20, 100);
  Team testTeam;
  testTeam.addMythikin(testKin);

  Location testLocation;

  vector<Item *> testInventory;

  Player testPlayer = Player("TestName", testLocation, testTeam, testInventory, 25);

  EXPECT_EQ(testPlayer.getTeam().getSlot(0).getName(), testKin.getName());
}

TEST(PlayerTestSuite, getInventoryTest) {
  Mythikin testKin = Mythikin("TestKin", "TestType", 1, 20, 100);
  Team testTeam;
  testTeam.addMythikin(testKin);

  Location testLocation;

  vector<Item *> testInventory;

  Player testPlayer = Player("TestName", testLocation, testTeam, testInventory, 25);

  EXPECT_EQ(testPlayer.getInventory(), testInventory);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}