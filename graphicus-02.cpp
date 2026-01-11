/********
 * Fichier: graphicus-01.cpp
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: gestionnaire de tests pour l'application Graphicus.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/
#include "tests.h"

using namespace std;

int main()
{
	Tests tests;

	//tests.tests_unitaires();
	cout << endl;
	tests.test_validation();
	return 0;
}

