#include "garauThomasListeInt.h"

/*
affiche un message en console 
@input : void
@output : int, le choix de l'utilisateur
@postcondition : retourne le choix de l'utilisateur
*/
int menu()
{
    int choix = 0;
    printf("1 Creer une liste d'entiers compris entre 0 et 20 de taille aleatoire comprise entre 1 et 20\n"
        "2 Ajouter un élément entier aléatoire (compris entre 0 et 20) en tête de liste\n"
        "3 Inserer un élément entier aléatoire dans sa place dans la liste suivant l'ordre croissant des premiers éléments\n"
        "4 Supprimer l'élément de tête\n"
        "5 Supprimer tous les maillons d'une valeur donnee\n"
        "6 Detruire liste\n"
        "7 Sauver la liste courante en binaire dans le fichier \"saveliste.bin\"\n"
        "8 Charger une liste depuis le fichier \"savelist.bin\"\n");

    scanf("%d", &choix);
    //reinitialise le scanf 
    rewind(stdin);

    return choix;
}


int main()
{
    maillon_int* premier = NULL;
    maillon_int* nouveau;
    int fin = 0;
    int i, nb;

    srand((unsigned)time(NULL));
    while (!fin) {
        i = menu();
        switch (i) {

        case 1: //Creer une liste de taille aleatoire
            detruire_liste2(&premier);
            nb = 1 + rand() % 20;
            while (i < nb){
                nouveau = init_elt();
                ajout_tete_v2(&premier, nouveau);
                i++;
            }
            break;

        case 2: // Ajouter
            nouveau = init_elt();
            ajout_tete_v2(&premier, nouveau);
            break;

        case 3: // Inserer (ordre croissant)
            nouveau = init_elt();
            inserer2(&premier, nouveau);
            break;

        case 4: //Supprimer debut:
            supprimer_debut(&premier);
            break;

        case 5: // Supprimer un maillon d'une valeur donnee
        //scanf et rewind pas oublié
            parcourir(premier);
            scanf("%d blblblblbl", &nb);
            critere_supp_un2(&premier, nb);
            //rewind(nb);
            break;

        case 6: // detruire liste
            detruire_liste2(&premier);
            break;

        case 7: // Sauver liste
            sauver_liste(premier);
            break;

        case 8: // Charger liste
            premier = load_liste();
            break;

        default:
            break;
        }
        
    }

    return 0;
}