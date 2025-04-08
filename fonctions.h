#ifndef FONCTION_H
#define FONCTION_H

// Déclarations des structures
typedef struct {
    int numero;
    char nom[50];
    float note;
} Etudiant;

// Déclaration de la fonction afficherEtudiantsParMerite
void afficherEtudiantsParMerite(Etudiant VETU[], int SUIVANT[], int NBETU);
#endif // FONCTION_H
