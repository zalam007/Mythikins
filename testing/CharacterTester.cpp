#include "../header/Character.h"


#include "gtest/gtest.h"

TEST(CharacterTesting, getNameTest) {
  Character testChar;
  testChar.setName("Bob");
  EXPECT_EQ(testChar.getName(), "Bob");
}

TEST(CharacterTesting, CoinTestAdd) {
  Character testChar;
  testChar.addCoins(25);
  EXPECT_EQ(testChar.getCoins(), 25);
}

TEST(CharacterTesting, CoinTestRemove) {
  Character testChar;
  testChar.addCoins(50);
  testChar.removeCoins(25);
  EXPECT_EQ(testChar.getCoins(), 25);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}