//
// Created by claxbot on 26/02/2021.
//

#include <climits>
#include <gtest/gtest.h>
#include "../src/Piece.h"

using namespace TP1;

TEST(Piece, Constructor) {
  Piece piece;
  EXPECT_EQ (piece.getParcourue(), false);
  EXPECT_EQ (piece.getDistanceDuDebut(), INT_MAX);
}

TEST(Piece, ConstructorUniqueName) {
  Piece piece1;
  Piece piece2;
  EXPECT_NE (piece1.getNom(), piece2.getNom());
}

TEST(Piece, ConstructorWithName) {
  const std::string name = "test";
  Piece piece(name);
  EXPECT_EQ (piece.getNom(), name);
}

TEST(Piece, ConstructorCopy) {
  const std::string name = "test";
  Piece piece1(name);
  piece1.setParcourue(true);
  piece1.setDistanceDuDebut(3);
  Piece piece2(piece1);
  EXPECT_EQ(piece1.getNom(), piece2.getNom());
  EXPECT_EQ(piece1.getDistanceDuDebut(), piece2.getDistanceDuDebut());
  EXPECT_EQ(piece1.getParcourue(), piece2.getParcourue());
  EXPECT_EQ(piece1.getPortes(), piece2.getPortes());
}

TEST(Piece, ConstructorCopyWithDeletedOriginal) {
  const std::string name = "test";
  Piece *piece1 = new Piece(name);
  piece1->setParcourue(true);
  piece1->setDistanceDuDebut(3);
  Piece piece2(*piece1);
  delete piece1;
  EXPECT_EQ(name, piece2.getNom());
  EXPECT_EQ(3, piece2.getDistanceDuDebut());
  EXPECT_EQ(true, piece2.getParcourue());
  EXPECT_EQ(0, piece2.getPortes().size());
}

TEST(Piece, ajoutePorte) {
  const std::string name = "test";
  Piece piece(name);
  Porte porte;
  piece.ajoutePorte(porte);
  EXPECT_EQ(1, piece.getPortes().size());
  EXPECT_EQ(piece.getPortes().front().getDestination(), nullptr);
  EXPECT_EQ(piece.getPortes().front().getCouleur(), Aucun);
}