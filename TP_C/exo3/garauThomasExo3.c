#include "garauThomasVoyage.h"

/*
    question 1)
    j'ai choisi de représenter la liste des horaires de train par une structure simple contenant chaque élement
    nécessaire à caractèriser un voyage que sont: ville départ, ville arrivé, heure départ et minute départ , heure arrivé et minute arrivé
    ainsi qu'un attribut p_suiv contenant un pointeur sur l'élement suivant de la liste chainé.
    J'ai donc choisi d'opter pour une liste chainé carc cela me permettais de réutilisé le code des exercice précédent.
    De plus la liste ayant besoins d'être trié le choix de la liste chainé ce justifie d'autant plus que les inssetion sont moins longue
    en utilisant une liste chainé.
*/
int main(int argc, char const *argv[])
{
    
    Voyage* head = NULL;
    Voyage* nouveau = NULL;
    Voyage* tail = NULL;

    head = init_voyage("Lyon", "Marseille", 11, 17, 50, 00, 450);
    tail = get_tail(head);

    nouveau = init_voyage("Lyon", "Marseille", 10, 15, 7, 1, 450);
    ajout_voyage(&tail, nouveau);
    tail = get_tail(head);

    nouveau = init_voyage("Lille", "Calais", 15, 18, 19, 34, 110);
    ajout_voyage(&tail, nouveau);
    tail = get_tail(head);

    nouveau = init_voyage("Lille", "Paris", 8, 8, 0, 59, 237);
    ajout_voyage(&tail, nouveau);
    tail = get_tail(head);

    nouveau = init_voyage("Lille", "Lyon", 7, 10, 0, 0, 709);
    ajout_voyage(&tail, nouveau);
    tail = get_tail(head);

    nouveau = init_voyage("Paris", "Marseille", 12, 18, 0, 0, 900);
    ajout_voyage(&tail, nouveau);
    tail = get_tail(head);
    tri_voyage(&head);

    //désolé pas eu le temps pour des test unitaire mais chaque print correspond à un test dont le résultat est cohérent avec ce attendu
    //décommenter les au fur est à mesure pour plus de lisibilité si vous souhaiter tester.

    //question 3
    //display_all_train_from(head, "Lyon");

    //question 4
    //display_fastest_voyage(head);

    //question 5
   // display_all_voyage(head);
    // on vois que cela est triè alors que l'inssertion faite plus haut n'est pas dans l'ordre cela est le résultat de tri_voyage ligne 32

    //question 6
    display_fastest_voyage_corespondance(head, "Lille", "Marseille");

}