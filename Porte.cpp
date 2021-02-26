/**
 * \file Porte.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Porte
 * \author Claire Bouttes
 * \version 0.1
 * \date février 2021
 *
 */

#include "Porte.h"
#include "Piece.h"

namespace TP1
{
    /**
     * \fn Porte::Porte()
     * \brief Constructeur par défault
     */
  Porte::Porte(): destination(nullptr), color(Aucun) { }

  /**
   * \fn Porte::Porte(Couleur c, Piece *d)
   * \brief Constructeur permettant de définir toutes les variables directement
   * @param c[Couleur]: Couleur du joueur pour lequelle cette porte appartient
   * @param d[Destination]: Pièce vers laquelle la porte permet d'aller
   */
  Porte::Porte(Couleur c, Piece *d): destination(d), color(c) { }

  /**
   * \fn Porte::Porte(const Porte &p)
   * \brief Constructeur de copy
   * @param p[Porte]: porte copiée
   */
  Porte::Porte(const Porte &p): destination(p.destination), color(p.color) {}

  /**
   * \fn Porte::~Porte()
   * \brief Destructeur par défault
   */
  Porte::~Porte() { };

  /**
   * \fn const Porte &Porte::operator=(const Porte &source)
   * \brief copie la destination et la couleur d'une porte vers notre porte
   * @param source: porte dont on copie les valeurs
   * @return la porte générée après la copie
   */
  const Porte &Porte::operator=(const Porte &source) {
    destination = source.destination;
    color = source.color;
    return (*this);
  }

  /**
   * \fn bool Porte::operator==(const Porte &source) const
   * \brief operateur de comparaison
   * @param source[Porte]: porte à comparer
   * @return true si la destination et la couleur et la même, faux autrement
   */
  bool Porte::operator==(const Porte &source) const {
    return (source.destination == destination && source.color == color);
  }

  /**
   * \fn Couleur Porte::getCouleur() const
   * @return la couleur de la porte
   */
  Couleur Porte::getCouleur() const { return color; }

  /**
   * \fn Piece *Porte::getDestination() const
   * @return la destination vers laquelle la porte mène
   */
  Piece *Porte::getDestination() const { return destination; }
}
