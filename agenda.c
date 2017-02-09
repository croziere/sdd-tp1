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

        //ajouterAction(list, annee, semaine, jour, heure, nom);
    }

    if(ferror(stream))
    {
        return CHARGER_ERREUR_LECTURE;
    }

    fclose(stream);

    return RETURN_SUCCESS;

}

void afficherSemaine(pagenda_t agenda, FILE * stream)
{
    fprintf(stream, "Annee %s / Semaine %s\n", agenda->annee, agenda->semaine);
}

void afficherAgenda(pagenda_t pagenda, FILE * stream)
{
    afficherSemaine(pagenda, stream);
    afficherList(pagenda->actions, &afficherAction, stream);
}

void libererAgenda(pagenda_t pagenda)
{
    liberer_list(pagenda->actions, &free);
    free(pagenda);
}