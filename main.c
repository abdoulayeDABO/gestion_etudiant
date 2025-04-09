#include <stdio.h>
#include "fonction.h"

#define NBETU 100
int main() {
    Etudiant VETU[NBETU];
    int SUIVANT[NBETU];
    int NBETU = 0;

    // Charger les étudiants depuis le fichier de sauvegarde
    ChargerEtudiants(VETU, SUIVANT, &NBETU);

    printf("Affichage des étudiants par ordre de mérite :\n");
    afficherEtudiantsParMerite(VETU, SUIVANT, NBETU);

    return 0;
}

