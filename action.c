//
// Created by Benjamin Rozière on 03/02/2017.
//
#include <stdio.h>
#include "action.h"

void afficherAction(paction_t action, FILE * stream)
{
    fprintf(stream, "\t%s\n", action->nom);
    fprintf(stream, "\tLe %c a %sh00\n", action->jour, action->heure);
}

void saveAction(paction_t paction, FILE * stream)
{
    fprintf(stream, "%c%s%s", paction->jour, paction->heure, paction->nom);
}

