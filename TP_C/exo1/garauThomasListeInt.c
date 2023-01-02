#include "garauThomasListeInt.h"

/*
Initialise un pointeur sur un maillon.Le maillon prend comme
valeur un nombre aléatoire compris entre 0 et 20 et comme successeur NULL.
@input : void
@output : pointeur sur un maillon_int
@postcondition : p_nv_elt a un nombre en 0 et 20 en value et un suivant à NULL 
*/
maillon_int* init_elt()
{
    //utilisation de malloc pour alouer dynamiquement de la mémoire au nouveau pointeur afin qu'il soit réutilisable en dehors de la fonction.
    maillon_int* p_nv_elt = malloc(sizeof(maillon_int));
    if (p_nv_elt != NULL){
        p_nv_elt->val = rand() % 21;
        p_nv_elt->p_suiv = NULL;
    }
    return p_nv_elt;
}

/*
ajoute un nouvelle élément comme tête de la chaine
@input : maillon_int* p_tete, pointeur actuelle sur la tête de la chaine de maillons; 
maillon_int* p_nv_elt, pointeur sur le noueaux maillons qui doit être placé en tête de la chaine.
@output : maillon_int* p_tete, retourne la nouvelle tete de la chaine 
@precondition : p_tete, p_nv_elt ne sont pas null
*/
maillon_int* ajout_tete_v1(maillon_int* p_tete, maillon_int* p_nv_elt)
{
    //met p_suiv sur la tete actuelle pour la faire devenir le second élément de la chaine
    //et ne pas perdre la totalité de la chaine.
    p_nv_elt->p_suiv = p_tete;
    //fait pointer p_tete sur le nouvel élément pour qu'il devienne la tete de chaine.
    p_tete = p_nv_elt;
    return p_tete;
}

/*
ajoute un nouvelle élément comme tête de la chaine en utilisant un pointeur sur un pointeur
@input maillon_int** p_p_tete, pointeur sur un pointeur de la tete de la chaine;
maillon_int* p_nv_elt, pointeur sur le nouveaux maillon qui doit être placé en tête de chaine.
@output : void
@postcondition : p_p_tete pointe sur le nouvel élément qui lui même a pour successeur l'ancienne tête.
@precondition : p_p_tete et p_nv_elt ne sont pas null 
*/
void ajout_tete_v2(maillon_int** p_p_tete, maillon_int* p_nv_elt)
{
    //fait de l'ancienne tête de chaine le successeur du nouvel élément.
    p_nv_elt->p_suiv = *p_p_tete;
    //fait du nouvel élément la nouvelle tête de chaine.
    *p_p_tete = p_nv_elt;
}

/*
affiche en console l'intégralité de la chaine
@input : maillon_int* p_tete, un pointeur sur le premier maillon de la chaine.
@output : void 

*/
void parcourir(maillon_int* p_tete)
{
    //verifie que la tête de la liste n'est pas aussi le dernier élément.
    if (p_tete == NULL)
        printf("liste vide");
    else
        //verifie que le maillon itérer n'est pas le dernier
        while (p_tete != NULL) {
            printf("%d--", p_tete->val);
            p_tete = p_tete->p_suiv;
        }
    putchar('\n');
}

/*
insert un nouveaux maillon dans la chaine de manière à ce qu'elle reste trié
@input : maillon_int* p_tete, la tete de la chaine;
maillon_int* p_nv_elt, pointeur sur le nouveaux maillon
@output : maillon_int* p_tete, la tête de la chaine.
@precondition : la liste est trié.
@postcondition : la chaine contien le nouveau maillon et est toujours triée.
*/
maillon_int* inserer1(maillon_int* p_tete, maillon_int* p_nv_elt)
{
    maillon_int* n, * prec;
    
    // si la valeur du nouvelle element est inférieur ou égale à la valeur de la tete
    // insere le nouvelle élément dans la chaine juste avant la tête 
    if (p_tete == NULL || p_nv_elt->val <= p_tete->val) {  
        p_nv_elt->p_suiv = p_tete;
        p_tete = p_nv_elt;
    }
    else {  
        //sinon itére sur la chaine jusqu'a trouvé l'elment plus petit que le nouvel élément ou
        // le dernière element de la chaine.
        n = prec = p_tete;
        while (n != NULL && p_nv_elt->val > n->val) {
            prec = n;
            n = n->p_suiv;
        }
        //insére le nouveaux maillon entre prec et psuiv
        p_nv_elt->p_suiv = n;
        prec->p_suiv = p_nv_elt;
    }
    return p_tete;
}


/*
insere un nouveaux maillon dans une chaine triée en utilisant un pointeur sur un pointeur.
@input : maillon_int** prem, pointeur sur pointeur du premier element de la chaine,
maillon_int* e, pointeur sur le nouveaux maillon
@output : void
@precondition : la chaine est trié
@postcondition : le nouveaux maillon est insérer dans la chaine, la chaine est toujours trié
*/
void inserer2(maillon_int** prem, maillon_int* e)
{
    maillon_int* n, * prec;
    if (*prem == NULL || e->val <= (*prem)->val){ 
        e->p_suiv = *prem;
        *prem = e;
    }
    else {  
        //sinon itére sur la chaine jusqu'a trouvé l'elment plus petit que le nouvel élément ou
        // le dernière element de la chaine.
        n = prec = *prem;
        while (n != NULL && e->val > n->val) {
            prec = n;
            n = n->p_suiv;
        }
        //insére le nouveaux maillon entre prec et psuiv
        e->p_suiv = n;
        prec->p_suiv = e;
    }
}

/*
supprime le premier maillon de la liste chainé en passant par un pointeur de pointeur
@input : maillon_int** prem, pointeur sur pointeur sur du premier maillon de la liste chainé
@output : void
@postcondition : la tete de la liste chainé pointe sur le second élément, la case
mémoire du premier élément est libérer 
*/
void supprimer_debut(maillon_int** prem)
{
    maillon_int* n;
    if (*prem != NULL) {
        //conserve l'adresse de l'élément à suppr
        n = *prem;
        *prem = (*prem)->p_suiv;
        //libére l'élément détruit 
        free(n);
    }
}

/*
supprime les maillon d'une liste chainé qui on la valeur val
@input : maillon_int* prem, pointeur sur le premier élément de la liste chainé,
int val, la valeur que l'on souhaite supprimer.
@output : maillon_int* prem, le pointeur sur le premier élément de la liste chainé
@precondition : val n'est pas null.
@postcondition : la liste chainé ne contient plus les élément de valeur val.
*/
maillon_int* critere_supp_un1(maillon_int* prem, int val)
{
    maillon_int* e = prem, * prec = NULL, * n;

    //verifie que ce n'est pas le dernier élément de la liste
    while (e != NULL) {
        n = NULL;
        //test si la valeur du maillon = val 
        //si c'est le cas supprime le maillon en question
        if (e->val == val) {
            n = e;
            //verifie si le maillon à supprimé avait un prédecesseur
            //si il n'en avait pas fait du maillon suivant la tête de la chaine
            if (prec == NULL)
                prem = e->p_suiv;
            else
                //si non fait que le successeur du maillon précedent soit le successeur du maillon à supprimé 
                prec->p_suiv = e->p_suiv;
        }
        else
            prec = e;
        //affect à e le maillon prochain    
        e = e->p_suiv;
        //si un maillon à été sortie de la liste chainé libére ca case mémoire
        if (n != NULL)
            free(n);
    }
    return prem;

}
/*
supprime tout les maillon de la liste chainé ayant pour valeur val en utilisant un pointeur sur un pointeur
@input : maillon_int** prem, première élément de la liste chainé;
int val, la valeur des maillon à supprimé
@output : void
@precondition : val n'est pas null
@postcondition : les maillon contenant la valeur val ne sont plus chainé dans la liste chainé
*/
void critere_supp_un2(maillon_int** prem, int val)
{
    maillon_int* e = *prem, * prec = NULL, * n;

    //verifie que ce n'est pas le dernier élément de la liste
    while (e != NULL) {
        n = NULL;
        //test si la valeur du maillon = val 
        //si c'est le cas supprime le maillon en question
        if (e->val == val) {
            n = e;
            //verifie si le maillon à supprimé avait un prédecesseur
            //si il n'en avait pas fait du maillon suivant la tête de la chaine
            if (prec == NULL)
                *prem = e->p_suiv;
            else
                prec->p_suiv = e->p_suiv;
        }
        else
            prec = e;
        //affect à e le maillon prochain    
        e = e->p_suiv;
        //si un maillon à été sortie de la liste chainé libére ca case mémoire
        if (n != NULL)
            free(n);
    }
}

/*
detruit une liste chaine est libére toute les zone mémoire utilisé par les maillons de cette dernière.
@input : maillon_int** prem , pointeur sur un pointeur du premiére élément de la liste chainé
@output : void
@postcondition : toute les zone mémoire utilisé par les différents maillons de la liste on été libérer
*/
void detruire_liste(maillon_int** prem)
{
    maillon_int* n;
    while (*prem != NULL) {
        n = *prem;
        *prem = (*prem)->p_suiv;
        free(n);
    }
}

/*
detruit une liste chaine est libére toute les zone mémoire utilisé par les maillons de cette dernière.
@input : maillon_int** prem , pointeur sur un pointeur du premiére élément de la liste chainé
@output : void
@postcondition : toute les zone mémoire utilisé par les différents maillons de la liste on été libérer
*/
void detruire_liste2(maillon_int** prem)
{
    while (*prem != NULL)
        //supprime_debut supprime le premiére élément de la liste chainé jusqu'à que la liste soit entièrement supprimé 
        supprimer_debut(prem);
    
}

/* Permet la sérialisation format binaire dans le fichier
"saveliste.bin" de la liste d'entier (maillon_int) dont
le pointeur sur le premier élément est passé en paramètre
@input : maillon_int * prem, pointeur sur l'élément de tête de la liste à sérialiser
@output : void
@precondition : le répertoire courant et le processus père permettent l'écriture 
                le pointeur prem, est soit NULL (aucune action) soit pointe sur
                le premier élément d'une liste d'entiers
@postcondition : le fichier saveliste.bin contient les éléments de la liste 
                dont le premier élément est pointé par prem. 
                Nota : il n'y a pas de libération de la mémoire occupée par la 
                liste. Il faut donc la détruire avant d'éventuellement la recharger.
*/
void sauver_liste(maillon_int* prem)
{
    //ouvrir un fichier binaire en écriture : suffixe b
    FILE* f=fopen("saveliste.bin", "wb");
    printf("Ouvertude du fichier %p\n",f);
    // si liste non vide
    if (prem != NULL) {
        if (f==NULL)
            fprintf(stderr,"erreur création fichier :%i\n",errno);
        else // parcourir la liste jusque fin
            while (prem != NULL) {
                // écrire chaque maillon en binaire
                if (1 !=fwrite(prem, sizeof(maillon_int), 1, f))
                    fprintf(stderr,"Erreur d'écriture du maillon %p\n",prem);
                else 
                // passer au maillon suivant
                prem = prem->p_suiv;
            }
            fclose(f);	// fermer le fichier
    }
    else
        fprintf(stderr,"pas de sauvegarde pour une liste vide\n");
}

maillon_int* load_liste()
{
    FILE* f;
    maillon_int* prem = NULL, * p, e;
    if ((f= fopen("saveliste.bin", "rb")) != NULL) {
        prem = malloc(sizeof(maillon_int));
        fread(prem, sizeof(maillon_int), 1, f);
        p = prem;
        while (fread(&e, sizeof(maillon_int), 1, f)) {
            p->p_suiv = malloc(sizeof(maillon_int));
            p = p->p_suiv;
            *p = e;
            p->p_suiv = NULL;
        }
        fclose(f);
    }
    else
        printf("erreur ou fichier inexistant");
    return prem;
}

