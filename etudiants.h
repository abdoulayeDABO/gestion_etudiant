#ifndef ETUDIANTS_H
#define ETUDIANTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOM_LENGTH 50
#define MAX_ETUDIANTS 100
#define FICHIER_SAUVEGARDE "etudiants.data"


typedef struct {
    int numero;
    char prenom[MAX_NOM_LENGTH];
    char nom[MAX_NOM_LENGTH];
    int note;
} Etudiant;



void saisir_etudiants(Etudiant * VETU, int nb_ajout, int *NBETU);
void afficher_resultats(Etudiant VETU[], int SUIVANT[], int DEB);
void chainer_etudiants(Etudiant VETU[], int NBETU, int SUIVANT[], int *DEB);
void afficher_etudiants(Etudiant VETU[], int NBETU);
void ajouter_etudiant(Etudiant VETU[], int *NBETU);
void supprimer_etudiant(Etudiant VETU[], int *NBETU, int numero);
void sauvegarder_donnees(Etudiant VETU[], int NBETU);
void restaurer_donnees(Etudiant VETU[], int *NBETU);
void trier_par_nom(Etudiant VETU[], int NBETU);
void trier_par_note(Etudiant VETU[], int NBETU);
void trier_aleatoire(Etudiant VETU[], int NBETU);

#endif

