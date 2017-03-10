//
// Created by Benjamin Rozière on 03/02/2017.
//

#ifndef TP1_ACTION_H
#define TP1_ACTION_H

#include "list.h"

#define JOUR_STRING_MAX 14

typedef struct action
{
    char jour;
    char heure[3];
    char nom[11];
} action_t, * paction_t;


paction_t   action_creer(char, char *, char *);

void        action_afficher(void *, FILE *);
list_t      action_rechercher_prec(list_t, char, char *, char *);
void        action_sauvegarder(paction_t, FILE *);
char      * action_jour_char(paction_t, char *);

#endif //TP1_ACTION_H
