/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Implémentation des méthodes des classes décrites dans
 *    canevas.h.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas()
{
	activerCouche(0);
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
	return true;
}

bool Canevas::reinitialiserCouche(int index)
{
	bool estActive = couches[index].estActive();
	bool resultat = couches[index].reinitialiser();
	if (estActive) activerCouche(index);
	return resultat;
}

bool Canevas::activerCouche(int index)
{
	return couches[index].changerEtat(ACTIVE);
}

bool Canevas::desactiverCouche(int index)
{
	return couches[index].changerEtat(INACTIVE);
}

bool Canevas::ajouterForme(Forme *p_forme)
{
	for(int i = 0; i < MAX_COUCHES; i++) {
		if (couches[i].estActive()) {
			return couches[i].ajouter(p_forme);
		}
	}
	return false;
}

bool Canevas::retirerForme(int index)
{
	Forme* pforme = nullptr;
	for(int i = 0; i < MAX_COUCHES; i++) {
		if (couches[i].estActive()) {
			pforme = couches[i].retirer(index);
		}
	}
	
	if (pforme == nullptr) {
		return false;
	}
	else {
		delete pforme;
		return true;
	}
}

double Canevas::aire()
{
	double A = 0.0;
	
	for(int i = 0; i < MAX_COUCHES; i++) {
		A += couches[i].aire();
	}
	
	return A;
}

bool Canevas::translater(int deltaX, int deltaY)
{
	for(int i = 0; i < MAX_COUCHES; i++) {
		if (couches[i].estActive()) {
			return couches[i].translater(deltaX, deltaY);
		}
	}
	return false;
}

void Canevas::afficher(ostream & s)
{
	for(int i = 0; i < MAX_COUCHES; i++) {
		s << "----- Couche " << i << " -----" << endl;
		couches[i].afficher(s);
	}
}
