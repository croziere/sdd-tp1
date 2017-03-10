/* -------------------------------------------------------------------- */
/* Module Action           Gestion des action (horaires) par semaines   */
/* action_t est un horaire (paction_t pointeur)                         */
/* actions_t est une liste d'action implémentée via une list_t          */
/* -------------------------------------------------------------------- */

#ifndef TP1_ACTION_H
#define TP1_ACTION_H

#include "list.h"

/* Taille max de la chaine du nom d'un jour */
#define JOUR_STRING_MAX 14

/* -------------------------------------------------------------------- */
/* Représente un horaire                                                */
/*                                                                      */
/* Attributs : jour Chaine du jour                                      */
/*             heure Chaine de l'heure                                  */
/*             nom Chaine du nom                                        */
/*                                                                      */
/* Types : action_t  Représente un horaire                              */
/*         paction_t Pointeur sur un horaire                            */
/* -------------------------------------------------------------------- */
typedef struct action
{
    char    jour;
    char    heure[3];
    char    nom[11];
} action_t, * paction_t;

/* Masque l'implémentation de la liste d'action par une list_t */
typedef list_t actions_t;

/* Création d'actions */
paction_t   action_creer(char, char *, char *);

/* Affichage/Sauvegarde */
void        action_afficher(void *, FILE *);
void        action_sauvegarder(paction_t, FILE *);
char      * action_jour_char(paction_t, char *);

/* Recherche */
actions_t   action_rechercher_prec(actions_t, char, char *, char *);

#endif //TP1_ACTION_H
