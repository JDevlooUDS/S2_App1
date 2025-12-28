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
#include "sstream"
#include "canevas.h"
#include "vecteur.h"
#include "rectangle.h"
#include "carre.h"
#include "cercle.h"

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
	
	//Tests pour la classe vecteur
	bool test_vecteur_retourne_taille_zero_quand_vide();
	bool test_vecteur_retourne_taille_1_quand_1_element();
	bool test_vecteur_retourne_taille_X_quand_X_element();
	bool test_capacite_initial_est_unitaire();
	bool test_capacite_double_lorsque_trop_plein();
	bool test_lorsque_vecteur_se_vide_taille_devient_zero();
	bool test_estVide_retourne_vrai_quand_le_vecteur_est_vide();
	bool test_estVide_retourne_faux_quand_le_vecteur_nest_pas_vide();
	bool test_ajouter_au_vecteur_retourne_vrai_lorsque_la_forme_est_ajouter();
	bool test_retirer_au_vecteur_retourne_pointeur_vers_objet_selon_index_et_retire_objet();
	bool test_retirer_avec_index_plus_petit_que_zero_retourne_nullptr_et_garde_objet();
	bool test_retirer_avec_index_plus_grand_que_capacite_retourne_nullptr_et_garde_objet();
	bool test_obtenir_au_vecteur_retourne_pointeur_vers_objet_selon_index();
	bool test_obtenir_avec_index_plus_petit_que_zero_retourne_nullptr();
	bool test_obtenir_avec_index_plus_grand_que_capacite_retourne_nullptr();
	bool test_afficher_affiche_le_contenu_de_chaque_forme_du_vecteur();
	
	//Tests pour la classe couche
	bool test_couche_ajoute_forme_si_active_retourne_vrai();
	bool test_couche_ajoute_forme_si_inactive_retourne_faux();
	bool test_couche_retire_forme_si_active_retourne_forme();
	bool test_couche_retire_forme_si_inactive_retourne_nullptr();
	bool test_couche_obtenir_forme_retourne_forme();
	bool test_couche_donne_aire_totale_si_active_retourne_aire();
	bool test_couche_donne_aire_toatale_si_initialise_retourne_zero();
	bool test_couche_peut_translater_formes_si_active();
	bool test_couche_ne_peut_pas_translater_formes_si_inactive();
	bool test_couche_peut_se_reinitialiser_retourne_un_boolean();
	bool test_couche_peut_afficher_son_contenue();
	
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
