/********
 * Fichier: tests.h
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Déclaration de la classe pour les tests de Graphicus.
 *    Ce fichier peut être adapté à vos besoins de tests.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include "canevas.h"

using namespace std;

class Tests
{
public:
	// Méthodes pour les tests unitaires des classes
	//Tests pour la classe Rectangle
	bool test_peut_creer_rectangle_avec_valeurs_de_base();
	bool test_peut_creer_rectangle_avec_valeurs();
	bool test_rectangle_peut_calculer_aire();
	bool test_rectangle_peut_modifier_sa_largeur();
	bool test_rectangle_peut_modifier_sa_hauteur();
	bool test_rectangle_affiche_correctement_ses_valeurs();
	bool test_rectangle_peut_changer_ancrage();
	bool test_rectangle_peut_translater();
	
	//Tests pour la classe Carre
	bool test_peut_creer_carre_avec_valeurs_de_base();
	bool test_peut_creer_carre_avec_valeurs();
	bool test_carre_peut_modifier_son_cote();
	bool test_carre_peut_calculer_son_aire();
	bool test_carre_peut_afficher_ses_valeurs();
	bool test_carre_peut_changer_son_ancrage();
	bool test_carre_peut_translater();
	
	//Tests pour la classe Cercle
	bool test_peut_creer_cercle_avec_valeurs_de_base();
	bool test_peut_creer_cercle_avec_valeurs();
	bool test_cercle_peut_modifier_son_rayon();
	bool test_cercle_peut_calculer_son_aire();
	bool test_cercle_peut_afficher_ses_valeurs();
	bool test_cercle_peut_changer_son_ancrage();
	bool test_cercle_peut_translater();
	
	void tests_unitaires_formes();
	void tests_unitaires_vecteur();
	void tests_unitaires_couche();
	void tests_unitaires_canevas();
	void tests_unitaires(); // Appel de tous les tests unitaires
	// Méthodes pour les tests unitaires applicatifs
	void tests_application_cas_01();
	void tests_application_cas_02();
	void tests_application(); // Appel de tous les tests applicatifs
};

#endif
