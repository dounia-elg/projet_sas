#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    char nom[20];
    char prenom[20];
    char date[11];
    int id_dep;
    float note;
} Etudiant;

typedef struct {
    int id_dep;
    char nom_dep[20];
    float m_generel;
} Departement;

Departement tab_dep[5];
Etudiant tab_etd[2000];
int nbr_etd = 0;
int nbr_dep = 0;

void ajouter_departement() {

    printf("donner id du departement : ");
    scanf("%d", &tab_dep[nbr_dep].id_dep);
    printf("donner le nom du departement : ");
    scanf("%s", tab_dep[nbr_dep].nom_dep);
    nbr_dep++;
    printf("departement ajoute avec succes.\n");
}

void ajouter_etudiant() {
    printf("entrez le numero : ");
    scanf("%d", &tab_etd[nbr_etd].num);
    printf("entrez le nom : ");
    scanf("%s", tab_etd[nbr_etd].nom);
    printf("entrez le prenom : ");
    scanf("%s", tab_etd[nbr_etd].prenom);
    printf("entrez la date de naissance (jour/mois/annee) : ");
    scanf("%s", tab_etd[nbr_etd].date);

    printf("liste des departements :\n");
    for (int i = 0; i < nbr_dep; i++) {
        printf("id: %d, nom: %s\n", tab_dep[i].id_dep, tab_dep[i].nom_dep);
    }

    printf("entrez id du departement : ");
    scanf("%d", &tab_etd[nbr_etd].id_dep);
    printf("entrez la note generale : ");
    scanf("%f", &tab_etd[nbr_etd].note);
    nbr_etd++;
    printf("etudiant ajoute avec succes.\n");
}

void modifier_etudiant() {
    int num;
    printf("entrez le numero de l etudiant a modifier : ");
    scanf("%d", &num);
    for (int i = 0; i < nbr_etd; i++) {
        if (tab_etd[i].num == num) {
            printf("modifier le nom : ");
            scanf("%s", tab_etd[i].nom);
            printf("modifier le prénom : ");
            scanf("%s", tab_etd[i].prenom);
            printf("modifier la date de naissance (jour/mois/annee) : ");
            scanf("%s", tab_etd[i].date);
            printf("modifier le departement (id) : ");
            scanf("%d", &tab_etd[i].id_dep);
            printf("modifier la note generale : ");
            scanf("%f", &tab_etd[i].note);
            printf("etudiant modifie avec succes.\n");
            return;
        }
    }
}

void supprimer_etudiant() {
    int num;
    printf("entrez le numero de l etudiant a supprimer : ");
    scanf("%d", &num);

    for (int i = 0; i < nbr_etd; i++) {
        if (tab_etd[i].num == num) {
            for (int j = i; j < nbr_etd - 1; j++) {
                tab_etd[j] = tab_etd[j + 1];
            }
            nbr_etd--;
            printf("etudiant supprime avec succes.\n");
            return;
        }
    }
}

void afficher_details_etudiant(int num) {
    for (int i = 0; i < nbr_etd; i++) {
        if (tab_etd[i].num == num) {
            printf("Numero : %d\n", tab_etd[i].num);
            printf("Nom : %s\n", tab_etd[i].nom);
            printf("Prenom : %s\n", tab_etd[i].prenom);
            printf("Date de naissance : %s\n", tab_etd[i].date);

            for (int j = 0; j < nbr_dep; j++) {
                if (tab_dep[j].id_dep == tab_etd[i].id_dep) {
                    printf("Departement : %s\n", tab_dep[j].nom_dep);
                    break;
                }
            }
            printf("Note generale : %.2f\n", tab_etd[i].note);
            return;
        }
    }
}

void rechercher_etudiant_par_nom() {
    char nom[20];
    int i;
    printf("entrez le nom de l etudiant a rechercher : ");
    scanf("%s", nom);

    for (i = 0; i < nbr_etd; i++) {
        if (strcmp(tab_etd[i].nom, nom) == 0) {
            afficher_details_etudiant(tab_etd[i].num);
            return;
        }
    }
}

void afficher_liste_etudiants() {
    int id_dep;
    int i;
    printf("entrez id du departement : ");
    scanf("%d", &id_dep);

    printf("liste des etudiants inscrits dans le departement id %d :\n", id_dep);
    for (i = 0; i < nbr_etd; i++) {
        if (tab_etd[i].id_dep == id_dep) {
            afficher_details_etudiant(tab_etd[i].num);
            printf("\n");
        }
    }
}

void calculer_moyenne_generale() {
    float somme = 0;
    int count = 0;

    for (int i = 0; i < nbr_etd; i++) {
        somme += tab_etd[i].note;
        count++;
    }

    if (count > 0) {
        printf("moyenne generale de luniversite : %.2f\n", somme / count);
    }
    // Moyenne par département
    for (int i = 0; i < nbr_dep; i++) {
        somme = 0;
        count = 0;
        for (int j = 0; j < nbr_etd; j++) {
            if (tab_etd[j].id_dep == tab_dep[i].id_dep) {
                somme += tab_etd[j].note;
                count++;
            }
        }
        if (count > 0) {
            printf("moyenne generale pour le departement %s : %.2f\n", tab_dep[i].nom_dep, somme / count);
        }
    }
}

void tri_par_note() {
    Etudiant tri_note[2000];

    // Copier les etudiants du tableau principal dans un tableau temporaire
    for (int i = 0; i < nbr_etd; i++) {
        tri_note[i] = tab_etd[i];
    }
    // tri des etudiants par note en ordre decroissant
    for (int i = 0; i < nbr_etd - 1; i++) {
        for (int j = i + 1; j < nbr_etd; j++) {
            if (tri_note[i].note < tri_note[j].note) {
                Etudiant temp = tri_note[i];
                tri_note[i] = tri_note[j];
                tri_note[j] = temp;
            }
        }
    }
    printf("tri des etudiants par note generale :\n");
    for (int i = 0; i < nbr_etd; i++) {
        printf("%s %s : %.2f\n", tri_note[i].nom, tri_note[i].prenom, tri_note[i].note);
    }
}

void tri_reussite(){
    Etudiant temp;
    int j = 0;
    for (int i = 0; i < nbr_etd; i++) {
        if (tab_etd[i].note >= 10) {
            temp = tab_etd[j];
            tab_etd[j] = tab_etd[i];
            tab_etd[i] = temp;
            j++;
        }
    }
    nbr_etd = j;
    tri_par_note(tab_etd, nbr_etd);
}

void tri_alfha() {
    Etudiant tab_alfha[2000];

    // copier les etudiants du tableau principal dans un tableau temporaire
    for(int i = 0; i < nbr_etd; i++) {
        tab_alfha[i] = tab_etd[i];
    }

    // tri des etudiants par ordre alpha
    for(int i = 0; i < nbr_etd - 1; i++) {
        for(int j = i + 1; j < nbr_etd; j++) {  
            if(strcmp(tab_alfha[i].nom, tab_alfha[j].nom) > 0) {
                Etudiant temp = tab_alfha[i];
                tab_alfha[i] = tab_alfha[j];
                tab_alfha[j] = temp;
            }
        }
    }
    printf("etudiants trie par ordre alphabetique :\n");
    for(int i = 0; i < nbr_etd; i++) {
        printf("%s %s : %.2f\n", tab_alfha[i].nom, tab_alfha[i].prenom, tab_alfha[i].note);
    }
}

void statistiques() {
    float seuil;
    int tab_reussie[20];

    //Afficher le nombre total d'étudiants inscrits
    printf("nombre total detudiants inscrits : %d\n", nbr_etd);

    //Afficher le nombre d'étudiants dans chaque département
    printf("nombre d etudiants par d epartement :\n");
    for (int i = 0; i < nbr_dep; i++) {
        int count = 0;
        for (int j = 0; j < nbr_etd; j++) {
            if (tab_etd[j].id_dep == tab_dep[i].id_dep) {
                count++;
            }
        }
        printf("%s : %d\n", tab_dep[i].nom_dep, count);
    }

    //Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil.
    printf("entrer le seuil de reussite : ");
    scanf("%f", &seuil);
    printf("etudiants ayant une note superieure ou egale a %.2f :\n", seuil);
    for (int i = 0; i < nbr_etd; i++) {
        if (tab_etd[i].note >= seuil) {
            afficher_details_etudiant(tab_etd[i].num);
            printf("\n");
        }
    }

    // Afficher les 3 étudiants ayant les meilleures notes
    Etudiant tri_meilleur[2000];

    // copier les etudiants du tableau principal dans un tableau temporaire
    for (int i = 0; i < nbr_etd; i++) {
        tri_meilleur[i] = tab_etd[i];
    }

    for (int i = 0; i < nbr_etd - 1; i++) {
        for (int j = i + 1; j < nbr_etd; j++) {
            if (tri_meilleur[i].note < tri_meilleur[j].note) {
                Etudiant temp = tri_meilleur[i];
                tri_meilleur[i] = tri_meilleur[j];
                tri_meilleur[j] = temp;
            }
        }
    }

    // Affichage des 3 étudiants ayant les meilleures notes
    printf("les 3 etudiants ayant les meilleures notes:\n");
    for (int i = 0; i < 3 && i < nbr_etd; i++) {  // Limiter à 3 étudiants
        printf("%s %s : %.2f\n", tri_meilleur[i].nom, tri_meilleur[i].prenom, tri_meilleur[i].note);
    }

    //Afficher le nombre d'étudiants ayant réussi dans chaque département
    printf("nombre detudiants ayant reussi (note >= 10) dans chaque departement :\n");
    for (int i = 0; i < nbr_dep; i++) {
        int count = 0;
        for (int j = 0; j < nbr_etd; j++) {
            if (tab_etd[j].id_dep == tab_dep[i].id_dep && tab_etd[j].note >= 10) {
                count++;
            }
        }
        printf("%s : %d\n", tab_dep[i].nom_dep, count);
    }
}

void afficher_menu() {
    printf("Menu:\n");
    printf("1. ajouter un etudiant\n");
    printf("2. modifier un etudiant\n");
    printf("3. supprimer un etudiant\n");
    printf("4. afficher les details dun etudiant\n");
    printf("5. calculer la moyenne generale\n");
    printf("6. rechercher un etudiant par nom\n");
    printf("7. afficher la liste des etudiants par departement\n");
    printf("8. statistiques\n");
    printf("9. trier les etudiants\n");
}

int main() {
    int choix;

    // Initialisation des départements
    tab_dep[0] = (Departement){1, "informatique", 0.0};
    tab_dep[1] = (Departement){2, "mathematique", 0.0};
    tab_dep[2] = (Departement){3, "physique", 0.0};
    tab_dep[3] = (Departement){4, "chimie", 0.0};
    tab_dep[4] = (Departement){5, "droit", 0.0};
    nbr_dep = 5;

    // Initialisation des étudiants
    tab_etd[0] = (Etudiant){1, "elgarrai", "dounia", "23/06/2004", 1, 12};
    tab_etd[1] = (Etudiant){2, "elmarjani", "ahmed", "15/03/1999", 1, 17};
    tab_etd[2] = (Etudiant){3, "jamili", "yassine", "22/07/2001", 2, 14.50};
    tab_etd[3] = (Etudiant){4, "zohra", "amal", "05/11/2003", 3, 8};
    tab_etd[4] = (Etudiant){5, "amrani", "manar", "19/12/1997", 5, 9.25};
    tab_etd[5] = (Etudiant){6, "imad", "imad", "31/01/2002", 4, 16.50};
    nbr_etd = 6;

    do {
        afficher_menu();
        printf("entrer votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_etudiant();
                break;
            case 2:
                modifier_etudiant();
                break;
            case 3:
                supprimer_etudiant();
                break;
            case 4: {
                int num;
                printf("entrez le numero de l etudiant : ");
                scanf("%d", &num);
                afficher_details_etudiant(num);
                break;
            }
            case 5:
                calculer_moyenne_generale();
                break;
            case 6:
                rechercher_etudiant_par_nom();
                break;
            case 7:
                afficher_liste_etudiants();
                break;
            case 8:
                statistiques();
                break;
            case 9: {
                int tri;
                printf("Choisir le type de tri :\n");
                printf("1. Tri alphabétique des étudiants en fonction de leur nom\n");
                printf("2. Tri des etudiants par note generale\n");
                printf("3. Tri des étudiants selon leur statut de réussite\n");
                printf("entrer votre choix : ");
                scanf("%d", &tri);

                switch (tri) {
                    case 1:
                        tri_alfha();
                        break;
                    case 2:
                        tri_par_note();
                        break;
                    case 3:
                        tri_reussite();
                        break;
                    default :
                        printf("tri invalide.\n");
                        break;
                }
                break;
            }
            default:
                printf("Choix invalide.\n");
                break;
        }
    } while (choix != 0);

    return 0;
}