#include <stdio.h>
#include "fonction.h"

int main() {
    Etudiant VETU[NBETU];
    int SUIVANT[NBETU];
    int NBETU = 0;

    printf("Affichage des étudiants par ordre de mérite :\n");
    afficherEtudiantsParMerite(VETU, SUIVANT, NBETU);

    return 0;
}
