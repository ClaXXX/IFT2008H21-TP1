/**
 * \file Porte.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Porte
 * \author Claire Bouttes
 * \version 0.1
 * \date février 2021
 *
 */

#include "Porte.h"

namespace TP1
{
  Porte::Porte(): destination(nullptr), color(Aucun) { }

  Porte::Porte(Couleur c, Piece *d): destination(d), color(c) { }

  Porte::Porte(const Porte &p): destination(p.destination), color(p.color) { }

  Porte::~Porte() { }

  const Porte &Porte::operator=(const Porte &source) {
    destination = source.destination;
    color = source.color;
    return *this;
  }

  bool Porte::operator==(const Porte &source) const {
    return (source.getDestination() == destination && source.getCouleur() == color);
  }

  Couleur Porte::getCouleur() const { return color; }

  Piece *Porte::getDestination() const { return destination; }
}
