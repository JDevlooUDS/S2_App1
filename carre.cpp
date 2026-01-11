#include "carre.h"

Carre::Carre(int x, int y, int c): Forme(x,y) {
	cote = c;
}

void Carre::setCote(int c) {
	cote = c;
}

int Carre::getCote() {
	return cote;
}

void Carre::afficher(ostream &s) {
	s << "Carre (x=" << ancrage.x << ", y=" << ancrage.y << ", c=" << cote << ", aire=" << aire() << ")" << endl;
}

double Carre::aire() {
	return cote * cote;
}
