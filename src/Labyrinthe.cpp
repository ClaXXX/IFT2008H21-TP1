/**
 * \file Labyrinthe.cpp
 * \brief Le code des méthodes membres et privés de la classe Labyrinthe.
 * \author IFT-2008, Claire Bouttes
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

/**!
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
      if (dernier == nullptr)
        return;
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

    /**
     * \fn std::vector<Piece*> Labyrinthe::getToutesPieces(const Piece *piece, Couleur couleur)
     * \brief Cherche toutes les pièces qui sont accessibles depuis une piece pour une couleur
     * \param piece: piece depuis laquelle on cherche les portes
     * \param couleur: couleur de porte acceptée
     * \return un tableau (std::vector<Piece*>) de pointeur sur les pièces accessibles et non visitées
     */
    std::vector<Piece*> Labyrinthe::getToutesPieces(const Piece *piece, Couleur couleur) {
      std::vector<Piece*> pieces;
      NoeudListePieces* tmp = dernier;

      for (const auto& porte : piece->getPortes())
        if (porte.getCouleur() == couleur && !porte.getDestination()->getParcourue()) {
          pieces.push_back(porte.getDestination());
          porte.getDestination()->setParcourue(true);
        }
      do {
        for (const auto& porte : tmp->piece.getPortes()) {
          if (porte.getCouleur() == couleur && porte.getDestination()->getNom() == piece->getNom()
            && !tmp->piece.getParcourue()) {
            pieces.push_back(&tmp->piece);
            tmp->piece.setParcourue(true);
          }
        }
        tmp = tmp->suivant;
      } while (tmp && tmp->piece.getNom() != dernier->piece.getNom());
      return pieces;
    }

    /**
     * \fn void Labyrinthe::parcourtPorte(Piece *piece, const Couleur couleur)
     * \brief Function récursive qui parcourt pour une porte toutes les pièces auquelles elle peut accéder et informe de la distance depuis le début
     * \param piece: pièce dont on va tester toutes les portes
     * \param couleur: Couleur du joueur à tester
     */
    void Labyrinthe::parcourtPorte(Piece *piece, const Couleur couleur) {
      if (piece->getNom() == arrivee->getNom())
        return;

      for (auto p : getToutesPieces(piece, couleur)) {
        if (piece->getDistanceDuDebut() + 1 < p->getDistanceDuDebut()) {
          p->setDistanceDuDebut((piece->getDistanceDuDebut() + 1));
        }
        parcourtPorte(p, couleur);
      }
    }

    /**
     * \fn void Labyrinthe::reinitialise()
     * \brief Reinitialise toutes les pièces comme non parcourues et avec une distance presque infinie
     */
    void Labyrinthe::reinitialise() {
      NoeudListePieces* tmp = dernier;
      do {
        tmp->piece.setDistanceDuDebut(INT_MAX);
        tmp->piece.setParcourue(false);
        tmp = tmp->suivant;
      } while (tmp && tmp->piece.getNom() != dernier->piece.getNom());
    }

    /**
     * \fn int Labyrinthe::solutionner(Couleur joueur)
     * \brief Pour une couleur, calcul une distance pour allé à l'arrivée
     * \param[Couleur] joueur: Couleur du joueur testé
     * \return la distance parcourue pour arrivée à la sortie du labyrinthe
     * \post Le labyrinthe doit déjà avoir été chargé pour la couleur demandée
     */
    int Labyrinthe::solutionner(Couleur joueur) {
      if (depart->getNom() == arrivee->getNom())
        return (0);
      reinitialise();
      depart->setDistanceDuDebut(0);
      parcourtPorte(depart, joueur);
      if (!arrivee->getParcourue())
        return (-1);
      return arrivee->getDistanceDuDebut();
    }

    /**
     * \fn Couleur Labyrinthe::trouveGagnant()
     * \brief Trouve le gagnant parmi l'énumération des couleurs donc rouge, vert, bleue, jaune
     * \return le joueur qui a réussi à parcourrir le moins de chemin, en cas d'Ex aequo retourne le premier dans l'énumération à avoir réussi
     * \post Le labyrinthe doit déjà avoir été chargé pour toutes les couleurs
     */
    Couleur Labyrinthe::trouveGagnant() {
      std::pair<Couleur, int> meilleur(Aucun, INT_MAX);
      std::map<Couleur, int> resultats;

      for (int i = Rouge; i < Aucun; i++)
        resultats[(Couleur )i] = solutionner((Couleur )i);

      for (int i = Rouge; i < Aucun; i++)
        if (resultats.at((Couleur )i) != -1 && resultats.at((Couleur )i) < meilleur.second)
          meilleur = std::pair<Couleur, int>((Couleur )i, resultats.at((Couleur)i));
      return meilleur.first;
    }

    bool Labyrinthe::appartient(const Piece &p) const {
      return trouvePiece(p.getNom()) != nullptr;
    }

    /**
     * \fn void Labyrinthe::placeDepart(const string &nom)
     * \brief initialise la variable de départ par l'adresse de la pièce de départ
     * \param nom: nom de la pièce de départ
     * \throw logic_error: si la pièce de départ n'existe pas
     */
    void Labyrinthe::placeDepart(const string &nom) {
      NoeudListePieces *noeud = trouvePiece(nom);

      if (!noeud)
        throw logic_error("<Labyrinthe::placeDepart> La pièce de départ n'existe pas");
      depart = &noeud->piece;
    }

    /**
     * \fn void Labyrinthe::placeArrivee(const string &nom)
     * \brief initialise la variable d'arrivée par l'adresse de la pièce d'arrivé
     * \param nom: nom de la pièce d'arrivée
     * \throw logic_error: si la pièce d'arrivée n'existe pas
     */
    void Labyrinthe::placeArrivee(const string &nom) {
      NoeudListePieces *noeud = trouvePiece(nom);

      if (!noeud)
        throw logic_error("La pièce d'arrivéé n'existe pas");
      arrivee = &noeud->piece;
    }

    /**
     * \fn Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(const string &nom) const
     * \brief Parcours tous les noeuds qui existent pour trouver le noeuds avec le nom qui correspond
     * \param nom: nom de la porte du noeud à trouver
     * \return l'adresse du noeud trouvé, nullptr autrement
     */
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