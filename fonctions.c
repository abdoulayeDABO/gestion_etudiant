#include <stdio.h>
#include "fonction.h"

void afficherEtudiantsParMerite(Etudiant VETU[], int SUIVANT[], int NBETU) {
    int i = 0;
    
    // Trouver l'étudiant ayant la meilleure note (celui au début de la chaîne)
    while (i != 0) {
        printf("Numéro: %d, Nom: %s, Note: %.2f\n", VETU[i].numero, VETU[i].nom, VETU[i].note);
        i = SUIVANT[i];  // On passe à l'étudiant suivant dans la chaîne
    }
}
