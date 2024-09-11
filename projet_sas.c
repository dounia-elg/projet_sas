#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 2000
#define MAX_DEPARTEMENT 20
#define MAX_NOM 20
#define MAX_PRENOM 20
#define SEUIL 10.00

typedef struct{
    int num;
    char nom[MAX_NOM];
    char prenom[MAX_PRENOM];
    char date[11];
    char departement[MAX_DEPARTEMENT];
    float note;
}Etudiant;

Etudiant etudiants[MAX_ETUDIANTS];
int nbr= 0;

void ajouter_etudiant() {
    Etudiant etd;
    printf("Entrez le numero: ");
    scanf("%d", &etd.num);
    printf("Entrez le nom : ");
    scanf("%s", etd.nom);
    printf("Entrez le prenom : ");
    scanf("%s", etd.prenom);
    printf("Entrez la date de naissance (jour/mois/anne) : ");
    scanf("%s", etd.date);
    printf("Entrez le departement : ");
    scanf("%s", etd.departement);
    printf("Entrez la note generale : ");
    scanf("%f", &etd.note);
    
    etudiants[nbr] = etd;
    nbr++;
    printf("Etudiant ajoute avec succes.\n");
}