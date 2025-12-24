/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Implémentation des méthodes des classes décrites dans
 *    tests.h.  Ce fichier peut être adapté à vos besoins de tests.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#include "sstream"
#include "tests.h"
#include "rectangle.h"

bool Tests::test_peut_créer_rectangle_avec_valeurs() {
	Rectangle rect(52,52,10,10);
	
	return rect.getAncrage().x == 52 &&
	       rect.getAncrage().y == 52 &&
	       rect.getLargeur() == 10 &&
	       rect.getHauteur() == 10;
}

bool Tests::test_rectangle_peut_calculer_aire() {
	Rectangle rect(52,52,10,10);
	int expected = 100;
	
	return rect.aire() == expected;
}

bool Tests::test_rectangle_peut_modifier_sa_largeur() {
	Rectangle rect(52,52,10,10);
	int newLargeur = 45;
	
	rect.setLargeur(newLargeur);
	
	return rect.getLargeur() == newLargeur;
}

bool Tests::test_rectangle_peut_modifier_sa_hauteur() {
	Rectangle rect(52,52,10,10);
	int newHauteur = 45;
	
	rect.setHauteur(newHauteur);
	
	return rect.getHauteur() == newHauteur;
}

bool Tests::test_rectangle_affiche_correctement_ses_valeurs() {
	Rectangle rect(52,52,10,10);
	ostringstream oss;
	string expected = "Rectangle(x=52, y=52, l=10, h=10, aire=100)\n";
	
	rect.afficher(oss);
	
	return oss.str() == expected;	
}

bool Tests::test_rectangle_peut_changer_ancrage() {
	Rectangle rect(52,52,10,10);
	Coordonnee newAncrage;
	newAncrage.x = 10;
	newAncrage.y = 15;
	
	rect.setAncrage(newAncrage);
	
	return rect.getAncrage().x == newAncrage.x &&
	       rect.getAncrage().y == newAncrage.y;
}

bool Tests::test_rectangle_peut_translater() {
	Rectangle rect(52,52,10,10);
	int deltaX = 2;
	int deltaY = 5;
	
	rect.translater(deltaX, deltaY);
	
	return rect.getAncrage().x == 52 + deltaX &&
	       rect.getAncrage().y == 52 + deltaY;
}

void Tests::tests_unitaires_formes()
{
	//Tests Rectangle
	if (test_peut_créer_rectangle_avec_valeurs() &&
	    test_rectangle_affiche_correctement_ses_valeurs() &&
	    test_rectangle_peut_calculer_aire() &&
	    test_rectangle_peut_modifier_sa_largeur() &&
	    test_rectangle_peut_modifier_sa_hauteur() &&
	    test_rectangle_peut_changer_ancrage() &&
	    test_rectangle_peut_translater())
		cout << "Tests sur les rectangles réussies" << endl;
	else
		cout << "Tests sur les rectangles échouées" << endl;
	
	//Tests Cercle
	
	//Tests Carré
}

void Tests::tests_unitaires_vecteur()
{
	// Tests de la classe Vecteur
}

void Tests::tests_unitaires_couche()
{
	// Tests de la classe Couche
}

void Tests::tests_unitaires_canevas()
{
	// Tests de la classe Canevas
}

void Tests::tests_unitaires()
{
	// Faire tous les tests unitaires
	tests_unitaires_formes();
	tests_unitaires_vecteur();
	tests_unitaires_couche();
	tests_unitaires_canevas();
}

void Tests::tests_application()
{
	// Faire tous les tests applicatifs
	tests_application_cas_01();
	tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
	cout << "TESTS APPLICATION (CAS 01)" << endl;
	// Il faut ajouter les opérations réalisant ce scénario de test.
}

void Tests::tests_application_cas_02()
{
	cout << "TESTS APPLICATION (CAS 02)" << endl;
	// Il faut ajouter les opérations realisant ce scénario de test.
}
