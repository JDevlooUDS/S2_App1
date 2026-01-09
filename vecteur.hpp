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
	int taille = 0;
	T** list = nullptr;
	
};

template <typename T>
Vecteur<T>::Vecteur() {
	list = new T*[capacite];
	list[0] = nullptr;
}

template <typename T>
Vecteur<T>::~Vecteur() {
	for(int i = 0; i < capacite; i++) {
		if (list[i] != nullptr) {
			delete list[i];
			list[i] = nullptr;
		}
	}
	delete[] list;
	list = nullptr;
}

template <typename T>
int Vecteur<T>::getCapacite() {
	return capacite;
}

template <typename T>
int Vecteur<T>::getTaille() {
	return taille;
}

template <typename T>
bool Vecteur<T>::ajouter(T* obj) {
	for(int i = 0; i < capacite; i++) {
		if (list[i] != nullptr && i == (capacite - 1)) aggrandir();
		else if (list[i] == nullptr) {
			list[i] = obj;
			taille++;
			return true;
		}
	}
	return false;
}

template <typename T>
T* Vecteur<T>::retirer(int index) {
	if (index < 0 || index >= capacite) return nullptr;
	T* obj = list[index];
	list[index] = nullptr;
	if (taille > index + 1) {
		for (int i = index; i < capacite - 1; i++) {
			list[i] = list[i + 1];
		}
	}
	taille--;
	return obj;
}

template <typename T>
T* Vecteur<T>::obtenir(int index) {
	if (index < 0 || index >= capacite) return nullptr;
	return list[index];
}

template <typename T>
void Vecteur<T>::vider() {
	for(int i = 0; i < capacite; i++) {
		if (list[i] != nullptr) {
			delete list[i];
			list[i] = nullptr;
		}
	}
	delete[] list;
	list = nullptr;
	
	capacite = 1;
	list = new T*[capacite];
	list[0] = nullptr;
}

template <typename T>
bool Vecteur<T>::estVide() {
	return getTaille() == 0;
}

template <typename T>
void Vecteur<T>::afficher(ostream &s) {
	for(int i = 0; i < capacite; i++) {
		if (list[i] != nullptr) list[i]->afficher(s);
	}
}

template <typename T>
void Vecteur<T>::aggrandir() {
	int newCapacite = capacite * 2;
	T** newList = new T*[newCapacite];
	
	for(int i = 0; i < newCapacite; i++) {
		newList[i] = nullptr;
	}	
	
	for(int i = 0; i < capacite; i++) {
		newList[i] = list[i];
	}
	delete[] list;
	capacite = newCapacite;
	list = newList;
	
}

#endif
