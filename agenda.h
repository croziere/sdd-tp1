//
// Created by Benjamin Rozière on 03/02/2017.
//

#ifndef SDD_TP1_AGENDA_H
#define SDD_TP1_AGENDA_H

#include "action.h"
#include "list.h"

#define CHARGER_ERREUR_OUVERTURE -1
#define CHARGER_ERREUR_LECTURE -2
#define RETURN_SUCCESS 0

typedef struct
{
    char    annee[5];
    char    semaine[3];
    list_t  actions;
} semaine_t, * psemaine_t;

/* Encapsulation de la liste */
typedef list_t agenda_t;

agenda_t    agenda_creer();
void        agenda_liberer(agenda_t);

void        agenda_action_ajouter(list_t *, char *, char *, char, char *, char *);
void        agenda_lecture_format(char *, char *, char *, char *, char *, char *);



psemaine_t  agenda_semaine_creer(char *, char *, char, char *, char *);
void        agenda_semaine_liberer(void *);

list_t      agenda_rechercher(list_t, char *, char *);
list_t      agenda_rechercher_prec(list_t, char *, char *);

void        agenda_afficher(void *, FILE *);
void        agenda_semaine_afficher(psemaine_t, FILE *);
void        agenda_sauvegarder(void *, FILE *);

#endif //SDD_TP1_AGENDA_H
