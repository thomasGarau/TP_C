/*
Question 1: 
liste chainée Voyage contenant:
4int pour representé les heure et les minute des horaire départ et d'arrivé
1int representant la distance
2 tableau de char contenant les ville de depart et d'arrivé
1 pointeur sur un autre voyage contenant l'élément suivant de la liste chainé
*/
#include "garauThomasVoyage.h"

/*
initialise un voyage
@input char* ville_depart string qui represente la ville de départ du voyage; 
char* ville_arrive string qui represente la ville d'arrive du voyage;
int heure_depart l'heure de départ du voyage;
int heure_arrive l'heure d'arrive du voyage;
int minute_depart la minute de départ du voyage;
int minute_arrive la minute d'arrive du voyage;
int distance la distance en km du voyage;
@output : un pointeur sur le voyage nouvellement créer
@postcondition : le voyage est créer et retourné 
*/
Voyage* init_voyage(char* ville_depart, char* ville_arrive,int heure_depart, int heure_arrive, int minute_depart, int minute_arrive, int distance){
    Voyage* p_nv_elt = malloc(sizeof(Voyage));
    if (p_nv_elt != NULL){
        strcpy(p_nv_elt->ville_depart, ville_depart);
        strcpy(p_nv_elt->ville_arrive, ville_arrive);
        p_nv_elt->heure_depart = heure_depart;
        p_nv_elt->heure_arrive = heure_arrive;
        p_nv_elt->minute_depart = minute_depart;
        p_nv_elt->minute_arrive = minute_arrive;
        p_nv_elt->distance = distance;
        p_nv_elt->p_suiv = NULL;
    }
    return p_nv_elt;
}

/*
retourne le dernier élément de la liste
@input Voyage* head correspond à la tête de la liste 
@output : un pointeur sur Voyage correspondant au dernier élément de la liste
@postcondition : l'élément retourné correspond au dernier élément de la liste
@precondition : la liste é déja été instancié
*/
Voyage* get_tail(Voyage* head){
    //si la liste est vide
    if (head == NULL)
        printf("liste vide");
    else
        //verifie que le maillon itérer n'est pas le dernier
        while (head->p_suiv != NULL) {
            head = head->p_suiv;
        }
    return head;
}

/*
detruit une liste chainé de voyage est libére toute les zone mémoire utilisé par les élément de cette dernier.
@input : Voyage** head , pointeur sur un pointeur du premiére voyage de la liste chainé
@output : void
@postcondition : toute les zone mémoire utilisé par les différents maillons de la liste on été libérer
@precondition : la liste à déja été créer
*/
void detruire_liste2(Voyage** head){
    Voyage* n;
    while (*head != NULL) {
        n = *head;
        *head = (*head)->p_suiv;
        free(n);
    }
}

/*
ajoute un voyage à la fin d'une liste de voyages
@input : Voyage** p_p_tail , pointeur sur un pointeur du dernier voyage de la liste chainé;
Voyage* nouveau_voyage, pointeur sur le nouveaux voyage à ajouté en fin de liste.
@output : void
@postcondition : Le nouvelle ééement a été ajouté en bout de liste
@precondition : la liste et le nouvelle élément on déja été instancié.
*/
void ajout_voyage(Voyage** p_p_tail, Voyage* nouveau_voyage){
    (*p_p_tail)->p_suiv = nouveau_voyage;
    (*p_p_tail) = nouveau_voyage;
}

/*
affiche un voyage donné
@input : Voyage* p_voyage un pointeur sur le voyage à afficher
@output : void
@postcondition : le voyage en question est affiché en console
@precondition : le voyage existe 
*/
void display_voyage(Voyage* p_voyage){
    printf("tail : Ville départ = %s\nVille arrivé = %s\nHeure départ %d:%d\nHeure arrivé = %d:%d\nDistance parcouru = %d",
             p_voyage->ville_depart,p_voyage->ville_arrive,p_voyage->heure_depart,p_voyage->minute_depart,
             p_voyage->heure_arrive,p_voyage->minute_arrive,p_voyage->distance
        );
}

/*
affiche tout les voyage d'une liste de voyage
@input : Voyage* head, poiteur sur la tête de la liste
@output : void
@postcondition : tout les élément de la liste sont affiché dans le terminal
@precondition : la liste existe 
*/
void display_all_voyage(Voyage* head){
    while(head->p_suiv != NULL){
        display_voyage(head);
        head = head->p_suiv;
    }// car la boucle while s'arrête à l'avant dernier 
    display_voyage(head);
}

/*
affiche tout les voyage d'une liste de voyage pour un ville de départ donné
@input : Voyage* head, poiteur sur la tête de la liste;
char* ville, string représentant la ville de départ voulu
@output : void
@postcondition : tout les voyage de la liste dont la liste de départ est celle demandé sont affiché en console
@precondition : la liste existe et la ville saisi figurent dans la liste des voyage
*/
void display_all_train_from(Voyage* head, char* ville){
        //verifie que la tête de la liste n'est pas aussi le dernier élément.
    if (head == NULL)
        printf("liste vide");
    else
        //verifie que le maillon itérer n'est pas le dernier
        while (head != NULL) {
            if (strcmp(head->ville_depart,ville) == 0){
                display_voyage(head);
            }
            head = head->p_suiv;
        }
    putchar('\n');
}

/*
affiche le voyage le plus rapide en km/h, pour une liste de voyage donné
@input : Voyage* head, poiteur sur la tête de la liste;
@output : void
@postcondition : le voyage ayant la vitesse moyenne la plus élevé est affiché en console
@precondition : la liste des voyage à été créer en amont la distance est les heure de départ et d'arrivé ont correctement été insséré
*/
void display_fastest_voyage(Voyage* head){

    if(head == NULL){
        printf("liste vdie");
    }

    int MaxSpeed = 0;
    char* max_speed_ville_depart = "";
    char* max_speed_ville_arrive = "";
    float temps = 0;
    float depart = 0;
    float arrive = 0;

    while(head != NULL) {
        // calcule l'heure de départ et d'arrive avec les moinutes en pourcentage  d'heure
        // 8h30 = 8.5
        depart = head->heure_depart + (((float)head->minute_depart / 60.0));
        arrive = head->heure_arrive + (((float)head->minute_arrive / 60.0));
        //calcule le temps total
        temps = arrive - depart;

        //si la vitesse moyenne en km/h est plus grande que MaxSpeed (le voyage le plus rapide avant ca)
        //alors conserve la nouvelle vitesse la plus élevé anssi que la ville de départ et d'arrivé du voyage en question
        if((head->distance / temps) > MaxSpeed){
            MaxSpeed = head->distance /temps;
            max_speed_ville_depart = head->ville_depart;
            max_speed_ville_arrive = head->ville_arrive;
        }
        head = head->p_suiv;
    }
    //affiche le trajet le plus rapide
    printf("Trajet le plus rapide : Vitesse moyenne =%d ville de départ = %s  ville arrive = %s", 
            MaxSpeed, max_speed_ville_depart, max_speed_ville_arrive);
}


/*
trie une liste de voyage donnée par heure de départ
@input : Voyage** head, poiteur sur pointeur sur la tête de la liste;
@output : void
@postcondition : la liste est correctement trié
@precondition : la liste des voyage à été créer en amont
*/
void tri_voyage(Voyage** head){
    Voyage* elt = (*head);
    Voyage* next = (*head);
    Voyage* temporaire = NULL;
    Voyage* avant_elt = NULL;
    //calcule la taille de la liste chainé en nombre element qu'elle contient car sizeof retourne des octets 
    int size = 1;
    while(next->p_suiv != NULL){
        size += 1;
        next = next->p_suiv;
    }
    for(int i=0; i < size; i++){
        //revient  à faire elt = (*head + i) et next = (*head + i + 1) et avant_elt = (*head + i -1);
        //mais pour une liste dynamique
        elt = (*head);
        if(i != 0){
            for(int j=0; j < i; j++){
                if(j == i-1){
                    avant_elt = elt;
                }
                elt = elt->p_suiv;
            }
        }  
        // le dernier element ne peut pas être tester avec sont suivant car il est null
        // si on arrive au dernier element alors la liste est deja trié alors on return null pour arrêté la fonction
        if(elt->p_suiv != NULL){
            next = elt->p_suiv;
        }else{
            return;
        }
        // si l'element suivant a une heure de départ inférieur
        //ou si leurs heures sont égales mais que l'element suivant a une minute de départ inferieur alors
        //on intervertie les deux element
        if (next->heure_depart < elt->heure_depart || (next->heure_depart == elt->heure_depart && next->minute_depart < elt->minute_depart)){
            if(i != 0){
                avant_elt->p_suiv = next;
                elt->p_suiv = next->p_suiv;
                next->p_suiv = elt;
                
            }else{
                temporaire = (*head)->p_suiv;
                elt->p_suiv = next->p_suiv;
                temporaire->p_suiv = (*head);
                (*head) = temporaire;
            }
            // si on a interverti des élément alors on reprend la boucle depuis le départ 
            // -1 car au debut de la boucle i++ donc la boucle recommenceras à 0
            i = -1;
        }
    }
}


/*
affiche le voyage le plus rapide avec une correspondance si nécessaire, pour une ville de départ et une ville d'arrivé donné
@input : Voyage* head, pointeur sur la tête de la liste;
@output : void
@postcondition : le voyage et potentiellement ca correspondance hypothetique sont affiché en console
@precondition : la liste des voyage à été créer en amont,  il existe un voyage ou un voyage avec correspondance permettant de relié les deux villes
*/
void display_fastest_voyage_corespondance(Voyage* head, char* depart, char* destination){
    //dans la même idée que fastest = math.inf
    int fastest = 1000000;
    //permettra d'éffectuer une deuxieme boucle sur la liste afin de déterminé si une correspondance est possible et souhaitable
    Voyage* head2 = head;
    int Tempsdepart = 0;
    int arrive = 0;
    int temps = 0;
    Voyage* voyage_depart = NULL;
    Voyage* correspondance = NULL;
    while(head->p_suiv != NULL){
        //si la ville de départ correspond à celle voulu
        if(strcmp(head->ville_depart, depart) == 0){
            //si la ville de destination correspond a celle souhaiter
            if(strcmp(head->ville_arrive, destination) ==0){
                    //détermine l'heure de départ et d'arrive avec les minute en pourcentage d'heure
                    //8h30 = 8.5 heure
                    Tempsdepart = head->heure_depart + (((float)head->minute_depart / 60.0));
                    arrive = head->heure_arrive + (((float)head->minute_arrive / 60.0));
                    temps = arrive - Tempsdepart;
                    //si le voyage est plus rapide que le précedent trouvé
                    if (temps < fastest){
                        fastest = temps;
                        voyage_depart = head;
                        correspondance = NULL;
                    }
            //si non essaye de trouver une correspondance
            }else{
                display_voyage(head);
                while(head2->p_suiv !=NULL){
                    //si la ville de départ du premier voyage correspond à la ville souhaité et que la ville d'arrivé du second voyage (la correspodance) correspond à la ville de destination voulu
                    if(strcmp(head->ville_arrive, head2->ville_depart) == 0 && strcmp(head2->ville_arrive, destination) == 0){
                        //si l'heure de départ de la correspondance et au moin 5m après l'heure d'arrive du premier train 
                        //et que l'heure de départ de la correspondance n'exéde pas 2h après l'heure d'arrivé du premier train
                        //pas eu le temps pour la condition du battement entre 5m et 2h entre les correspondance
                        //if(head->heure_arrive <= head2->heure_depart && head->minute_arrive + 5 < head2->minute_depart && (head->heure_arrive * 3600 + head->minute_arrive * 60) > (head2->heure_depart * 3600 + head2->minute_depart * 60)){
                            Tempsdepart = head->heure_depart + (((float)head->minute_depart / 60.0));
                            arrive = head2->heure_arrive + (((float)head->minute_arrive / 60.0));
                            temps = arrive - Tempsdepart;
                            if (temps < fastest){
                                fastest = temps;
                                voyage_depart = head;
                                correspondance = head2;
                            }
                        //}
                    }
                    head2 = head2->p_suiv;
                }
            }
        }
        head = head->p_suiv;
    }
    //affiche le voyage le plus rapide
    printf("pour aller de %s à %s le voyage le plus rapide est\n ", depart, destination);
    display_voyage(voyage_depart);
    //affiche ca correspondance si il y'en a une
    if( correspondance != NULL){
        printf("\n puis de prendre la correspondance \n");
        display_voyage(correspondance);
    }
}
