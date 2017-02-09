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
    char annee[4];
    char semaine[2];
    list_t actions;
}semaine_t, *psemaine_t;

typedef struct GestionnaireSemaine{
    psemaine_t (*Recherche)(char*,char*);
    void (*AjouterAction)(char*,char*,char*);
}GestionnaireSemaine;
// Gestionnaire liste agenda
psemaine_t initAgenda(void);

int estVideAgenda(psemaine_t);

int chargerAgenda(const char *, list_t *);
void ajouterAction(psemaine_t *, const char *, const char *, const char, const char *, const char *);

void afficherSemaine(psemaine_t , FILE *);
void afficherAgenda(psemaine_t , FILE *);

void libererAgenda(psemaine_t);

#endif //SDD_TP1_AGENDA_H
