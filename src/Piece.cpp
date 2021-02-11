/**
 * \file Piece.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Piece
 * \author Étudiant(e)
 * \version 0.1
 * \date février 2021
 *
 */

#include <sstream>      // std::ostringstream
#include <iostream>
#include "Piece.h"

// Utils (should be in an utils file)

/**
 *
 * @return
 */
std::string getId() {
  static int n = 1;

  std::ostringstream id;
  id << n++;
  return id.str();
}

// End Utils

namespace TP1
{
  Piece::Piece(): portes(std::list<Porte>()), parcourue(false), nom(getId()), distanceDuDebut(0) { }

  Piece::Piece(const std::string &s): portes(std::list<Porte>()), parcourue(false), nom(s), distanceDuDebut(0) { }

  Piece::Piece(const Piece &source)
    : portes(source.getPortes()),
      parcourue(source.getParcourue()),
      nom(source.getNom()),
      distanceDuDebut(source.getDistanceDuDebut()) { }

  Piece::~Piece() {
    portes.clear(); // Not a necessity but clean stuff
  }

  const Piece &Piece::operator=(const Piece &source) {
    nom = source.getNom();
    portes = source.getPortes();
    parcourue = source.getParcourue();
    distanceDuDebut = source.getDistanceDuDebut();
    return *this;
  }

  std::string Piece::getNom() const { return nom; }

  const std::list<Porte> &Piece::getPortes() const { return portes; }

  bool Piece::getParcourue() const { return parcourue; }

  int Piece::getDistanceDuDebut() const { return distanceDuDebut; }

  void Piece::setParcourue(bool p) { parcourue = p; }

  void Piece::setDistanceDuDebut(int d) { distanceDuDebut = d; }

  void Piece::ajoutePorte(const Porte &p) {
    std::cout << "<Piece::ajoutePorte> Function called with: " << p.getDestination()->getNom() << "\tcolor: " << p.getCouleur() << std::endl;
    portes.push_back(p);
  }
}
