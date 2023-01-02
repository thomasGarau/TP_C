#ifndef __garauThomasVoyage_h__
#define __garauThomasVoyage_h__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>

typedef struct Voyage {
    char ville_depart[100];
    char ville_arrive[100];
    int heure_depart;
    int heure_arrive;
    int minute_depart;
    int minute_arrive;
    int distance;
    struct Voyage* p_suiv;
}Voyage;

Voyage* init_voyage(char* ville_depart, char* ville_arrive,int heure_depart, int heure_arrive, int minute_depart, int minute_arrive, int distance);
Voyage* get_tail(Voyage* head);
void detruire_liste2(Voyage** head);
void ajout_voyage(Voyage** tail, Voyage* nouveau_voyage);
void display_voyage(Voyage* p_tail);
void display_all_voyage(Voyage* head);
void display_all_train_from(Voyage* head, char* ville);
void display_fastest_voyage(Voyage* head);
void tri_voyage(Voyage** head);
void display_fastest_voyage_corespondance(Voyage* head, char* depart, char* destination);
#endif