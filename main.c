#include <stdio.h>
#include "fonction.h"


int main() {
    printf("Hello, World!\n");
    return 0;
}

// La Fonction AfficherEtudiantRandom()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "etudiants.h"
#include "supermat.h"
int main() {
    Etudiant tab[MAX_ETUDIANTS];
    int n = 0;
    int choix, numero;

    do {
        printf("\n===== Menu Etudiants =====\n");
        printf("8. Afficher un étudiant aléatoire\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);


        switch (choix) {
           case 8:
                afficherEtudiantRandom(tab, n);
                break;
                
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);


    return 0;
}
