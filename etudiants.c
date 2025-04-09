#include <stdio.h>
#include <string.h>
#include "etudiants.h"


void saisir_etudiants(Etudiant VETU[], int NBETU) {
    for (int i = 0; i < NBETU; i++) {
        printf("Entrez les informations de l'étudiant %d:\n", i + 1);
        printf("Numéro: ");
        scanf("%d", &VETU[i].numero);
        printf("Nom: ");
        scanf("%s", VETU[i].nom);
        printf("Note: ");
        scanf("%d", &VETU[i].note);
    }
}


void chainer_etudiants(Etudiant VETU[], int NBETU, int SUIVANT[], int *DEB) {
    // Initialiser le tableau SUIVANT à 0
    for (int i = 0; i < NBETU; i++) {
        SUIVANT[i] = 0;
    }

    // Trouver l'étudiant avec la plus grande note
    *DEB = 0;
    for (int i = 1; i < NBETU; i++) {
        if (VETU[i].note > VETU[*DEB].note) {
            *DEB = i;
        }
    }

    // Remplir le tableau SUIVANT
    for (int i = 0; i < NBETU; i++) {
        int max_suivant = -1;
        int max_note = -1;
        for (int j = 0; j < NBETU; j++) {
            if (VETU[j].note <= VETU[i].note && VETU[j].note > max_note) {
                max_note = VETU[j].note;
                max_suivant = j;
            }
        }
        SUIVANT[i] = max_suivant;
    }
}


void afficher_resultats(Etudiant VETU[], int SUIVANT[], int DEB) {
    int current = DEB;
    int rank = 1;

    printf("Classement par ordre de mérite:\n");
    while (current != -1) {
        printf("%d. Numéro: %d, Nom: %s, Note: %d\n", rank, VETU[current].numero, VETU[current].nom, VETU[current].note);
        current = SUIVANT[current];
        rank++;
    }
}


void afficher_etudiants(Etudiant VETU[], int NBETU) {
    printf("\nListe des étudiants:\n");
    printf("-------------------\n");
    for (int i = 0; i < NBETU; i++) {
        printf("Étudiant %d:\n", i + 1);
        printf("  Numéro: %d\n", VETU[i].numero);
        printf("  Nom: %s\n", VETU[i].nom);
        printf("  Note: %d\n", VETU[i].note);
        printf("-------------------\n");
    }
}

void ajouter_etudiant(Etudiant VETU[], int *NBETU) {
    if (*NBETU >= MAX_ETUDIANTS) {
        printf("Impossible d'ajouter un étudiant. La liste est pleine.\n");
        return;
    }

    printf("Entrez les informations du nouvel étudiant:\n");
    printf("Numéro: ");
    scanf("%d", &VETU[*NBETU].numero);
    printf("Nom: ");
    scanf("%s", VETU[*NBETU].nom);
    printf("Note: ");
    scanf("%d", &VETU[*NBETU].note);

    (*NBETU)++;
}


void supprimer_etudiant(Etudiant VETU[], int *NBETU, int numero) {
    int index = -1;
    for (int i = 0; i < *NBETU; i++) {
        if (VETU[i].numero == numero) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Étudiant avec le numéro %d non trouvé.\n", numero);
        return;
    }

    // Déplacer le dernier étudiant à la position de l'étudiant supprimé
    VETU[index] = VETU[*NBETU - 1];
    (*NBETU)--;
}

void sauvegarder_donnees(Etudiant VETU[], int NBETU) {
    FILE *fichier = fopen(FICHIER_SAUVEGARDE, "wb");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour sauvegarde.\n");
        return;
    }

    fwrite(&NBETU, sizeof(int), 1, fichier);
    fwrite(VETU, sizeof(Etudiant), NBETU, fichier);

    fclose(fichier);
    printf("Données sauvegardées avec succès.\n");
}

void restaurer_donnees(Etudiant VETU[], int *NBETU) {
    FILE *fichier = fopen(FICHIER_SAUVEGARDE, "rb");
    if (fichier == NULL) {
        printf("Aucun fichier de sauvegarde trouvé. Commencement avec une nouvelle liste.\n");
        *NBETU = 0;
        return;
    }

    fread(NBETU, sizeof(int), 1, fichier);
    fread(VETU, sizeof(Etudiant), *NBETU, fichier);

    fclose(fichier);
    printf("Données restaurées avec succès.\n");
}

void trier_par_nom(Etudiant VETU[], int NBETU) {
    for (int i = 0; i < NBETU - 1; i++) {
        for (int j = i + 1; j < NBETU; j++) {
            if (strcmp(VETU[i].nom, VETU[j].nom) > 0) {
                Etudiant temp = VETU[i];
                VETU[i] = VETU[j];
                VETU[j] = temp;
            }
        }
    }
}

void trier_par_note(Etudiant VETU[], int NBETU) {
    for (int i = 0; i < NBETU - 1; i++) {
        for (int j = i + 1; j < NBETU; j++) {
            if (VETU[i].note < VETU[j].note) {
                Etudiant temp = VETU[i];
                VETU[i] = VETU[j];
                VETU[j] = temp;
            }
        }
    }
}

void trier_aleatoire(Etudiant VETU[], int NBETU) {
    srand(time(NULL));
    for (int i = NBETU - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Etudiant temp = VETU[i];
        VETU[i] = VETU[j];
        VETU[j] = temp;
    }
}
