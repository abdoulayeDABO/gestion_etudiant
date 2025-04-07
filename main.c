#include <stdio.h>
#include "fonction.h"


int main() {
    printf("Hello, World!\n");
    return 0;
}

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
