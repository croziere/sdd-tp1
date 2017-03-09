//
// Created by Benjamin Rozière on 03/02/2017.
//

#ifndef TP1_ACTION_H
#define TP1_ACTION_H

#include "list.h"

typedef struct action
{
    char jour;
    char heure[3];
    char nom[11];
} action_t, * paction_t;


paction_t           action_creer(char, char *, char *);

void                action_afficher_list(paction_t);
void                action_afficher(void *, FILE *);
list_t              action_rechercher_prec(list_t, char, char *, char *);
void                action_sauvegarder(paction_t, FILE *);

#endif //TP1_ACTION_H
