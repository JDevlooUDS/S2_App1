#include "forme.h"
#include <cmath>

class Cercle: public Forme {
public:
	Cercle(int x=0, int y=0, int r=1);
	double aire() override;
	void afficher(ostream &s) override;
	void setRayon(int r);
	int getRayon();
protected:
	int rayon;
};
