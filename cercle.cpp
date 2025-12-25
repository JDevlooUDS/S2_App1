#include "cercle.h"

Cercle::Cercle(int x, int y, int r): Forme(x,y) {
	rayon = r;
}

double Cercle::aire() {
	return pow(rayon,2) * M_PI;
}

void Cercle::afficher(ostream &s) {
	s << "Cercle (x=" << ancrage.x << ", y=" << ancrage.y << ", r=" << rayon << ", aire=" << aire() << ")" << endl;
}

void Cercle::setRayon(int r) {
	rayon = r;
}

int Cercle::getRayon() {
	return rayon;
}
