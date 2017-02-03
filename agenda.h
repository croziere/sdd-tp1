//
// Created by Benjamin Rozière on 03/02/2017.
//

#ifndef SDD_TP1_AGENDA_H
#define SDD_TP1_AGENDA_H

#include "action.h"

#define CHARGER_ERREUR_OUVERTURE -1
#define CHARGER_ERREUR_LECTURE -2
#define RETURN_SUCCESS 0

typedef struct agenda
{
    char annee[4];
    char semaine[2];
    action_t * actions;
    struct agenda * suiv;
}agenda_t, *pagenda_t;

// Gestionnaire liste agenda
pagenda_t initAgenda(void);

int estVideAgenda(pagenda_t);

int chargerAction(const char *, pagenda_t *);
void ajouterAction(pagenda_t *, const char *, const char *, const char, const char *, const char *);

void afficherSemaine(pagenda_t);
void afficherAgenda(pagenda_t);

#endif //SDD_TP1_AGENDA_H
