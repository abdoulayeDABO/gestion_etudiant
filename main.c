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
        printf("1. Saisir les étudiants\n");
        printf("2. Ajouter un étudiant\n");
        printf("3. Supprimer un étudiant\n");
        printf("4. Afficher les étudiants\n");
        printf("5. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez le nombre d'étudiants: ");
                scanf("%d", &NBETU);
                saisir_etudiants(VETU, NBETU);
                break;
            case 2:
                ajouter_etudiant(VETU, &NBETU);
                break;
            case 3:
                printf("Entrez le numéro de l'étudiant à supprimer: ");
                scanf("%d", &numero);
                supprimer_etudiant(VETU, &NBETU, numero);
                break;
            case 4:
                printf("Choisissez l'ordre d'affichage:\n");
                printf("1. Alphabétique\n");
                printf("2. Mérite\n");
                printf("3. Aléatoire\n");
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
                        printf("Option invalide. Affichage par défaut.\n");
                }

                afficher_etudiants(VETU, NBETU);
                break;
            case 5:
                sauvegarder_donnees(VETU, NBETU);
                printf("Au revoir!\n");
                break;
            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    } while (choix != 5);

    return 0;
}
