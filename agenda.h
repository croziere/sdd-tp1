//
// Created by Benjamin Rozière on 03/02/2017.
//

#ifndef SDD_TP1_AGENDA_H
#define SDD_TP1_AGENDA_H

typedef struct action
{
    int jour;
    int heure;
    char nom[10];
    struct action * suiv;

}action_t, *paction_t;

typedef struct agenda
{
    char annee[4];
    char semaine[2];
    action_t * actions;
    struct agenda * suiv;
}agenda_t, pagenda_t;

#endif //SDD_TP1_AGENDA_H
