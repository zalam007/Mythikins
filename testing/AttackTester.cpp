#include "../header/Attack.h"

#include "gtest/gtest.h"

//CONSTRUCTOR: Attack(string name, string type, int power, int accuracy, int MM)
TEST(Attack, attackGetName) {
    Attack fireBlast("HoofSpark", "magma", 15, 90, 10);
    EXPECT_EQ(fireBlast.getName(), "HoofSpark");
}

TEST(Attack, attackSetName) {
    Attack fireBlast("HoofSpark", "magma", 15, 90, 10);
    fireBlast.setName("FireBlast");
    EXPECT_EQ(fireBlast.getName(), "FireBlast");
}

TEST(Attack, attackGetType) {
    Attack fireBlast("HoofSpark", "magma", 15, 90, 10);
    EXPECT_EQ(fireBlast.getType(), "magma");
}

TEST(Attack, attackSetType) {
    Attack fireBlast("HoofSpark", "magma", 15, 90, 10);
    fireBlast.setType("fire");
    EXPECT_EQ(fireBlast.getType(), "fire");
}

TEST(Attack, attackGetPower) {
    Attack fireBlast("HoofSpark", "magma", 15, 90, 10);
    EXPECT_EQ(fireBlast.getPower(), 15);
}

TEST(Attack, attackSetPower) {
    Attack fireBlast("HoofSpark", "magma", 15, 90, 10);
    fireBlast.setPower(20);
    EXPECT_EQ(fireBlast.getPower(), 20);
}

TEST(Attack, attackGetAccuracy) {
    Attack fireBlast("HoofSpark", "magma", 15, 90, 10);
    EXPECT_EQ(fireBlast.getAccuracy(), 90);
}

TEST(Attack, attackSetAccuracy) {
    Attack fireBlast("HoofSpark", "magma", 15, 90, 10);
    fireBlast.setAccuracy(95);
    EXPECT_EQ(fireBlast.getAccuracy(), 95);
}

//MM tests

TEST(Attack, attackGetMaxMM) {
    Attack fireBlast("HoofSpark", "magma", 15, 90, 10);
    EXPECT_EQ(fireBlast.getMaxMM(), 10);
}

TEST(Attack, attackSetMaxMM) {
    Attack fireBlast("HoofSpark", "magma", 15, 90, 10);
    fireBlast.setMaxMM(15);
    EXPECT_EQ(fireBlast.getMaxMM(), 15);
}

TEST(Attack, attackGetMM) {
    Attack fireBlast("HoofSpark", "magma", 15, 90, 10);
    EXPECT_EQ(fireBlast.getMM(), 10);
}

TEST(Attack, attackSetMM) {
    Attack fireBlast("HoofSpark", "magma", 15, 90, 10);
    fireBlast.setMM(9);
    EXPECT_EQ(fireBlast.getMM(), 9);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}