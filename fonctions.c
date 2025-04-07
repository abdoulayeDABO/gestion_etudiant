
// # la fonction afficherEtudiantRandom()
#include <stdlib.h>
#include <time.h>

void afficherEtudiantRandom(const Etudiant tab[], int n) {
    if (n == 0) {
        printf("Aucun étudiant dans la liste.\n");
        return;
    }

    srand(time(NULL));  // Initialiser le générateur de nombres aléatoires
    int index = rand() % n;

    printf("Étudiant sélectionné aléatoirement :\n");
    printf("Numero : %d | Nom : %s | Note : %.2f\n",
           tab[index].numero, tab[index].nom, tab[index].note);
}
