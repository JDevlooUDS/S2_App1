#include "rectangle.h"

class Carre: public Rectangle {
public:
	Carre(int x=0, int y=0, int c=1);
	int getCote();
	void setCote(int c);
	void afficher(ostream &s) override;
};
