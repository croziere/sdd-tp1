//
// Created by Benjamin Rozière on 03/02/2017.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "agenda.h"
#include "helper.h"

agenda_t agenda_creer()
{
    return list_init();
}

void agenda_liberer(agenda_t agenda)
{
    list_liberer(agenda, &agenda_semaine_liberer);
}

void agenda_action_ajouter(list_t *pt, char *annee, char *semaine, char jour, char *heure, char *nom)
{
    list_t pt_semaine = agenda_rechercher(*pt, annee, semaine);
    if (pt_semaine == NULL)
    {
        psemaine_t data = agenda_semaine_creer(annee, semaine, jour, heure, nom);
        list_ajouter_maillon(pt, data);
    }
    else
    {
        paction_t data = action_creer(jour, heure, nom);
        list_ajouter_maillon(&((psemaine_t) list_data(pt_semaine))->actions, data);
    }
}

void agenda_lecture_format(char *buffer, char *annee, char *semaine, char *jour, char *heure, char *nom)
{
    strncpy(annee, buffer, 4);
    strncpy(semaine, buffer + 4, 2);
    strncpy(jour, buffer + 6, 1);
    strncpy(heure, buffer + 7, 2);
    strcpy(nom, buffer + 9);

    annee[4] = '\0';
    semaine[2] = '\0';
    heure[2] = '\0';
}

/* -------------------------------------------------------------------- */
/* agenda_rechercher           Recherche une semaine dans l'agenda      */
/*                                                                      */
/* En entrée: pt La liste des semaines (Agenda)                         */
/*            annee Une chaine contenant l'année recherchée             */
/*            semaine Une chaine contenant la semaine recherchée        */
/*                                                                      */
/* En sortie: Retourne l'adresse de la semaine ou NULL si non trouvé    */
/* -------------------------------------------------------------------- */
list_t agenda_rechercher(list_t pt, char *annee, char *semaine)
{

    psemaine_t  pdata;
    int         test_annee;
    int         test_semaine;

    foreach(pt, cur)
    {
        pdata = (psemaine_t)list_data(cur);

        test_annee = strncmp(pdata->annee, annee, 4);
        test_semaine = strncmp(pdata->semaine, semaine, 2);

        if ((test_annee == 0) && (test_semaine == 0))
        {
            return cur;
        }

        next(cur);
    }

    return NULL;
}

/* -------------------------------------------------------------------- */
/* agenda_rechercher_prec           Recherche de la semaine précedente  */
/* dans la liste                                                        */
/*                                                                      */
/* En entrée: pt La liste des semaines (Agenda)                         */
/*            annee Une chaine contenant l'année recherchée             */
/*            semaine Une chaine contenant la semaine recherchée        */
/*                                                                      */
/* En sortie: Retourne l'adresse de la semaine précedente               */
/* ou NULL si non trouvé                                                */
/* -------------------------------------------------------------------- */
list_t agenda_rechercher_prec(list_t pt, char *annee, char *semaine)
{
    list_t      cur = pt;
    list_t      retour = NULL;
    psemaine_t  pdata;
    int         test_annee;
    int         test_semaine;
    int         trouve = 0;

    while (list_suivant(cur) != NULL && !trouve)
    {
        pdata = (psemaine_t) list_data(list_suivant(cur));

        test_annee = strncmp(pdata->annee, annee, 4);
        test_semaine = strncmp(pdata->semaine, semaine, 2);

        if ((test_annee == 0) && ( test_semaine == 0))
        {
            retour = cur;
            trouve = 1;
        }

        cur = list_suivant(cur);
    }

    return retour;
}

/* -------------------------------------------------------------------- */
/* agenda_semaine_creer           Créé une nouvelle semaine             */
/*                                                                      */
/* En entrée: annee Une chaine contenant l'année                        */
/*                  semaine Une chaine contenant la semaine             */
/*                  jour Un caractere contenant le jour                 */
/*                  heure Une chaine contenance l'heure                 */
/*                  nom Une chaine contenant le nom de l'action         */
/*                                                                      */
/* En sortie: Retourne l'adresse de la semaine ou NULL si non trouvé    */
/* -------------------------------------------------------------------- */
psemaine_t agenda_semaine_creer(char *annee, char *semaine, char jour, char *heure, char *nom)
{
    psemaine_t  pt = NULL;
    paction_t   data = action_creer(jour, heure, nom);

    malcx(pt, sizeof(semaine_t),"Erreur lors de l'allocation d'une semaine")

    pt->actions = list_init();
    list_ajouter_maillon(&pt->actions, data);

    strcpy(pt->annee,annee);
    strcpy(pt->semaine,semaine);

    return pt;
}

void agenda_semaine_afficher(psemaine_t agenda, FILE *stream)
{
    fprintf(stream, "Annee %s / Semaine %s\n", agenda->annee, agenda->semaine);
}

void agenda_afficher(void *data, FILE *stream)
{
    psemaine_t  pagenda = (psemaine_t)data;
    
    agenda_semaine_afficher(pagenda, stream);
    list_afficher(pagenda->actions, &action_afficher, stream);
}

void agenda_sauvegarder(void *data, FILE *stream)
{
    psemaine_t  psemaine = (psemaine_t)data;

    foreach(psemaine->actions, action)
    {
        fprintf(stream, "%s%s", psemaine->annee, psemaine->semaine);
        action_sauvegarder(list_data(action), stream);
        fprintf(stream, "\n");

        next(action);
    }
}

void agenda_semaine_liberer(void *data)
{
    psemaine_t  pagenda = (psemaine_t)data;

    list_liberer(pagenda->actions, &free);
    free(pagenda);
}