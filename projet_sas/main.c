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

void afficher_details_etudiant(Etudiant etd) {
    int num,i;
    printf("Entrez le numero de letudiant a afficher : ");
    scanf("%d", &num);

    for (i = 0; i < nbr; i++) {
        if (etudiants[i].num == num) {
            printf("Numro : %d\n", etd.num);
            printf("Nom : %s\n", etd.nom);
            printf("Prenom : %s\n", etd.prenom);
            printf("Date de naissance : %s\n", etd.date);
            printf("Departement : %s\n", etd.departement);
            printf("Note generale : %.2f\n", etd.note);
            return;
        }
    }
}

void calculer_moyenne_generale() {
    float note_total= 0;
    int compter= 0;
    float moyenne_par_departement[MAX_ETUDIANTS] = {0};
    int compter_par_departement[MAX_ETUDIANTS] = {0};
    char departements[MAX_ETUDIANTS][MAX_DEPARTEMENT];
    int num_departements = 0;
    int i;

    for (i = 0; i < nbr; i++) {
        note_total += etudiants[i].note;
        compter++;
    }

    printf("Moyenne generale de luniversite : %.2f\n", note_total / compter);

    for (i = 0; i < num_departements; i++) {
        printf("Moyenne pour le departement %s : %.2f\n", departements[i], moyenne_par_departement[i] / compter_par_departement[i]);
    }
}

void rechercher_etudiant_par_nom() {
    char nom[MAX_NOM];
    int i;
    printf("Entrez le nom de l etudiant a rechercher : ");
    scanf("%s", nom);

    for (i = 0; i < nbr; i++) {
        if (strcmp(etudiants[i].nom, nom) == 0) {
            afficher_details_etudiant(etudiants[i]);
            return;
        }
        else{
            printf("Étudiant non trouvé.\n");
        }
    }
}

void afficher_etd_par_departement() {
    char departement[MAX_DEPARTEMENT];
    int i;
    printf("Entrez le departement : ");
    scanf("%s", departement);

    printf("Liste des etudiants inscrits dans ce departement %s :\n", departement);
    for (i = 0; i < nbr; i++) {
        if (strcmp(etudiants[i].departement, departement) == 0) {
            afficher_details_etudiant(etudiants[i]);
        }
    }
}
