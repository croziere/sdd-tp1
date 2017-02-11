//
// Created by Benjamin Rozière on 03/02/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <memory.h>
#include "action.h"
#include "helper.h"

paction_t action_t_new(char jour, char * heure, char * nom)
{
    paction_t pt;
    malcx(pt,sizeof(action_t),"Erreur lors de l'allocation d'une action")
    pt->jour = jour;
    strcpy(pt->heure,heure);
    strcpy(pt->nom,nom);
    return pt;
}

void afficherAction(paction_t action, FILE * stream)
{
    fprintf(stream, "\t%s\n", action->nom);
    fprintf(stream, "\tLe %c a %sh00\n", action->jour, action->heure);
}

void saveAction(paction_t paction, FILE * stream)
{
    fprintf(stream, "%c%s%s", paction->jour, paction->heure, paction->nom);
}

