//
// Created by Benjamin Rozière on 03/02/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "action.h"
#include "helper.h"
#include "parser.h"
#include "agenda.h"

paction_t action_creer(char jour, char *heure, char *nom)
{
    paction_t pt = null;
    malcx(pt,sizeof(action_t),"Erreur lors de l'allocation d'une action")
    pt->jour = jour;
    strcpy(pt->heure,heure);
    strcpy(pt->nom,nom);
    return pt;
}

void action_afficher(void * data, FILE *stream)
{
    paction_t action = (paction_t)data;

    fprintf(stream, "\t%s\n", action->nom);
    fprintf(stream, "\tLe %c a %sh00\n", action->jour, action->heure);
}

void action_sauvegarder(paction_t paction, FILE *stream)
{
    fprintf(stream, "%c%s%s", paction->jour, paction->heure, paction->nom);
}

list_t action_rechercher_prec(list_t pt, char jour, char *heure, char *nom){
    list_t cur = pt;
    paction_t pdata;
    int test_heure;
    int test_nom;
    while (cur->next != null){
        pdata = (paction_t) (cur->next->data);
        test_heure = strncmp(pdata->heure, heure,2);
        test_nom = strncmp(pdata->nom, nom,10);
        printf("%c\t%s\t%s\n",pdata->jour,pdata->heure,pdata->nom);
        if ((test_heure == 0) && ( test_nom == 0) && (jour == pdata->jour)){
            return cur;
        }
        cur = cur->next;
    }
    return null;
}
