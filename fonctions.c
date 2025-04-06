//definition de la procedure quib permet de vider le buffer
void viderBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
      
    }
}

//sauvegarde des données de l'etudiant 
void sauvegarderListe(Etudiant *liste[], const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    if (!fichier) {
        perror("Erreur lors de l'ouverture du fichier de sauvegarde");
        return -1;
    }

    for (int i = 0; i < NBETU; i++) {
        if (liste[i] != NULL) {
            // on sauvegarde les informations dans le fichier dans le format : numero nom note
            fprintf(fichier, "%d;%s;%.2f\n", liste[i]->numero, liste[i]->nom, liste[i]->note);
        }
    }

    fclose(fichier);
}


//affichage des elements de la liste
void afficherListe(Etudiant *liste[]){
for (int i = 0; i < 100; i++){
    if (liste[i] == NULL) continue;
    printf ("\nle numero : %d\nle nom :%s\nla note : %.3f\n", liste[i]->numero, liste[i]->nom, liste[i]->note);
    printf("++++++++++++++++++++++++++++++++++++");
  }
}


//nettoyage de l'espace memoire occupee par nos variables
void nettoyerMemoire(Etudiant *liste[]){
  for (int i = 0; i < 100; i++){
    if (liste[i] == NULL) continue;
      if (liste[i]->nom != NULL)
      free(liste[i]->nom);
    free(liste[i]);
  }
}


//oú positionner le nouveau etudiant
int trouverIndex(Etudiant *liste[]){
 for (int i = 0 ; i < 100; i++){
 if(liste[i] == NULL) return i;
 }
 
 printf("Le nombre maximum d'etudiants est atteint.\n");
 return -1;
}

//ajout du nouveau etudiant
void ajouterEtudiant (Etudiant *liste[], int position, int numero, char *nom, float note){
  
  liste[position] = (Etudiant *)malloc(sizeof(Etudiant));
  if(liste[position] != NULL){
    liste[position]->numero = numero;
    liste[position]->nom = strdup(nom);
    liste[position]->note = note;
  }
}

//dialogue entre le programme et l'utilisateur pour inserer l'etudiant dans la liste
void saisirEtudiant(){
  int numero = -1;
  char nom[255];
  char *nomP = NULL;
  float note;
  
  printf("\n+--------------------------------------+\n");
  printf("| Saisir les inforamions de l'etudiant |");
  printf("\n+--------------------------------------+\n");
  printf("Numéro : ");
  do {
    scanf("%d", &numero);
  }while(numero < 0);
  viderBuffer();
  
  
  
  printf("Prénom et Nom : ");
  fgets(nom, sizeof(nom), stdin);
  nom[strcspn(nom, "\n")] = 0;

  while (strlen(nom) < 2) {
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = 0;
  }
  

  nomP = nom;
  printf("Note : ");
  do {
    scanf("%f", &note);
    viderBuffer();
  }while(note < 0 || note > 20);


  ajouterEtudiant(VETU, trouverIndex(VETU), numero, nomP, note);
}



//trouver l'emplacement de l'etudiant á supprimer
int supprimerIndex(Etudiant *liste[], int numero){
  for(int i = 0 ; i < 100; i++){
    if(liste[i] == NULL) continue;
    if(liste[i]->numero == numero) return i;
  }
  return -1;
}


// supprimer l'etudiant
void supprimer(Etudiant *liste[], int position){
  if (liste[position] != NULL) {
    if (liste[position]->nom != NULL)
      free(liste[position]->nom);
    free(liste[position]);
    liste[position] = NULL;
  }
}

//dialogue afin de supprimer l'etudiant
void supprimerEtudiant(){

  printf("+-----------------------------+\n");
  printf("| Suppression d'un Etudiant : |\n");
  printf("+-----------------------------+\n");
  int numero;
  printf("Numero de l'etudiant : ");
  scanf("%d", &numero);viderBuffer();
  
  int position = supprimerIndex(VETU,numero);
  supprimer(VETU, position);
}

void restaurerListe(Etudiant *liste[], const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (!fichier) {
        return -1;
    }

    char ligne[256];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        int numero;
        float note;
        char nom[200];

        // Extraire les infos à partir du format "numero;nom;note"
        if (sscanf(ligne, "%d;%199[^;];%f", &numero, nom, &note) == 3) {
            ajouterEtudiant(liste, trouverIndex(liste), numero, nom, note);
        }
    }

    fclose(fichier);
}
