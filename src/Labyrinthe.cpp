/**
 * \file Labyrinthe.cpp
 * \brief Le code des méthodes membres et privés de la classe Labyrinthe.
 * \author IFT-2008, Étudiant(e)
 * \version 0.1
 * \date février 2021
 * 
 */

//Fichiers à compléter par les autres méthodes de la classe Labyrinthes demandées

#include <climits>
#include "Labyrinthe.h"

namespace TP1
{
 using namespace std;


// -------------------------------------------------------------------------------------------------
//	Méthodes fournies
// -------------------------------------------------------------------------------------------------

/**
 * \fn	void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
 * \param[in]	couleur, la couleur du jouer auquel le labyrinthe chargé s'applique
 * \param[in]	entree, fichier contenant la définition du labyrinthe
 */
void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
{
	int nbCols, nbRangs;

    if (!entree.is_open())
        throw logic_error("Labyrinthe::chargeLabyrinthe: Le fichier n'est pas ouvert !");

	entree >> nbCols >> nbRangs;
	entree.ignore(); //pour consommer le \n (le caractère fin de ligne)

	const int MAX_LIGNE = 1000;
	char ligne[MAX_LIGNE];

	entree.getline(ligne, MAX_LIGNE);
	entree.getline(ligne, MAX_LIGNE);

	std::ostringstream s; //Une chaîne pour écrire dedans, cette chaîne servira pour nommer les pièces du labyrinthe

	for (int i = 0; i < nbCols; i++)
	{
		for (int j = 0; j < nbRangs; j++)
		{
			s << i << "," << j;
			Piece p(s.str());
			s.str("");
			ajoutePieceLabyrinthe(p);
		}
	}

	for (int i = 0; i < nbCols; i++)
	{
		if (ligne[i * 4 + 1] == 'D' || ligne[i * 4 + 1] == 'd')
		{
			std::string nom;
			s << i << ",0";
			nom = s.str();
			s.str("");
			placeDepart(nom);
		}
		if (ligne[i * 4 + 1] == 'F' || ligne[i * 4 + 1] == 'f' || ligne[i * 4
				+ 1] == 'A' || ligne[i * 4 + 1] == 'a')
		{
			std::string nom;
			s << i << ",0";
			nom = s.str();
			s.str("");
			placeArrivee(nom);
		}
	}

	for (int j = 0; j < nbRangs; j++)
	{
		entree.getline(ligne, MAX_LIGNE);

		for (int i = (j == nbRangs - 1 && (j & 1)) ? 1 : 0; i < nbCols; i++)
		{
			if (j & 1)
			{
				if (j < nbRangs - 2 && ligne[i * 4 + 3] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 2);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 1);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
				{
					ajoutePassage(couleur, i - 1, j, i, j + 1);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'D' || ligne[i * 4
						+ 1] == 'd'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeDepart(nom);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'F' || ligne[i * 4
						+ 1] == 'f' || ligne[i * 4 + 1] == 'A' || ligne[i * 4
						+ 1] == 'a'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeArrivee(nom);
				}
			}
			else
			{
				if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
				{
					ajoutePassage(couleur, i - 1, j + 1, i, j);
				}
				if (j < nbRangs - 2 && ligne[i * 4 + 1] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 2);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 1);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'D' || ligne[i * 4
						+ 3] == 'd'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeDepart(nom);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'F' || ligne[i * 4
						+ 3] == 'f' || ligne[i * 4 + 3] == 'A' || ligne[i * 4
						+ 3] == 'a'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeArrivee(nom);
				}
			}
		}
	}
}


/**
 * \fn	Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
 * \param[in]	Couleur couleur Couleur de la porte à ajouter
 * \param[in]	int i1
 * \param[in]	int j1
 * \param[in]	int i2
 * \param[in]	int j2
 */
void Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
{

	NoeudListePieces *piece1, *piece2;
	string nomPiece1, nomPiece2;
	ostringstream s;

	s << i1 << "," << j1;
	nomPiece1 = s.str();

	s.str("");

	s << i2 << "," << j2;
	nomPiece2 = s.str();

	s.str("");

	piece1 = trouvePiece(nomPiece1);
	piece2 = trouvePiece(nomPiece2);

	Porte nouvellePorte(couleur, &(piece2->piece));

	piece1->piece.ajoutePorte(nouvellePorte);
}


/**
 * \fn	Labyrinthe::ajoutePieceLabyrinthe(Piece& p)
 * \brief ajoute une pièce au labyrinthe (si elle ne s'y trouve pas déjà)
 * \param[in]	p La pièce à ajouter
 * \post	la pièce appartient au labyrinthe;
 */
    void Labyrinthe::ajoutePieceLabyrinthe(const Piece& p) {
        Labyrinthe::NoeudListePieces* noeud = new Labyrinthe::NoeudListePieces;
        noeud->piece = p;

        if (dernier == 0)
        {
            noeud->suivant = noeud;
            dernier = noeud;
        }
        else if (!appartient(p)) {
            noeud->suivant = dernier->suivant;
            dernier->suivant = noeud;
        }
    }

    Labyrinthe::Labyrinthe(): dernier(nullptr), depart(nullptr), arrivee(nullptr) { }

    Labyrinthe::Labyrinthe(const Labyrinthe &source)
      : dernier(source.dernier), depart(source.depart), arrivee(source.arrivee) {}

    Labyrinthe::~Labyrinthe() {
      NoeudListePieces *av = nullptr;
      for (NoeudListePieces *tmp = dernier->suivant; tmp && tmp->piece.getNom() != dernier->piece.getNom(); tmp = tmp->suivant) {
        delete av;
        av = tmp;
      }
      delete dernier;
      dernier = nullptr;
    }

    const Labyrinthe &Labyrinthe::operator=(const Labyrinthe &source) {
      dernier = source.dernier;
      depart = source.depart;
      arrivee = source.arrivee;
      return *this;
    }

    std::vector<Piece*> Labyrinthe::getToutesPieces(const Piece *piece, Couleur couleur) {
      std::vector<Piece*> pieces;
      NoeudListePieces* tmp = dernier;

      for (const auto& porte : piece->getPortes())
        if (porte.getCouleur() == couleur) pieces.push_back(porte.getDestination());
      do {
        for (const auto& porte : tmp->piece.getPortes()) {
          if (porte.getCouleur() == couleur && porte.getDestination()->getNom() == piece->getNom())
            pieces.push_back(&tmp->piece);
        }
        tmp = tmp->suivant;
      } while (tmp && tmp->piece.getNom() != dernier->piece.getNom());
      return pieces;
    }

    void Labyrinthe::parcourtPorte(Piece *piece, const Couleur couleur) {
      piece->setParcourue(true);
      if (piece->getNom() == arrivee->getNom())
        return;

      for (const auto& p : getToutesPieces(piece, couleur)) {
        if (!p->getParcourue()) {
          if (piece->getDistanceDuDebut() + 1 < p->getDistanceDuDebut())
            p->setDistanceDuDebut((piece->getDistanceDuDebut() + 1));
          parcourtPorte(p, couleur);
        }
      }
    }

    void Labyrinthe::reinitialise() {
      NoeudListePieces* tmp = dernier;
      do {
        tmp->piece.setDistanceDuDebut(INT_MAX);
        tmp->piece.setParcourue(false);
        tmp = tmp->suivant;
      } while (tmp && tmp->piece.getNom() != dernier->piece.getNom());
    }

    int Labyrinthe::solutionner(Couleur joueur) {
      if (depart->getNom() == arrivee->getNom())
        return (resultats[joueur] = 0);
      reinitialise();
      depart->setDistanceDuDebut(0);
      parcourtPorte(depart, joueur);
      if (!arrivee->getParcourue())
        return (-1);
      resultats[joueur] = arrivee->getDistanceDuDebut();
      return resultats[joueur];
    }

    Couleur Labyrinthe::trouveGagnant() {
      std::pair<Couleur, int> meilleur(Aucun, INT_MAX);

      for (auto resultat : resultats)
        if (resultat.second < meilleur.second) meilleur = resultat;
      return meilleur.first;
    }

    bool Labyrinthe::appartient(const Piece &p) const {
      return trouvePiece(p.getNom()) != nullptr;
    }

    void Labyrinthe::placeDepart(const string &nom) {
      NoeudListePieces *noeud = trouvePiece(nom);

      if (!noeud)
        throw logic_error("La pièce de départ n'existe pas");
      depart = &noeud->piece;
    }

    void Labyrinthe::placeArrivee(const string &nom) {
      NoeudListePieces *noeud = trouvePiece(nom);

      if (!noeud)
        throw logic_error("La pièce d'arrivéé n'existe pas");
      arrivee = &noeud->piece;
    }

    Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(const string &nom) const {
      if (nom.empty())
        throw invalid_argument("Nom ne doit pas être vide");
      NoeudListePieces* tmp = dernier;

      do {
        if (tmp->piece.getNom() == nom)
          return tmp;
        tmp = tmp->suivant;
      } while (tmp && tmp->piece.getNom() != dernier->piece.getNom());
      return nullptr;
    }

}//fin du namespace
