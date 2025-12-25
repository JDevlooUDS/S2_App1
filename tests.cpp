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
#include "carre.h"
#include "cercle.h"

const int ANCRAGE_PAR_DEFAUT_X = 52;
const int ANCRAGE_PAR_DEFAUT_Y = 53;
const int LARGEUR_PAR_DEFAUT = 10;
const int HAUTEUR_PAR_DEFAUT = 10;
const int COTE_PAR_DEFAUT = 10;
const int RAYON_PAR_DEFAUT = 10;

bool Tests::test_peut_creer_rectangle_avec_valeurs_de_base() {
	Rectangle rect;
	
	return rect.getAncrage().x == 0 &&
	       rect.getAncrage().y == 0 &&
	       rect.getLargeur() == 1 &&
	       rect.getHauteur() == 1;
}

bool Tests::test_peut_creer_rectangle_avec_valeurs() {
	Rectangle rect(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, LARGEUR_PAR_DEFAUT, HAUTEUR_PAR_DEFAUT);
	
	return rect.getAncrage().x == ANCRAGE_PAR_DEFAUT_X &&
	       rect.getAncrage().y == ANCRAGE_PAR_DEFAUT_Y &&
	       rect.getLargeur() == LARGEUR_PAR_DEFAUT &&
	       rect.getHauteur() == HAUTEUR_PAR_DEFAUT;
}

bool Tests::test_rectangle_peut_calculer_aire() {
	Rectangle rect(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, LARGEUR_PAR_DEFAUT, HAUTEUR_PAR_DEFAUT);
	int expected = LARGEUR_PAR_DEFAUT * HAUTEUR_PAR_DEFAUT;
	
	return rect.aire() == expected;
}

bool Tests::test_rectangle_peut_modifier_sa_largeur() {
	Rectangle rect(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, LARGEUR_PAR_DEFAUT, HAUTEUR_PAR_DEFAUT);
	int newLargeur = 45;
	
	rect.setLargeur(newLargeur);
	
	return rect.getLargeur() == newLargeur;
}

bool Tests::test_rectangle_peut_modifier_sa_hauteur() {
	Rectangle rect(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, LARGEUR_PAR_DEFAUT, HAUTEUR_PAR_DEFAUT);
	int newHauteur = 45;
	
	rect.setHauteur(newHauteur);
	
	return rect.getHauteur() == newHauteur;
}

bool Tests::test_rectangle_affiche_correctement_ses_valeurs() {
	Rectangle rect(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, LARGEUR_PAR_DEFAUT, HAUTEUR_PAR_DEFAUT);
	ostringstream oss;
	string expected = "Rectangle(x=52, y=53, l=10, h=10, aire=100)\n";
	
	rect.afficher(oss);
	
	return oss.str() == expected;	
}

bool Tests::test_rectangle_peut_changer_ancrage() {
	Rectangle rect(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, LARGEUR_PAR_DEFAUT, HAUTEUR_PAR_DEFAUT);
	Coordonnee newAncrage;
	newAncrage.x = 10;
	newAncrage.y = 15;
	
	rect.setAncrage(newAncrage);
	
	return rect.getAncrage().x == newAncrage.x &&
	       rect.getAncrage().y == newAncrage.y;
}

bool Tests::test_rectangle_peut_translater() {
	Rectangle rect(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, LARGEUR_PAR_DEFAUT, HAUTEUR_PAR_DEFAUT);
	int deltaX = 2;
	int deltaY = 5;
	
	rect.translater(deltaX, deltaY);
	
	return rect.getAncrage().x == ANCRAGE_PAR_DEFAUT_X + deltaX &&
	       rect.getAncrage().y == ANCRAGE_PAR_DEFAUT_Y + deltaY;
}

	
bool Tests::test_peut_creer_carre_avec_valeurs_de_base() {
	Carre carre;
	
	return carre.getAncrage().x == 0 &&
	       carre.getAncrage().y == 0 &&
	       carre.getCote() == 1;
}

bool Tests::test_peut_creer_carre_avec_valeurs() {
	Carre carre(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, COTE_PAR_DEFAUT);
	
	return carre.getAncrage().x == ANCRAGE_PAR_DEFAUT_X &&
	       carre.getAncrage().y == ANCRAGE_PAR_DEFAUT_Y &&
	       carre.getCote() == COTE_PAR_DEFAUT;
}

bool Tests::test_carre_peut_modifier_son_cote() {
	Carre carre(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, COTE_PAR_DEFAUT);
	int newCote = 12;
	
	carre.setCote(newCote);

	return carre.getCote() == newCote;
}

bool Tests::test_carre_peut_calculer_son_aire() {
	Carre carre(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, COTE_PAR_DEFAUT);
	int expected = COTE_PAR_DEFAUT * COTE_PAR_DEFAUT;
	
	return carre.aire() == expected;
}

bool Tests::test_carre_peut_afficher_ses_valeurs() {
	Carre carre(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, COTE_PAR_DEFAUT);
	ostringstream oss;
	string expected = "Carre (x=52, y=53, c=10, aire=100)\n";
	
	carre.afficher(oss);
	
	return oss.str() == expected;
}

bool Tests::test_carre_peut_changer_son_ancrage() {
	Carre carre(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, COTE_PAR_DEFAUT);
	Coordonnee newAncrage;
	newAncrage.x = 2;
	newAncrage.y = 3;
	
	carre.setAncrage(newAncrage);
	
	return carre.getAncrage().x == newAncrage.x &&
	       carre.getAncrage().y == newAncrage.y;
}

bool Tests::test_carre_peut_translater() {
	Carre carre(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, COTE_PAR_DEFAUT);
	int deltaX = 2;
	int deltaY = 3;
	
	carre.translater(deltaX, deltaY);
	
	return carre.getAncrage().x == ANCRAGE_PAR_DEFAUT_X + deltaX &&
	       carre.getAncrage().y == ANCRAGE_PAR_DEFAUT_Y + deltaY;
}

bool Tests::test_peut_creer_cercle_avec_valeurs_de_base() {
	Cercle cercle;
	
	return cercle.getAncrage().x == 0 &&
	       cercle.getAncrage().y == 0 &&
	       cercle.getRayon() == 1;
}

bool Tests::test_peut_creer_cercle_avec_valeurs() {
	Cercle cercle(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, RAYON_PAR_DEFAUT);
	
	return cercle.getAncrage().x == ANCRAGE_PAR_DEFAUT_X &&
	       cercle.getAncrage().y == ANCRAGE_PAR_DEFAUT_Y &&
	       cercle.getRayon() == RAYON_PAR_DEFAUT;
}

bool Tests::test_cercle_peut_modifier_son_rayon() {
	Cercle cercle(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, RAYON_PAR_DEFAUT);
	int newRayon = 5;
	
	cercle.setRayon(newRayon);
	
	return cercle.getRayon() == newRayon;
}

bool Tests::test_cercle_peut_calculer_son_aire() {
	Cercle cercle(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, RAYON_PAR_DEFAUT);
	double expected =  pow(RAYON_PAR_DEFAUT, 2) * M_PI;
	
	return cercle.aire() == expected;
	
}

bool Tests::test_cercle_peut_afficher_ses_valeurs() {
	Cercle cercle(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, RAYON_PAR_DEFAUT);
	ostringstream oss;
	stringstream ss;
	ss << "Cercle (x=52, y=53, r=10, aire=" << 100.0 *M_PI << ")\n";
	string expected = ss.str();
	
	cercle.afficher(oss);
	
	return oss.str() == expected;
}

bool Tests::test_cercle_peut_changer_son_ancrage() {
	Cercle cercle(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, RAYON_PAR_DEFAUT);
	Coordonnee newAncrage;
	newAncrage.x = 1;
	newAncrage.y = 1;
	cercle.setAncrage(newAncrage);
	
	return cercle.getAncrage().x == 1 &&
	       cercle.getAncrage().y == 1;
}

bool Tests::test_cercle_peut_translater() {
	Cercle cercle(ANCRAGE_PAR_DEFAUT_X, ANCRAGE_PAR_DEFAUT_Y, RAYON_PAR_DEFAUT);
	int deltaX = 2;
	int deltaY = 3;
	
	cercle.translater(deltaX, deltaY);
	
	return cercle.getAncrage().x == ANCRAGE_PAR_DEFAUT_X + deltaX &&
	       cercle.getAncrage().y == ANCRAGE_PAR_DEFAUT_Y + deltaY;
}


void Tests::tests_unitaires_formes()
{
	//Tests Rectangle
	if (test_peut_creer_rectangle_avec_valeurs_de_base() &&
	    test_peut_creer_rectangle_avec_valeurs() &&
	    test_rectangle_affiche_correctement_ses_valeurs() &&
	    test_rectangle_peut_calculer_aire() &&
	    test_rectangle_peut_modifier_sa_largeur() &&
	    test_rectangle_peut_modifier_sa_hauteur() &&
	    test_rectangle_peut_changer_ancrage() &&
	    test_rectangle_peut_translater())
		cout << "Tests sur les rectangles réussies" << endl;
	else
		cout << "Tests sur les rectangles échouées" << endl;
		
	//Tests Carré
	if (test_peut_creer_carre_avec_valeurs_de_base() &&
	    test_peut_creer_carre_avec_valeurs() &&
	    test_carre_peut_modifier_son_cote() &&
	    test_carre_peut_calculer_son_aire() &&
	    test_carre_peut_afficher_ses_valeurs() &&
	    test_carre_peut_changer_son_ancrage() &&
	    test_carre_peut_translater() &&
	    test_cercle_peut_translater())
		cout << "Tests sur les carrées réussies" << endl;
	else
		cout << "Tests sur les carrées échouées" << endl;
	
	//Tests Cercle
	if (test_peut_creer_cercle_avec_valeurs_de_base() &&
	    test_peut_creer_cercle_avec_valeurs() &&
	    test_cercle_peut_modifier_son_rayon() &&
	    test_cercle_peut_calculer_son_aire() &&
	    test_cercle_peut_afficher_ses_valeurs() &&
	    test_cercle_peut_changer_son_ancrage())
		cout << "Tests sur les cercles réussies" << endl;
	else
		cout << "Tests sur les cercles échouées" << endl;
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
