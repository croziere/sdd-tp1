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
    char annee[5];
    char semaine[3];
    list_t actions;
}semaine_t, *psemaine_t;

typedef struct GestionnaireSemaine{
    list_t (*Recherche)(list_t,char*,char*);
}GestionnaireSemaine;

psemaine_t semaine_t_new(char* annee, char* semaine, char jour, char* heure, char* nom);
GestionnaireSemaine GestionnaireSemaine_new();
list_t Rechercher (list_t pt, char* annee, char * semaine);

void afficherAgenda(psemaine_t , FILE *);
void saveAgenda(psemaine_t , FILE *);

void libererAgenda(psemaine_t);

#endif //SDD_TP1_AGENDA_H
