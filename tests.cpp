/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Implémentation des méthodes des classes décrites dans
 *    tests.h.  Ce fichier peut être adapté à vos besoins de tests.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/
#include "tests.h"

const int ANCRAGE_PAR_DEFAUT_X = 52;
const int ANCRAGE_PAR_DEFAUT_Y = 53;
const int LARGEUR_PAR_DEFAUT = 10;
const int HAUTEUR_PAR_DEFAUT = 10;
const int COTE_PAR_DEFAUT = 10;
const int RAYON_PAR_DEFAUT = 10;


// ---------------------------- Tests classe Rectangle ----------------------------
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

// ---------------------------- Tests classe Carre ----------------------------
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

// ---------------------------- Tests classe Cercle ----------------------------
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


// ---------------------------- Tests classe Rectangle ----------------------------
bool Tests::test_vecteur_retourne_taille_zero_quand_vide() {
	Vecteur<Forme> v;
	
	return v.getTaille() == 0;
}

bool Tests::test_vecteur_retourne_taille_1_quand_1_element() {
	Vecteur<Forme> v;
	Cercle* c = new Cercle();
	v.ajouter(c);
	
	return v.getTaille() == 1;
}

bool Tests::test_vecteur_retourne_taille_X_quand_X_element() {
	Vecteur<Forme> v;
	for(int i = 0; i < 10; i++) {
		Cercle* c = new Cercle();
		v.ajouter(c);
	}
	
	return v.getTaille() == 10;
}

bool Tests::test_capacite_initial_est_unitaire() {
	Vecteur<Forme> v;
	
	return v.getCapacite() == 1;
}

bool Tests::test_capacite_double_lorsque_trop_plein() {
	Vecteur<Forme> v;
	for(int i = 0; i < 2; i++) {
		Cercle* c = new Cercle();
		v.ajouter(c);
	}
	
	return v.getCapacite() == 2;
}

bool Tests::test_lorsque_vecteur_se_vide_taille_devient_zero() {
	Vecteur<Forme> v;
	for(int i = 0; i < 10; i++) {
		Cercle* c = new Cercle();
		v.ajouter(c);
	}

	v.vider();

	return v.getTaille() == 0;
}
	
bool Tests::test_estVide_retourne_vrai_quand_le_vecteur_est_vide() {
	Vecteur<Forme> v;
	for(int i = 0; i < 10; i++) {
		Cercle* c = new Cercle();
		v.ajouter(c);
	}
	
	v.vider();
	
	return v.estVide();
}

bool Tests::test_estVide_retourne_faux_quand_le_vecteur_nest_pas_vide() {
	Vecteur<Forme> v;
	for(int i = 0; i < 10; i++) {
		Cercle* c = new Cercle();
		v.ajouter(c);
	}
	
	return !v.estVide();
}

bool Tests::test_ajouter_au_vecteur_retourne_vrai_lorsque_la_forme_est_ajouter() {
	Vecteur<Forme> v;
	Cercle* c = new Cercle();
	
	bool resultat = v.ajouter(c);
	
	return resultat && v.getTaille() == 1;
}

bool Tests::test_retirer_au_vecteur_retourne_pointeur_vers_objet_selon_index_et_retire_objet() {
	Vecteur<Forme> v;
	Cercle* c = new Cercle();
	v.ajouter(c);
	int index = 0;
	
	Forme* f = v.retirer(index);
	return f == c && v.getTaille() == 0;
}

bool Tests::test_retirer_avec_index_plus_petit_que_zero_retourne_nullptr_et_garde_objet() {
	Vecteur<Forme> v;
	Cercle* c = new Cercle();
	v.ajouter(c);
	int index = -1;
	
	Forme* f = v.retirer(index);
	
	return f == nullptr && v.getTaille() == 1;
}

bool Tests::test_retirer_avec_index_plus_grand_que_capacite_retourne_nullptr_et_garde_objet() {
	Vecteur<Forme> v;
	Cercle* c = new Cercle();
	v.ajouter(c);
	int index = 50;
	
	Forme* f = v.retirer(index);
	
	return f == nullptr && v.getTaille() == 1;
}

bool Tests::test_obtenir_au_vecteur_retourne_pointeur_vers_objet_selon_index() {
	Vecteur<Forme> v;
	Cercle* c = new Cercle();
	v.ajouter(c);
	int index = 0;
	
	Forme* f = v.obtenir(index);
	
	return f == c && v.getTaille() == 1;
}

bool Tests::test_obtenir_avec_index_plus_petit_que_zero_retourne_nullptr() {
	Vecteur<Forme> v;
	Cercle* c = new Cercle();
	v.ajouter(c);
	int index = -1;
	
	Forme* f = v.obtenir(index);
	
	return f == nullptr && v.getTaille() == 1;
}

bool Tests::test_obtenir_avec_index_plus_grand_que_capacite_retourne_nullptr() {
	Vecteur<Forme> v;
	Cercle* c = new Cercle();
	v.ajouter(c);
	int index = 50;
	
	Forme* f = v.obtenir(index);
	
	return f == nullptr && v.getTaille() == 1;
}

bool Tests::test_afficher_affiche_le_contenu_de_chaque_forme_du_vecteur() {
	Vecteur<Forme> v;
	Rectangle* r = new Rectangle();
	Carre* c = new Carre();
	v.ajouter(r);
	v.ajouter(c);
	ostringstream oss;
	string expected = "Rectangle(x=0, y=0, l=1, h=1, aire=1)\nCarre (x=0, y=0, c=1, aire=1)\n";
					 	
	v.afficher(oss);
	
	return oss.str() == expected;
}

// ---------------------------- Tests classe Couche ----------------------------
bool Tests::test_couche_ajoute_forme_si_active_retourne_vrai() {
	Couche couche;
	couche.changerEtat(ACTIVE);
	Rectangle* r = new Rectangle();
	
	bool resultat = couche.ajouter(r);
	
	return resultat;
}

bool Tests::test_couche_ajoute_forme_si_inactive_retourne_faux() {
	Couche couche;
	couche.changerEtat(INACTIVE);
	Rectangle* r = new Rectangle();
	
	bool resultat = couche.ajouter(r);
	
	return !resultat;
}

bool Tests::test_couche_retire_forme_si_active_retourne_forme() {
	Couche couche;
	couche.changerEtat(ACTIVE);
	Rectangle* r = new Rectangle();
	couche.ajouter(r);
	
	Forme* pforme = couche.retirer(0);
	
	return pforme == r;
}

bool Tests::test_couche_retire_forme_si_inactive_retourne_nullptr() {
	Couche couche;
	couche.changerEtat(INACTIVE);
	Rectangle* r = new Rectangle();
	couche.ajouter(r);
	
	Forme* pforme = couche.retirer(0);
	
	return pforme == nullptr;
}

bool Tests::test_couche_obtenir_forme_retourne_forme() {
	Couche couche;
	couche.changerEtat(ACTIVE);
	Rectangle* r = new Rectangle();
	couche.ajouter(r);
	
	Forme* pforme = couche.obtenir(0);
	
	return pforme == r;
}

bool Tests::test_couche_donne_aire_totale_si_active_retourne_aire() {
	Couche couche;
	couche.changerEtat(ACTIVE);
	double expected = 50;
	for(int i = 0; i < 5; i++) {
		Rectangle* r = new Rectangle(0,0,2,5);
		couche.ajouter(r);
	}
	
	double aire = couche.aire();
	
	return aire == expected;
}

bool Tests::test_couche_donne_aire_toatale_si_initialise_retourne_zero() {
	Couche couche;
	
	double aire = couche.aire();
	
	return aire == 0;
}

bool Tests::test_couche_peut_translater_formes_si_active() {
	Couche couche;
	couche.changerEtat(ACTIVE);
	int deltaX = 2;
	int deltaY = 3;
	Rectangle* r = new Rectangle();
	Carre* c = new Carre();
	couche.ajouter(r);
	couche.ajouter(c);
	
	bool resultat = couche.translater(deltaX, deltaY);
	
	return resultat &&
		   r->getAncrage().x == deltaX &&
		   r->getAncrage().y == deltaY &&
		   c->getAncrage().x == deltaX &&
		   c->getAncrage().y == deltaY;
}

bool Tests::test_couche_ne_peut_pas_translater_formes_si_inactive() {
	Couche couche;
	couche.changerEtat(INACTIVE);
	int deltaX = 2;
	int deltaY = 3;
	Rectangle* r = new Rectangle();
	Carre* c = new Carre();
	couche.ajouter(r);
	couche.ajouter(c);
	
	bool resultat = couche.translater(deltaX, deltaY);
	
	return !resultat &&
		   r->getAncrage().x == 0 &&
		   r->getAncrage().y == 0 &&
		   c->getAncrage().x == 0 &&
		   c->getAncrage().y == 0;
}

bool Tests::test_couche_peut_se_reinitialiser_retourne_un_boolean() {
	Couche couche;
	couche.changerEtat(ACTIVE);
	for(int i = 0; i < 5; i++) {
		Rectangle* r = new Rectangle();
		couche.ajouter(r);
	}
	
	bool resultat = couche.reinitialiser();
	
	return resultat;
}

bool Tests::test_couche_peut_afficher_son_contenue() {
	Couche couche;
	couche.changerEtat(ACTIVE);
	Rectangle* r = new Rectangle();
	Carre* c = new Carre();
	couche.ajouter(r);
	couche.ajouter(c);
	ostringstream oss;
	string expected = "État: active\nRectangle(x=0, y=0, l=1, h=1, aire=1)\nCarre (x=0, y=0, c=1, aire=1)\n";
	
	couche.afficher(oss);
	
	return oss.str() == expected;
}

// ---------------------------- Tests classe Canevas ----------------------------
bool Tests::test_canevas_peut_reinitialiser_une_couche_retourne_vrai() {
	Canevas canevas;
	Rectangle* r = new Rectangle();
	
	bool resultat = canevas.reinitialiserCouche(0);
	return resultat;
	
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
	if (test_vecteur_retourne_taille_zero_quand_vide() &&
		test_vecteur_retourne_taille_1_quand_1_element() &&
		test_vecteur_retourne_taille_X_quand_X_element() &&
		test_capacite_initial_est_unitaire() &&
		test_capacite_double_lorsque_trop_plein() &&
		test_lorsque_vecteur_se_vide_taille_devient_zero() &&
		test_estVide_retourne_vrai_quand_le_vecteur_est_vide() &&
		test_estVide_retourne_faux_quand_le_vecteur_nest_pas_vide() &&
		test_ajouter_au_vecteur_retourne_vrai_lorsque_la_forme_est_ajouter() &&
		test_retirer_au_vecteur_retourne_pointeur_vers_objet_selon_index_et_retire_objet() &&
		test_retirer_avec_index_plus_petit_que_zero_retourne_nullptr_et_garde_objet() &&
		test_retirer_avec_index_plus_grand_que_capacite_retourne_nullptr_et_garde_objet() &&
		test_obtenir_au_vecteur_retourne_pointeur_vers_objet_selon_index() &&
		test_obtenir_avec_index_plus_petit_que_zero_retourne_nullptr() &&
		test_obtenir_avec_index_plus_grand_que_capacite_retourne_nullptr() &&
		test_afficher_affiche_le_contenu_de_chaque_forme_du_vecteur())
		cout << "Tests sur les vecteurs réussies" << endl;
	else
		cout << "Tests sur les vecteurs échouées" << endl;
}

void Tests::tests_unitaires_couche()
{
	if (test_couche_ajoute_forme_si_active_retourne_vrai() &&
		test_couche_ajoute_forme_si_inactive_retourne_faux() &&
		test_couche_retire_forme_si_active_retourne_forme() &&
		test_couche_retire_forme_si_inactive_retourne_nullptr() && 
		test_couche_obtenir_forme_retourne_forme() &&
		test_couche_donne_aire_totale_si_active_retourne_aire() &&
		test_couche_donne_aire_toatale_si_initialise_retourne_zero() &&
		test_couche_peut_translater_formes_si_active() &&
		test_couche_ne_peut_pas_translater_formes_si_inactive() &&
		test_couche_peut_se_reinitialiser_retourne_un_boolean() &&
		test_couche_peut_afficher_son_contenue())
		cout << "Tests sur les couches réussies" << endl;
	else 
		cout << "Tests sur les couches échouées" << endl;
}

void Tests::tests_unitaires_canevas()
{
	// Tests de la classe Canevas
	if (test_canevas_peut_reinitialiser_une_couche_retourne_vrai())
		cout << "Tests sur les canevas réussies" << endl;
	else
		cout << "Tests sur les canevas échouées" << endl;
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
