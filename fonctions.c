#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#define NBETU 100

void afficherEtudiantsParMerite(Etudiant VETU[], int SUIVANT[], int NBETU) {
    int i = 0;
    
    // Trouver l'étudiant ayant la meilleure note (celui au début de la chaîne)
    while (i != 0) {
        printf("Numéro: %d, Nom: %s, Note: %.2f\n", VETU[i].numero, VETU[i].nom, VETU[i].note);
        i = SUIVANT[i];  // On passe à l'étudiant suivant dans la chaîne
    }
}
void ChargerEtudiants(Etudiant VETU[], int SUIVANT[], int* NBETU) {
    FILE* file = fopen("etudiants.dat", "rb");
    if (file == NULL) {
        printf("Aucun fichier de sauvegarde trouvé.\n");
        return;
    }

    // Lire l'indice du premier étudiant (DEB)
    int DEB;
    fread(&DEB, sizeof(int), 1, file);

    // Initialiser le nombre d'étudiants
    *NBETU = 0;
    
    // Charger les étudiants et les lier avec SUIVANT
    int i = 0;
    while (fread(&VETU[i], sizeof(Etudiant), 1, file) == 1) {
        fread(&SUIVANT[i], sizeof(int), 1, file);  // Lire l'indice du suivant
        i++;
        (*NBETU)++;  // Incrémenter le nombre d'étudiants
    }

    fclose(file);
    printf("Les données des étudiants ont été chargées avec succès.\n");
}

