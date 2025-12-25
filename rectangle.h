#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "forme.h"

class Rectangle: public Forme {
public:
	Rectangle(int x=0, int y=0, int l=1, int h=1);
	double aire() override;
	void afficher(ostream &s) override;
	void setHauteur(int h);
	int getHauteur();
	void setLargeur(int l);
	int getLargeur();
protected:
	int largeur;
	int hauteur;
};

#endif
