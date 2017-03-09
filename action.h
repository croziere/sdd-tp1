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


typedef struct GestionnaireAction
{

    list_t  (* RecherhePrec)    (list_t, char, char *, char *);

} GestionnaireAction;

paction_t           action_t_new(char, char *, char *);

GestionnaireAction  GestionnaireAction_new();
void                afficherActions(paction_t);
void                afficherAction(paction_t, FILE *);
list_t              RecherhePrec (list_t, char, char *, char *);
void                saveAction(paction_t, FILE *);

#endif //TP1_ACTION_H
