#include "carre.h"

Carre::Carre(int x, int y, int c):Rectangle(x,y,c,c) {}

void Carre::setCote(int c) {
	largeur = c;
	hauteur = c;
}

int Carre::getCote() {
	return largeur;
}

void Carre::afficher(ostream &s) {
	s << "Carre (x=" << ancrage.x << ", y=" << ancrage.y << ", c=" << largeur << ", aire=" << aire() << ")" << endl;
}
