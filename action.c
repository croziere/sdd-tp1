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
    paction_t pt = NULL;
    malcx(pt,sizeof(action_t),"Erreur lors de l'allocation d'une action")
    pt->jour = jour;
    strcpy(pt->heure,heure);
    strcpy(pt->nom,nom);
    return pt;
}

void action_afficher(void * data, FILE *stream)
{
    paction_t action = (paction_t)data;

    char jour[JOUR_STRING_MAX];

    fprintf(stream, "\t%s\n", action->nom);
    fprintf(stream, "\tLe %s a %sh00\n", action_jour_char(action, jour), action->heure);
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
    while (list_suivant(cur) != NULL){
        pdata = (paction_t) list_data(list_suivant(cur));
        test_heure = strncmp(pdata->heure, heure,2);
        test_nom = strncmp(pdata->nom, nom,10);
        printf("%c\t%s\t%s\n",pdata->jour,pdata->heure,pdata->nom);
        if ((test_heure == 0) && ( test_nom == 0) && (jour == pdata->jour)){
            return cur;
        }
        cur = list_suivant(cur);
    }
    return NULL;
}

char* action_jour_char(paction_t paction, char *jour_dest)
{
    switch (paction->jour)
    {
        case '1':
            strcpy(jour_dest, "Lundi");
            break;
        case '2':
            strcpy(jour_dest, "Mardi");
            break;
        case '3':
            strcpy(jour_dest, "Mercredi");
            break;
        case '4':
            strcpy(jour_dest, "Jeudi");
            break;
        case '5':
            strcpy(jour_dest, "Vendredi");
            break;
        case '6':
            strcpy(jour_dest, "Samedi");
            break;
        case '7':
            strcpy(jour_dest, "Dimanche");
            break;

        default:
            strcpy(jour_dest, "Jour invalide");
    }

    return jour_dest;
}
