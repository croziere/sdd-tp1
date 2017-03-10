/* -------------------------------------------------------------------- */
/* Module Agenda           Gestion d'un agenda                          */
/* Une agenda est une liste chainée de semaine_t, chaque semaine_t      */
/* contient une liste d'actions (actions_t) qui sont les horaires       */
/* -------------------------------------------------------------------- */
#ifndef SDD_TP1_AGENDA_H
#define SDD_TP1_AGENDA_H

#include <stdlib.h>
#include <stdio.h>
#include "action.h"
#include "list.h"

/* -------------------------------------------------------------------- */
/* Représente une semaine                                               */
/*                                                                      */
/* Attributs : annee Chaine de l'année                                  */
/*             semaine Chaine de la semaine                             */
/*             actions Liste d'actions                                  */
/*                                                                      */
/* Types : semaine_t  Représente une semaine                            */
/*         psemaine_t Pointeur sur une semaine                          */
/* -------------------------------------------------------------------- */
typedef struct
{
    char        annee[5];
    char        semaine[3];
    actions_t   actions;
} semaine_t, * psemaine_t;

/* Encapsulation de la liste, permet de masquer l'implémentation de l'agenda par une list_t */
typedef list_t agenda_t;

/* Création/Destruction de l'agenda et des semaines */
agenda_t    agenda_creer();
void        agenda_liberer(agenda_t);
psemaine_t  agenda_semaine_creer(char *, char *, char, char *, char *);
void        agenda_semaine_liberer(void *);

/* Gestion des actions */
void        agenda_action_ajouter(agenda_t *, char *, char *, char, char *, char *);
void        agenda_lecture_format(char *, char *, char *, char *, char *, char *);

/* Recherche */
agenda_t    agenda_rechercher(agenda_t , char *, char *);
agenda_t    agenda_rechercher_prec(agenda_t , char *, char *);

/* Affichage/Sauvegarde */
void        agenda_afficher_stdout(agenda_t);
void        agenda_afficher(void *, FILE *);
void        agenda_semaine_afficher(psemaine_t, FILE *);
void        agenda_sauvegarder(void *, FILE *);

#endif //SDD_TP1_AGENDA_H
