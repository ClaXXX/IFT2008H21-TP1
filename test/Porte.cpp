//
// Created by claxbot on 26/02/2021.
//

#include "../src/Porte.h"
#include "gtest/gtest.h"
#include "../src/Piece.h"

using namespace TP1;

TEST(Porte, Constructor) {
  Porte porte;
  EXPECT_EQ(porte.getCouleur(), Aucun);
  EXPECT_EQ(porte.getDestination(), nullptr);
}

TEST(Porte, ConstructorWithVariable) {
  Piece piece;
  Porte porte(Vert, &piece);
  EXPECT_EQ(porte.getCouleur(), Vert);
  EXPECT_EQ(porte.getDestination(), &piece);
}

TEST(Porte, ConstructorCopy) {
  Piece piece;
  Porte *porte1 = new Porte(Vert, &piece);
  Porte porte(*porte1);
  delete porte1;
  EXPECT_EQ(porte.getCouleur(), Vert);
  EXPECT_EQ(porte.getDestination(), &piece);
}

TEST(Porte, OperatorEqual) {
  Piece piece;
  Porte *porte1 = new Porte(Vert, &piece);
  Porte porte = *porte1;
  delete porte1;
  EXPECT_EQ(porte.getCouleur(), Vert);
  EXPECT_EQ(porte.getDestination(), &piece);
}