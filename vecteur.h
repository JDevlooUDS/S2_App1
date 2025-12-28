#ifndef VECTEUR_H
#define VECTEUR_H

#include "forme.h"
#include <type_traits>

template < typename T >
class Vecteur {

public:
	Vecteur();
	~Vecteur();
	int getCapacite();
	int getTaille();
	void vider();
	bool estVide();
	bool ajouter(T *obj);
	T* retirer(int index);
	T* obtenir(int index);
	void afficher(ostream &s);
	
private:
	void aggrandir();

	int capacite = 1;
	T** list = nullptr;
	
};

#endif
