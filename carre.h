#include "forme.h"

class Carre: public Forme {
public:
	Carre(int x=0, int y=0, int c=1);
	int getCote();
	void setCote(int c);
	void afficher(ostream &s) override;
	double aire() override;
private:
	int cote;
};
