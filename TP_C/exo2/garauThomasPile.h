#ifndef __garauThomasPile_h__
#define __garauThomasPile_h__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

typedef struct pile {
    int val;
    struct pile* p_suiv;
}Pile;

Pile* init_elt();
Pile* get_tail(Pile* p_tete);
Pile* get_before_tail(Pile* p_tete);
Pile* init_not_random_elt(int val);
void detruire_liste2(Pile** prem);
void get(Pile* p_p_tail);
void empile(Pile** p_p_tail, Pile* p_nv_elt);
int depile(Pile** p_p_tail, Pile* p_tete);
void renversePile(Pile* p_tete, int* tab);
#endif