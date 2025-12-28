/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Implémentation des méthodes des classes décrites dans
 *    couche.h.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

Couche::Couche() {
	etat = INITIALISE;
}

Couche::~Couche() {}

bool Couche::ajouter(Forme* pforme) {
	if (etat != ACTIVE) return false;
	return vecteur.ajouter(pforme);
}

Forme* Couche::retirer(int index) {
	if (etat != ACTIVE) return nullptr;
	return vecteur.retirer(index);
}

Forme* Couche::obtenir(int index) {
	return vecteur.obtenir(index);
}

double Couche::aire() {
	double A = 0.0d;
	for(int i = 0; i < vecteur.getCapacite(); i++) {
		Forme* pforme = vecteur.obtenir(i);
		if (pforme != nullptr) A += pforme->aire();
	}
	return A;
}

bool Couche::translater(int deltaX, int deltaY) {
	if (etat != ACTIVE) return false;
	for(int i = 0; i < vecteur.getCapacite(); i++) {
		Forme* pforme = vecteur.obtenir(i);
		if (pforme != nullptr) pforme->translater(deltaX, deltaY);
	}
	return true;
}

bool Couche::reinitialiser() {
	vecteur.vider();
	return vecteur.estVide();
}

bool Couche::changerEtat(Etat etat) {
	if (etat == INITIALISE) return false;
	this->etat = etat;
	return true;
}

void Couche::afficher(ostream &s) {
	string etatActuel;
	switch(etat) {
		case INITIALISE:
			etatActuel = "initialisée";
			break;
		case ACTIVE:
			etatActuel = "active";
			break;
		case INACTIVE:
			etatActuel = "inactive";
			break;
	}
	s << "État: " << etatActuel << endl;
	vecteur.afficher(s);
}

bool Couche::estActive() {
	return etat == ACTIVE;
}
