#include "garauThomasPile.h"

/*question 1 : 
    j'ai choisi d'opter pour une liste chainé car c'est le moyen le plus efficace en temps vitesse d'execution du programme 
    lorsqu'il y'a bcp d'inssertion ce qui est le cas dans le cas d'une pile.
    De plus cela reprend ce qui à été fait dans le première exercice et dans le code rien ne ce gache.
    Nota Bene : les élement ne sont pas ajouté en tête de liste mais en bout de liste
*/

int main(int argc, char const *argv[])
{
    Pile* premier = NULL;
    Pile* nouveau = NULL;
    Pile* tail = NULL;
    premier = init_elt();

    for(int i =0; i < 5; i++){
        tail = get_tail(premier);
        nouveau = init_elt();
        empile(&tail, nouveau);
        get(tail);
    }
    
    get(tail);
    depile(&tail, premier);
    get(tail);
    nouveau = init_not_random_elt(50);
    empile(&tail, nouveau);
    get(tail);
    
    int a[5] = {1,2,3,4,5};
    int *pt_tab = a;
    printf("%s","liste");
    for(int i=0; i<5; i++){
        printf(" %d", pt_tab[i]);
    }
    printf("%s", "liste inverssé"); 
    renversePile(premier, pt_tab);
    for(int i=0; i<5; i++){
        printf(" %d", pt_tab[i]);
    }
    detruire_liste2(&premier);
    free(tail);
    printf("\n%d", premier->val);

    return 0;
}
