#ifndef ETUDIANTS_H
#define ETUDIANTS_H

#define MAX_NOM_LENGTH 50

typedef struct {
    int numero;
    char nom[MAX_NOM_LENGTH];
    int note;
} Etudiant;


void saisir_etudiants(VETU, NBETU);
void afficher_resultats(Etudiant VETU[], int SUIVANT[], int DEB);
void chainer_etudiants(int VETU[], int NBETU, int SUIVANT[], int *DEB);
void ajouter_etudiant(Etudiant VETU[], int *NBETU);
void supprimer_etudiant(Etudiant VETU[], int *NBETU, int numero);
void sauvegarder_donnees(Etudiant VETU[], int NBETU);
void restaurer_donnees(Etudiant VETU[], int *NBETU);
void trier_par_nom(Etudiant VETU[], int NBETU);
void trier_par_note(Etudiant VETU[], int NBETU);
void trier_aleatoire(Etudiant VETU[], int NBETU);

#endif

