//
// Created by Benjamin Rozière on 03/02/2017.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "agenda.h"
#include "parser.h"
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

list_t RechercherPrec (list_t pt, char* annee, char * semaine){
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

GestionnaireSemaine GestionnaireSemaine_new(){
    GestionnaireSemaine* pt;
    malcx(pt,sizeof(GestionnaireSemaine),"Erreur lors de l'allocation du gestionnaire de semaine")
    pt->Recherche = &Rechercher;
    pt->RecherchePrec = &RechercherPrec;
    return *pt;
}

psemaine_t semaine_t_new(char* annee, char* semaine, char jour, char* heure, char* nom){
    psemaine_t pt;
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

void afficherAgenda(psemaine_t pagenda, FILE * stream)
{
    afficherSemaine(pagenda, stream);
    afficherList(pagenda->actions, &afficherAction, stream);
}

void saveAgenda(psemaine_t psemaine, FILE * stream)
{
    foreach(psemaine->actions, action)
    {
        fprintf(stream, "%s%s", psemaine->annee, psemaine->semaine);
        saveAction(action->data, stream);
        fprintf(stream, "\n");
    }
}

void libererAgenda(psemaine_t pagenda)
{
    liberer_list(pagenda->actions, &free);
    free(pagenda);
}