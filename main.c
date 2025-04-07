#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#define NBETU 100


int main(void){
  //Declaration 
  Etudiant *VETU[NBETU] = {NULL};
  restaurerListe(VETU, "etudiants.txt");
 
  saisirEtudiant(VETU);
  afficherListe(VETU);
  supprimerEtudiant(VETU);
  afficherListe(VETU);
  

  sauvegarderListe(VETU, "etudiants.txt");
  nettoyerMemoire(VETU);
}
