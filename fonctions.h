#ifndef FONCTION_H
#define FONCTION_H

// Déclarations des structures
typedef struct {
    int numero;   // Numéro de l'étudiant
    char nom[50]; // Nom de l'étudiant
    float note;   // Note de l'étudiant
} Etudiant;

// Déclaration de la fonction afficherEtudiantsParMerite
void afficherEtudiantsParMerite(Etudiant VETU[], int SUIVANT[], int NBETU);
#endif // FONCTION_H
