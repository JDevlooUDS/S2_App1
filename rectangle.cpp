#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int l, int h):Forme(x,y) {
	largeur = l;
	hauteur = h;
}

void Rectangle::afficher(ostream &s) {
	s << "Rectangle(x=" << ancrage.x << ", y=" << ancrage.y << ", l=" << largeur << ", h=" << hauteur << ", aire=" << aire() << ")" << endl;
}

double Rectangle::aire() {
	return hauteur * largeur;
}

void Rectangle::setHauteur(int h) {
	hauteur = h;
}

int Rectangle::getHauteur() {
	return hauteur;
}

void Rectangle::setLargeur(int l) {
	largeur = l;
}

int Rectangle::getLargeur() {
	return largeur;
}
