#ifndef FONCTION_A_INCLURE
#define FONCTION_A_INCLURE

//definition d'un type qui donne le numero, le nom et la note de l'etudiant

typedef struct {
  int numero;
  char *nom;
  float note;
} Etudiant;

//declaration de la procedure qui permet de vider le buffer apres chaque saisi
void viderBuffer(void);

//declaration de la procedure qui permet la sauvegarde
void sauvegarderListe(Etudiant *liste[], const char *nomFichier);

//declaration de la procedure qui permet d'afficher toute les etudiants.
void afficherListe(Etudiant *liste[]);

//une procedure qui permet de nettoyer les allocations faites au cours de l'execution du programme
void nettoyerMemoire(Etudiant *liste[]);

// cette fonction permet de trouver une place disponible pour ajouter un nouveau etudiant
int trouverIndex(Etudiant *liste[]);

//une procedure qui permet d'ajouter un etudiant dans la liste
void ajouterEtudiant (Etudiant *liste[], int position, int numero, char *nom, float note);

//une procedure qui permet de dialoguer afin d'obtenir les informations du nouveau etudiant
void saisirEtudiant(Etudiant *VETU[]);

//cette fonction permet de trouver l'emplacement de l'etudiant qu'on veut supprimer
int supprimerIndex(Etudiant *liste[], int numero);

//cette procedure permet de supprimer l'etudiant de la liste
void supprimer(Etudiant *liste[], int position);

//cette procedure permet de dialoguer pour obtenir les informations de l'etudiant qu'on veut supprimer
void supprimerEtudiant(Etudiant *VETU[]);


//cette procedure permet de restaurer les informations de la derniere executions
void restaurerListe(Etudiant *liste[], const char *nomFichier);

#endif
