//
// Created by claxbot on 11/02/2021.
//

#include "Labyrinthe.h"
#include "gtest/gtest.h"

using namespace TP1;

TEST(Labyrinthe, Constructor) {
  Labyrinthe lab;
  EXPECT_EQ (lab.getDepart(), nullptr);
  EXPECT_EQ (lab.getArrivee(), nullptr);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}