//
// Created by Benjamin Rozière on 03/02/2017.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "agenda.h"
#include "helper.h"

list_t agenda_rechercher(list_t pt, char *annee, char *semaine){
    psemaine_t pdata;
    int test_annee;
    int test_semaine;
    foreach(pt,cur){
        pdata = (psemaine_t)(cur->data);
        test_annee = strncmp(pdata->annee, annee,4);
        test_semaine = strncmp(pdata->semaine, semaine,2);
       if ((test_annee == 0) && ( test_semaine == 0)){
            return cur;
        }
    }
    return null;
}

list_t agenda_rechercher_prec(list_t pt, char *annee, char *semaine){
    list_t cur = pt;
    psemaine_t pdata;
    int test_annee;
    int test_semaine;
    while (cur->next != null){
        pdata = (psemaine_t) (cur->next->data);
        test_annee = strncmp(pdata->annee, annee,4);
        test_semaine = strncmp(pdata->semaine, semaine,2);
        if ((test_annee == 0) && ( test_semaine == 0)){
            return cur;
        }
        cur = cur->next;
    }
    return null;
}


psemaine_t agenda_semaine_creer(char *annee, char *semaine, char jour, char *heure, char *nom){
    psemaine_t pt = null;
    paction_t data = action_creer(jour, heure, nom);
    malcx(pt, sizeof(semaine_t),"Erreur lors de l'allocation d'une semaine")
    pt->actions = list_init();
    list_ajouter_maillon(&pt->actions, data);
    strcpy(pt->annee,annee);
    strcpy(pt->semaine,semaine);
    return pt;
}

void afficherSemaine(psemaine_t agenda, FILE * stream)
{
    fprintf(stream, "Annee %s / Semaine %s\n", agenda->annee, agenda->semaine);
}

void agenda_afficher(void *data, FILE *stream)
{
    psemaine_t pagenda = (psemaine_t)data;
    afficherSemaine(pagenda, stream);
    list_afficher(pagenda->actions, &action_afficher, stream);
}

void agenda_sauvegarder(void *data, FILE *stream)
{
    psemaine_t psemaine = (psemaine_t)data;

    foreach(psemaine->actions, action)
    {
        fprintf(stream, "%s%s", psemaine->annee, psemaine->semaine);
        action_sauvegarder(action->data, stream);
        fprintf(stream, "\n");
    }
}

void agenda_liberer(void *data)
{
    psemaine_t pagenda = (psemaine_t)data;

    list_liberer(pagenda->actions, &free);
    free(pagenda);
}