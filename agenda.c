//
// Created by Benjamin Rozière on 03/02/2017.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "agenda.h"
#include "helper.h"

list_t Rechercher (list_t pt, char* annee, char * semaine){
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

GestionnaireSemaine GestionnaireSemaine_new(){
    GestionnaireSemaine* pt = null;
    malcx(pt,sizeof(GestionnaireSemaine),"Erreur lors de l'allocation du gestionnaire de semaine")
    pt->Recherche = &Rechercher;
    return *pt;
}

psemaine_t semaine_t_new(char* annee, char* semaine, char jour, char* heure, char* nom){
    psemaine_t pt = null;
    paction_t data = new(action_t, jour,heure,nom);
    malcx(pt, sizeof(semaine_t),"Erreur lors de l'allocation d'une semaine")
    pt->actions = new(list_t);
    ajouterMaillon(pt->actions,data);
    strcpy(pt->annee,annee);
    strcpy(pt->semaine,semaine);
    return pt;
}

void afficherSemaine(psemaine_t agenda, FILE * stream)
{
    fprintf(stream, "Annee %s / Semaine %s\n", agenda->annee, agenda->semaine);
}

void afficherAgenda(void * data, FILE * stream)
{
    psemaine_t pagenda = (psemaine_t)data;
    afficherSemaine(pagenda, stream);
    afficherList(pagenda->actions, &afficherAction, stream);
}

void saveAgenda(void * data, FILE * stream)
{
    psemaine_t psemaine = (psemaine_t)data;

    foreach(psemaine->actions, action)
    {
        fprintf(stream, "%s%s", psemaine->annee, psemaine->semaine);
        saveAction(action->data, stream);
        fprintf(stream, "\n");
    }
}

void libererAgenda(void * data)
{
    psemaine_t pagenda = (psemaine_t)data;

    liberer_list(pagenda->actions, &free);
    free(pagenda);
}