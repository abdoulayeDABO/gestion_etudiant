#include <stdio.h>
#include <stdlib.h>
#include "etudiants.h"

#define MAX_ETUDIANTS 100


int main() {
    Etudiant VETU[MAX_ETUDIANTS];
    int NBETU;
    int SUIVANT[MAX_ETUDIANTS];
    int DEB;
    int choix, numero, ordre;

    restaurer_donnees(VETU, &NBETU);

    do {
        printf("\nMenu:\n");
        printf("1. Saisir les etudiants\n");
        printf("2. Ajouter un etudiant\n");
        printf("3. Supprimer un etudiant\n");
        printf("4. Afficher les etudiants\n");
        printf("5. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez le nombre d'etudiants: ");
                scanf("%d", &NBETU);
                saisir_etudiants(VETU, NBETU);
                break;
            case 2:
                ajouter_etudiant(VETU, &NBETU);
                break;
            case 3:
                printf("Entrez le numero de l'etudiant à supprimer: ");
                scanf("%d", &numero);
                supprimer_etudiant(VETU, &NBETU, numero);
                break;
            case 4:
                printf("Choisissez l'ordre d'affichage:\n");
                printf("1. Alphabetique\n");
                printf("2. Merite\n");
                printf("3. Aleatoire\n");
                printf("Entrez votre choix: ");
                scanf("%d", &ordre);

                switch (ordre) {
                    case 1:
                        trier_par_nom(VETU, NBETU);
                        break;
                    case 2:
                        trier_par_note(VETU, NBETU);
                        break;
                    case 3:
                        trier_aleatoire(VETU, NBETU);
                        break;
                    default:
                        printf("Option invalide. Affichage par defaut.\n");
                }

                afficher_etudiants(VETU, NBETU);
                break;
            case 5:
                sauvegarder_donnees(VETU, NBETU);
                printf("Au revoir!\n");
                break;
            default:
                printf("Option invalide. Veuillez reessayer.\n");
        }
    } while (choix != 5);

    return 0;
}
