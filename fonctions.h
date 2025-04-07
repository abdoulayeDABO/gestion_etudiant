#ifndef ETUDIANTS_H
#define ETUDIANTS_H

#define MAX_ETUDIANTS 100
#define TAILLE_NOM 50

typedef struct {
    int numero;
    char nom[TAILLE_NOM];
    float note;
} Etudiant;


// Prototype de la fonction afficherEtudiantRandom
void afficherEtudiantRandom(const Etudiant tab[], int n);

#endif

