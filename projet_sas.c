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

void modifier_etudiant() {
    int num;
    printf("Entrez le numero de l etudiant a modifier : ");
    scanf("%d", &num);
    for (int i = 0; i < nbr; i++) {
        if (etudiants[i].num == num) {
            printf("Modifier le nom : ");
            scanf("%s", etudiants[i].nom);
            printf("Modifier le prenom : ");
            scanf("%s", etudiants[i].prenom);
            printf("Modifier la date de naissance (jour/mois/anne) : ");
            scanf("%s", etudiants[i].date);
            printf("Modifier le departement : ");
            scanf("%s", etudiants[i].departement);
            printf("Modifier la note generale : ");
            scanf("%f", &etudiants[i].note);
             printf("Etudiant modifie avec succes.\n");
            return;
        }
    }
}

void supprimer_etudiant() {
    int num;
    int i,j;
    printf("Entrez le numro de letudiant a supprimer : ");
    scanf("%d", &num);

    for (i = 0; i < nbr; i++) {
        if (etudiants[i].num == num) {
            for (j = i; j < nbr-1; j++) {
                etudiants[j] = etudiants[j + 1];
            }
            nbr--;
            printf("Etudiant supprime avec succes.\n");
            return;
        }
    }
}