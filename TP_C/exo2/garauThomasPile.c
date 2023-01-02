#include "garauThomasPile.h"


/*
Initialise un pointeur sur élément d'une liste chainé.Le maillon prend comme
valeur un nombre aléatoire compris entre 0 et 20 et comme successeur NULL.
@input : void
@output : pointeur sur un maillon_int
@postcondition : p_nv_elt a un nombre en 0 et 20 en value et un suivant à NULL 
*/
Pile* init_elt()
{
    //utilisation de malloc pour alouer dynamiquement de la mémoire au nouveau pointeur afin qu'il soit réutilisable en dehors de la fonction.
    Pile* p_nv_elt = malloc(sizeof(Pile));
    if (p_nv_elt != NULL){
        p_nv_elt->val = rand() % 21;
        p_nv_elt->p_suiv = NULL;
    }
    return p_nv_elt;
}

/*
Initialise un pointeur sur un élément d'une liste chainé avec une valeur donné
@input : int val, la valeur que doit avoir l'élément
@output : pointeur sur un élément d'une liste chainé
@postcondition : l'élement a été créer et à la valeur souhaité
*/
Pile* init_not_random_elt(int val){
    Pile* p_nv_elt = malloc(sizeof(Pile));
    if (p_nv_elt != NULL){
        p_nv_elt->val = val;
        p_nv_elt->p_suiv = NULL;
    }
    return p_nv_elt;
}

/*
retourne un pointeur sur le dernier élément de la pile
@input : Pile* p_tete la tête de la pile
@output : Pile* p_tete pointeur sur dernier élement de la pile
@postcondition : un pointeur sur dernier élement de la pile est retourné
@precondition : la pile existe et contient au moins un élement
*/
Pile* get_tail(Pile* p_tete)
{
    if (p_tete == NULL)
        printf("liste vide");
    else
        //verifie que le maillon itérer n'est pas le dernier
        while (p_tete->p_suiv != NULL) {
            p_tete = p_tete->p_suiv;
        }
    return p_tete;
}

/*
retourne un pointeur sur l'avant  dernier élément de la pile
@input : Pile* p_tete la tête de la pile
@output : Pile* p_tete pointeur sur l'avant dernier élement de la pile
@postcondition : un pointeur sur l'avant dernier élement de la pile est retourné
@precondition : la pile existe et contient au moins un élement
*/
Pile* get_before_tail(Pile* p_tete){
       if (p_tete == NULL)
        printf("liste vide");
    else
        //verifie que le maillon itérer n'est pas l'avant dernier
        while (p_tete->p_suiv->p_suiv != NULL) {
            p_tete = p_tete->p_suiv;
        }
        get(p_tete);
    return p_tete;
}

/*
affiche la valeur du dernier élement de la pile
@input : Pile* p_tail pointeur sur le dernier élement de la pile
@output : void
@postcondition : le dernier élement de la pile est affiché en console
@precondition : la pile existe et contient au moins un élement, p_tail pointe bien sur le dernier élement de la pile
un get_tail a donc été fait avant
*/
void get(Pile* p_tail){
    printf("valeur de queu = %d\n", p_tail->val);
}

/*
empile un élement à la fin de la pile
@input : Pile** p_p_tail pointeur sur un pointeur sur le dernier élement de la pile;
Pile* p_nv_elt pointeur sur le nouvelle élement à empiler
@output : void
@postcondition : le nouvelle élement est ajouté à la fin de la pile
@precondition : la pile et le nouvelle élement existe , p_tail pointe bien sur le dernier élement de la pile
un get_tail a donc été fait avant
*/
void empile(Pile** p_p_tail, Pile* p_nv_elt){
    (*p_p_tail)->p_suiv = p_nv_elt;
    *p_p_tail = p_nv_elt;
}
/*
dépile le denrier élement de la pile
@input : Pile** p_p_tail pointeur sur un pointeur sur le dernier élement de la pile;
Pile* p_tete pointeur sur la tête de la pile
@output : int a, qui correspond à l'élement venant d'être supprimé 
@postcondition : le dernier élement de la pile a été supprimé
@precondition : la pile existe , p_tail pointe bien sur le dernier élement de la pile
un get_tail a donc été fait avant
*/
int depile(Pile** p_p_tail, Pile* p_tete){
    //pour conservé la valeur de l'élément avant de le supprimé afin de le retourné
    int a = (*p_p_tail)->val;
    Pile* test = NULL;
    *p_p_tail = get_before_tail(p_tete);
    //pour libérer la mémoire
    free((*p_p_tail)->p_suiv);
    (*p_p_tail)->p_suiv = NULL;
    return a;
}

/*
détruit une pile 
@input : Pile** prem pointeur sur un pointeur sur le première élément de la pile;
@output : void
@postcondition : le pile a été supprimé
@precondition : la pile existe
*/
void detruire_liste2(Pile** prem){
    Pile* n;
    while (*prem != NULL) {
        n = *prem;
        *prem = (*prem)->p_suiv;
        free(n);
    }
}

/*
inversse tout les élément d'un tableau
@input : Pile* pointeur sur la tête de la pile utilisé afin de trié le tableau;
int* tab, tableau à trier
@output : void
@postcondition : le tableau à été inverssé
@precondition : la pile et le tableau on été créer, le tableau contient au moins deux éléments
*/
void renversePile(Pile* p_tete, int* tab){   
    Pile* nouveau = NULL;
    int taille = sizeof(tab)+1;
    Pile* pt_tail = NULL;
    //empile tout les élement du tableau dans la pile
    for(int i=0; i < taille; i++){
        nouveau = init_not_random_elt(*tab+i);
        pt_tail = get_tail(p_tete);
        empile(&pt_tail,nouveau);
    }
    //insére dans le tableau et dépile tout les élement venant d'être ajouté dans la pile
    for(int i=0; i < taille; i++){
        tab[i] = depile(&pt_tail, p_tete);
    }
}    