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
#include <climits>
#include "Piece.h"

// Utils (should be in an utils file)

/**
 * Simple function qui génère un id unique
 * @return un id unique
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
    /**
     * \fn Piece::Piece()
     * \brief Constructeur par défault
     */
  Piece::Piece()
    : portes(std::list<Porte>()),
      parcourue(false),
      nom(getId()),
      distanceDuDebut(INT_MAX) { }

    /**
     * \fn Piece::Piece(const std::string& s)
     * \brief Constructeur qui permet de set le nom
     * \param[string] s: nom de la pièce à créer
     */
  Piece::Piece(const std::string& s)
    : portes(std::list<Porte>()),
      parcourue(false),
      nom(s),
      distanceDuDebut(INT_MAX) { }

  /**
   * \fn Piece::Piece(const Piece &source)
   * \brief Constructeur de copy
   * @param source
   */
  Piece::Piece(const Piece &source)
    : portes(source.getPortes()),
      parcourue(source.getParcourue()),
      nom(source.getNom()),
      distanceDuDebut(source.getDistanceDuDebut()) { }

      /**
       * \fn Piece::~Piece()
       * \brief Destructeur par défault
       */
  Piece::~Piece() {
    portes.clear(); // Not a necessity but clean stuff
  }

  /**
   * \fn const Piece &Piece::operator=(const Piece &source)
   * \brief Copie l'intégralité des données de la source (le nom aussi)
   * @param source[Piece] Pièce à copier
   * @return La pièce copier
   */
  const Piece &Piece::operator=(const Piece &source) {
    nom = source.getNom();
    portes = source.getPortes();
    parcourue = source.getParcourue();
    distanceDuDebut = source.getDistanceDuDebut();
    return (*this);
  }

  /**
   * \fn std::string Piece::getNom() const
   * @return Le nom de la pièce
   */
  std::string Piece::getNom() const { return nom; }

  /**
   * \fn const std::list<Porte> &Piece::getPortes() const
   * @return toutes les portes de la pièces
   */
  const std::list<Porte> &Piece::getPortes() const { return portes; }

  /**
   * \fn bool Piece::getParcourue() const
   * @return le booléan si la pièce a été parcourue ou non
   */
  bool Piece::getParcourue() const { return parcourue; }

  /**
   * \fn int Piece::getDistanceDuDebut() const
   * @return la distance depuis le début
   */
  int Piece::getDistanceDuDebut() const { return distanceDuDebut; }

  /**
   * \fn void Piece::setParcourue(bool p)
   * @param p[bool]: nouvelle valeur parcourue
   */
  void Piece::setParcourue(bool p) { parcourue = p; }

  /**
   * \fn void Piece::setDistanceDuDebut(int d)
   * @param d[int]: nouvelle valeur pour la distance depuis le début
   */
  void Piece::setDistanceDuDebut(int d) { distanceDuDebut = d; }

  /**
   * \fn void Piece::ajoutePorte(const Porte &p)
   * \brief Ajoute une porte qui relie cette pièce vers une autre pièce
   * @param p[Porte]: porte à ajouter
   */
  void Piece::ajoutePorte(const Porte &p) { portes.push_back(p); }
}
