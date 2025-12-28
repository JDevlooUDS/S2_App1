/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Déclaration de la classe pour une couche dans un
 *    canevas. La classe Couche gère un vecteur de pointeurs de formes
 *    géométriques en accord avec les spécifications de Graphicus.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H

#include "vecteur.h"

enum Etat {
	INITIALISE,
	ACTIVE,
	INACTIVE
};

class Couche
{
public:
	Couche();
	~Couche();
	bool ajouter(Forme* pforme);
	Forme* retirer(int index);
	Forme* obtenir(int index);
	double aire();
	bool translater(int deltaX, int deltaY);
	bool reinitialiser();
	bool changerEtat(Etat etat);
	bool estActive();
	void afficher(ostream &s);

private:
	Vecteur<Forme> vecteur;
	Etat etat;
};

#endif
