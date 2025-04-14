#include <stdio.h>
#include <string.h>
#include "etudiants.h"


void saisir_etudiants(Etudiant VETU[], int nb_ajout, int *NBETU) {
    int nb_place_dispo = MAX_ETUDIANTS - *NBETU;
    if (nb_ajout < 0 || nb_ajout > MAX_ETUDIANTS || nb_ajout > nb_place_dispo) {
        printf("Erreur !\n");
        printf("  - Nombre de place disponible: %d\n", MAX_ETUDIANTS - *NBETU);
        printf("  - Le nombre d'etudiants doit etre compris entre 0 et %d.\n", MAX_ETUDIANTS);
        printf("  - Le nombre d'etudiants depasse la limite autorisee.\n");
        return;
    }
    for (int i = *NBETU; i < nb_ajout; i++) {
        ajouter_etudiant(VETU, NBETU);
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
        printf("%d. Numero: %d, Prenom: %s, Nom: %s, Note: %d\n", rank, VETU[current].numero, VETU[current].prenom, VETU[current].nom, VETU[current].note);
        current = SUIVANT[current];
        rank++;
    }
}


void afficher_etudiants(Etudiant VETU[], int NBETU) {

    printf("\nListe des etudiants:\n");
    printf("Effectif total: %d\n", NBETU);
    printf("-------------------\n");
    for (int i = 0; i < NBETU; i++) {
        printf("Etudiant %d:\n", i + 1);
        printf("  Numero:   %d\n", VETU[i].numero);
        printf("  Prenom:   %s\n", VETU[i].prenom);
        printf("  Nom:      %s\n", VETU[i].nom);
        printf("  Note:     %d\n", VETU[i].note);
        printf("-------------------\n");
    }
}

void ajouter_etudiant(Etudiant VETU[], int *NBETU) {
    if (*NBETU >= MAX_ETUDIANTS) {
        printf("Impossible d'ajouter un etudiant. La liste est pleine.\n");
        return;
    }
    printf("Entrez les informations du nouvel etudiant:\n");
    printf("Numero: ");
    scanf("%d", &VETU[*NBETU].numero);
    printf("Prenom: ");
    scanf("%s", VETU[*NBETU].prenom);
    printf("Nom: ");
    scanf("%s", VETU[*NBETU].nom);
    printf("Note: ");
    scanf("%d", &VETU[*NBETU].note);
    while(VETU[*NBETU].note < 0 || VETU[*NBETU].note > 20)
    {
        printf("Entrez la note de l'etudiant (0-20): ");
        scanf("%d", &VETU[*NBETU].note);
    }
    printf("Etudiant ajoute avec succes.\n");
    (*NBETU)++;
    printf("Nombre total d'etudiants: %d\n", *NBETU);
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
        printf("Etudiant avec le numero %d non trouve.\n", numero);
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
    printf("Donnees sauvegardees avec succes.\n");
}

void restaurer_donnees(Etudiant VETU[], int *NBETU) {
    FILE *fichier = fopen(FICHIER_SAUVEGARDE, "rb");
    if (fichier == NULL) {
        printf("Aucun fichier de sauvegarde trouve. Commencement avec une nouvelle liste.\n");
        *NBETU = 0;
        return;
    }

    fread(NBETU, sizeof(int), 1, fichier);
    fread(VETU, sizeof(Etudiant), *NBETU, fichier);

    fclose(fichier);
    printf("Donnees restaurees avec succes.\n");
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
