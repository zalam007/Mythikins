#include "../header/Mythidex.h"
#include "../header/Mythikin.h"
#include "../header/Attack.h"

#include "gtest/gtest.h"

TEST(Mythidex, DefaultConstructor) {
    Mythidex mythidex;
    EXPECT_TRUE(mythidex.getAllMythikins().empty());
    EXPECT_TRUE(mythidex.getAllMoves().empty());
}

TEST(Mythidex, ReadMythikinsFromFile) {
    Mythidex mythidex;
    mythidex.readMythikinsFromFile("txt/mythikins.txt");
    ASSERT_FALSE(mythidex.getAllMythikins().empty());
}

TEST(Mythidex, ReadMythikinsFromFileNumber) {
    Mythidex mythidex;
    mythidex.readMythikinsFromFile("txt/mythikins.txt");
    EXPECT_EQ(mythidex.getAllMythikins().size(), 19);   // Currently 19 moves
}

TEST(Mythidex, ReadMovesFromFile) {
    Mythidex myMythidex;
    myMythidex.readMovesFromFile("txt/moves.txt");
    ASSERT_FALSE(myMythidex.getAllMoves().empty());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}