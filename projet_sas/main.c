#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 2000
#define MAX_DEPARTEMENT 20
#define MAX_NOM 20
#define MAX_PRENOM 20


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

void afficher_details_etudiant() {
    int num,i;
    printf("Entrez le numero de letudiant a afficher : ");
    scanf("%d", &num);

    for (i = 0; i < nbr; i++) {
        if (etudiants[i].num == num) {
            printf("Numro : %d\n",etudiants[i].num);
            printf("Nom : %s\n",etudiants[i].nom);
            printf("Prenom : %s\n",etudiants[i].prenom);
            printf("Date de naissance : %s\n",etudiants[i].date);
            printf("Departement : %s\n",etudiants[i].departement);
            printf("Note generale : %.2f\n",etudiants[i].note);
            return;
        }
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

void afficher_liste_etudiants() {
    char departement[MAX_DEPARTEMENT];
    int i;
    int trouve = 0;
    printf("Entrez le departement : ");
    scanf("%s", departement);

    printf("Liste des etudiants inscrits dans le departement %s : \n", departement);
    for (i = 0; i < nbr; i++) {
        if (strcmp(etudiants[i].departement, departement) == 0) {
            printf("Numero : %d\n", etudiants[i].num);
            printf("Nom : %s\n", etudiants[i].nom);
            printf("Prenom : %s\n", etudiants[i].prenom);
            printf("Date de naissance : %s\n", etudiants[i].date);
            printf("Departement : %s\n", etudiants[i].departement);
            printf("Note generale : %.2f\n", etudiants[i].note);
            printf("\n");
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucun etudiant trouve dans ce departement.\n");
    }
}

void calculer_moyenne_generale() {
    float note_total = 0;
    int compter = 0;
    float moyenne_dep[MAX_ETUDIANTS] = {0};
    int compter_dep[MAX_ETUDIANTS] = {0};
    char departements[MAX_ETUDIANTS][MAX_DEPARTEMENT];
    int num_dep = 0;
    int i,j;
    int dep_index = -1;

    for (i = 0; i < nbr; i++) {
        note_total += etudiants[i].note;
        compter++;

        for (j = 0; j < num_dep; j++) {
            if (strcmp(departements[j], etudiants[i].departement) == 0) {
                dep_index = j;
                break;
            }
        }

        if (dep_index == -1) {
            dep_index = num_dep++;
            strcpy(departements[dep_index], etudiants[i].departement);
        }

        moyenne_dep[dep_index] += etudiants[i].note;
        compter_dep[dep_index]++;
    }

    if (compter > 0) {
        printf("Moyenne generale de l'universite: %.2f\n", note_total / compter);
    }

    for (i = 0; i < num_dep; i++) {
        if (compter_dep[i] > 0) {
            printf("Moyenne pour le departement %s: %.2f\n", departements[i],
                   moyenne_dep[i] / compter_dep[i]);
        }
    }
}

void statistiques(){
    int i;
    int nbr_dep[MAX_ETUDIANTS]={0};
    char departements[MAX_ETUDIANTS][MAX_DEPARTEMENT];
    int num_dep=0;
    float seuil;
    int nbr_reussite[MAX_ETUDIANTS]={0};
    int dep_index= -1;
    char departement[MAX_DEPARTEMENT];


    //Afficher le nombre total d'étudiants inscrits:
    printf("nombre total d'étudiants inscrits:%d\n",nbr);

    //Afficher le nombre d'étudiants dans chaque département.
    printf("nombre d'étudiants dans chaque département:\n");
    for(i=0;i<num_dep;i++){
        printf("departement %s:%d\n",departements[i],nbr_dep[i]);
    }

    //Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil.
    printf("entrer le seuil de la moyenne generale:");
    scanf("%f",&seuil);
    printf("les etudiants avec une moyenne generale superieure a %.2f:\n",seuil);
    for(i=0;i<nbr;i++){
        if(etudiants[i].note>seuil){
            printf("Numero : %d\n", etudiants[i].num);
            printf("Nom : %s\n", etudiants[i].nom);
            printf("Prenom : %s\n", etudiants[i].prenom);
            printf("Date de naissance : %s\n", etudiants[i].date);
            printf("Departement : %s\n", etudiants[i].departement);
            printf("Note generale : %.2f\n", etudiants[i].note);
            printf("\n");
        }
    }

    //Afficher le nombre d'étudiants ayant réussi dans chaque département:
    for(i=0;i<nbr;i++){
        if(etudiants[i].note>=10.00){
            if(dep_index!= -1){
                nbr_reussite[dep_index]++;
            }
        }
    }
    printf("Afficher le nombre d'étudiants ayant réussi dans chaque département:\n");
    for(i=0;i<num_dep;i++){
        printf("departement %s:%d\n",departement[i],nbr_reussite[i]);
    }
}

int main(){
    int choix;
    do{
        printf("MENU: \n");
        printf("1= Ajouter un etudiant\n");
        printf("2= Modifier un etudiant\n");
        printf("3= Supprimer un etudiant\n");
        printf("4= Afficher les détails d'un étudiant\n");
        printf("5= Rechercher un étudiant par son nom\n");
        printf("6= Afficher la liste des étudiants inscrits dans un département spécifique\n");
        printf("7= Calculer la moyenne générale\n");
        printf("8= Statistiques\n");
        printf("entrer votre choix:");
        scanf("%d",&choix);

        switch(choix){
            case 1:
                ajouter_etudiant();
                break;
            case 2:
                modifier_etudiant();
                break;
            case 3:
                supprimer_etudiant();
                break;
            case 4:
                afficher_details_etudiant();
                break;
            case 5:
                rechercher_etudiant_par_nom();
                break;
            case 6:
                afficher_liste_etudiants();
                break;
            case 7:
                calculer_moyenne_generale();
                break;
            case 8:
                statistiques();
                break;
            default:
                printf("choix invalide. \n");

        }
    }while(choix!=0);
    return 0;
}
