//
// Created by claxbot on 11/02/2021.
//

#include <ios>
#include "../src/Labyrinthe.h"
#include "gtest/gtest.h"

using namespace TP1;

TEST(Labyrinthe, Constructor) {
  Labyrinthe lab;
  EXPECT_EQ (lab.getDepart(), nullptr);
  EXPECT_EQ (lab.getArrivee(), nullptr);
}

TEST(Labyrinthe, Lab2x3) {
  const std::string size = "2x3";
  Labyrinthe lab;
  std::ifstream entree;
  entree.open("../../data/Lab" + size + "/rouge" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Rouge, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/bleu" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Bleu, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/vert" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Vert, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/jaune" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Jaune, entree);
  entree.close();
  EXPECT_EQ(lab.solutionner(Rouge), 2);
  EXPECT_EQ(lab.solutionner(Bleu), 3);
  EXPECT_EQ(lab.solutionner(Vert), 4);
  EXPECT_EQ(lab.solutionner(Jaune), -1);
  EXPECT_EQ(lab.trouveGagnant(), Rouge);
}

TEST(Labyrinthe, Lab8x8) {
  const std::string size = "8x8";
  Labyrinthe lab;
  std::ifstream entree;
  entree.open("../../data/Lab" + size + "/rouge" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Rouge, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/bleu" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Bleu, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/vert" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Vert, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/jaune" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Jaune, entree);
  entree.close();
  EXPECT_EQ(lab.solutionner(Rouge), 23);
  EXPECT_EQ(lab.solutionner(Bleu), 44);
  EXPECT_EQ(lab.solutionner(Vert), 31);
  EXPECT_EQ(lab.solutionner(Jaune), 22);
  EXPECT_EQ(lab.trouveGagnant(), Jaune);
}

TEST(Labyrinthe, Lab10x10) {
  const std::string size = "10x10";
  Labyrinthe lab;
  std::ifstream entree;
  entree.open("../../data/Lab" + size + "/rouge" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Rouge, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/bleu" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Bleu, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/vert" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Vert, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/jaune" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Jaune, entree);
  entree.close();
  EXPECT_EQ(lab.solutionner(Rouge), 53);
  EXPECT_EQ(lab.solutionner(Bleu), 17);
  EXPECT_EQ(lab.solutionner(Vert), 43);
  EXPECT_EQ(lab.solutionner(Jaune), 45);
  EXPECT_EQ(lab.trouveGagnant(), Bleu);
}

TEST(Labyrinthe, Lab10x14) {
  const std::string size = "10x14";
  Labyrinthe lab;
  std::ifstream entree;
  entree.open("../../data/Lab" + size + "/rouge" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Rouge, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/bleu" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Bleu, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/vert" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Vert, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/jaune" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Jaune, entree);
  entree.close();
  EXPECT_EQ(lab.solutionner(Rouge), 51);
  EXPECT_EQ(lab.solutionner(Bleu), 76);
  EXPECT_EQ(lab.solutionner(Vert), 48);
  EXPECT_EQ(lab.solutionner(Jaune), 54);
  EXPECT_EQ(lab.trouveGagnant(), Vert);
}
TEST(Labyrinthe, Lab14x14) {
  const std::string size = "14x14";
  Labyrinthe lab;
  std::ifstream entree;
  entree.open("../../data/Lab" + size + "/rouge" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Rouge, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/bleu" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Bleu, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/vert" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Vert, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/jaune" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Jaune, entree);
  entree.close();
  EXPECT_EQ(lab.solutionner(Rouge), 95);
  EXPECT_EQ(lab.solutionner(Bleu), 72);
  EXPECT_EQ(lab.solutionner(Vert), 85);
  EXPECT_EQ(lab.solutionner(Jaune), 104);
  EXPECT_EQ(lab.trouveGagnant(), Bleu);
}
TEST(Labyrinthe, Lab20x20) {
  const std::string size = "20x20";
  Labyrinthe lab;
  std::ifstream entree;
  entree.open("../../data/Lab" + size + "/rouge" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Rouge, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/bleu" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Bleu, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/vert" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Vert, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/jaune" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Jaune, entree);
  entree.close();
  EXPECT_EQ(lab.solutionner(Rouge), 120);
  EXPECT_EQ(lab.solutionner(Bleu), 106);
  EXPECT_EQ(lab.solutionner(Vert), 171);
  EXPECT_EQ(lab.solutionner(Jaune), 180);
  EXPECT_EQ(lab.trouveGagnant(), Bleu);
}
TEST(Labyrinthe, Lab35x50) {
  const std::string size = "35x50";
  Labyrinthe lab;
  std::ifstream entree;
  entree.open("../../data/Lab" + size + "/rouge" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Rouge, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/bleu" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Bleu, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/vert" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Vert, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/jaune" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Jaune, entree);
  entree.close();
  EXPECT_EQ(lab.solutionner(Rouge), 568);
  EXPECT_EQ(lab.solutionner(Bleu), 418);
  EXPECT_EQ(lab.solutionner(Vert), 528);
  EXPECT_EQ(lab.solutionner(Jaune), 756);
  EXPECT_EQ(lab.trouveGagnant(), Bleu);
}
TEST(Labyrinthe, Lab50x65) {
  const std::string size = "50x65";
  Labyrinthe lab;
  std::ifstream entree;
  entree.open("../../data/Lab" + size + "/rouge" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Rouge, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/bleu" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Bleu, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/vert" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Vert, entree);
  entree.close();
  entree.open("../../data/Lab" + size + "/jaune" + size + ".txt", std::ios::in);
  lab.chargeLabyrinthe(Jaune, entree);
  entree.close();
  EXPECT_EQ(lab.solutionner(Rouge), 913);
  EXPECT_EQ(lab.solutionner(Bleu), 1211);
  EXPECT_EQ(lab.solutionner(Vert), 1228);
  EXPECT_EQ(lab.solutionner(Jaune), 904);
  EXPECT_EQ(lab.trouveGagnant(), Jaune);
}