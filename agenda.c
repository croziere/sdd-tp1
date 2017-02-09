//
// Created by Benjamin Rozière on 03/02/2017.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "agenda.h"


int chargerAgenda(const char * path, list_t * list)
{
    FILE * stream;
    char buf[25];
    char annee[4];
    char semaine[2];
    char jour;
    char heure[2];
    char nom[10];


    if((stream = fopen(path, "r")) == NULL)
    {
        return CHARGER_ERREUR_OUVERTURE;
    }

    while (!feof(stream))
    {
        buf[strlen(buf) - 1] = '\0';

        strncpy(annee, buf, 4);
        strncpy(semaine, buf+4, 2);
        strncpy(&jour, buf+6, 1);
        strncpy(heure, buf+7, 2);
        strcpy(nom, buf+9);

        ajouterAction(list, annee, semaine, jour, heure, nom);
    }

    if(ferror(stream))
    {
        return CHARGER_ERREUR_LECTURE;
    }

    fclose(stream);

    return RETURN_SUCCESS;

}

void afficherActions(paction_t action)
{
    paction_t curr;

    if(estVide(action))
    {
        fprintf(stdout, "Aucune action pour cette semaine.\n");
    }
    else
    {
        curr = action;
        while (curr != NULL)
        {
            afficherAction(curr);
            curr = curr->suiv;
        }
    }
}

void afficherAction(paction_t action)
{
    fprintf(stdout, "\t%s\n", action->nom);
    fprintf(stdout, "\tLe %c a %sh00\n", action->jour, action->heure);
}

void afficherSemaine(pagenda_t agenda)
{
    fprintf(stdout, "Annee %s / Semaine %s\n", agenda->annee, agenda->semaine);
}

void afficherAgenda(pagenda_t agenda)
{
    pagenda_t semaineCurr;

    if(estVideAgenda(agenda))
    {
        fprintf(stdout, "Votre agenda est vide.\n");
    }
    else
    {
        semaineCurr = agenda;
        while (semaineCurr != NULL)
        {
            afficherSemaine(semaineCurr);
            afficherActions(semaineCurr->actions);
          //  semaineCurr = semaineCurr->suiv;
        }
    }
}

int estVideAgenda(pagenda_t agenda)
{
    return (agenda == NULL);
}

pagenda_t initAgenda()
{
    return NULL;
}