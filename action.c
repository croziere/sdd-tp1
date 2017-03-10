/* -------------------------------------------------------------------- */
/* Module Action           Gestion des action (horaires) par semaines   */
/* Implémentations                                                      */
/* -------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "action.h"
#include "helper.h"

/* -------------------------------------------------------------------- */
/* action_creer           Créé une nouvelle action                      */
/*                                                                      */
/* En entrée: jour Caractère du jour                                    */
/*            heure Chaine de l'heure                                   */
/*            nom Chaine du nom                                         */
/*                                                                      */
/* En sortie: Retourne un pointeur sur l'action créée                   */
/* -------------------------------------------------------------------- */
paction_t action_creer(char jour, char *heure, char *nom)
{
    paction_t   pt = NULL;
    malcx(pt, sizeof(action_t), "Erreur lors de l'allocation d'une action")

    pt->jour = jour;
    strcpy(pt->heure, heure);
    strcpy(pt->nom, nom);

    return pt;
}

/* -------------------------------------------------------------------- */
/* action_afficher           Ecrit une action sur stream                */
/*                                                                      */
/* En entrée: data L'action à afficher                                  */
/*            stream Flux su lequel écrire                              */
/* -------------------------------------------------------------------- */
void action_afficher(void * data, FILE *stream)
{
    paction_t   action = (paction_t)data;
    char        jour[JOUR_STRING_MAX];

    fprintf(stream, "\t%s\n", action->nom);
    fprintf(stream, "\tLe %s a %sh00\n", action_jour_char(action, jour), action->heure);
}

/* -------------------------------------------------------------------- */
/* action_sauvegarder           Ecrit une action pour sa sauvegarde     */
/*                                                                      */
/* En entrée: paction L'action à sauvegarder                            */
/*            stream Le flux où écrire                                  */
/* -------------------------------------------------------------------- */
void action_sauvegarder(paction_t paction, FILE *stream)
{
    fprintf(stream, "%c%s%s", paction->jour, paction->heure, paction->nom);
}

/* -------------------------------------------------------------------- */
/* action_rechercher_prec           Recherche l'action précedente       */
/*                                                                      */
/* En entrée: pt La liste d'actions                                     */
/*            jour Caractère du jour                                    */
/*            heure Chaine de l'heure                                   */
/*            nom Chaine du nom                                         */
/*                                                                      */
/* En sortie: Retourne un pointeur sur le maillon ou NULL si non trouvé */
/* -------------------------------------------------------------------- */
actions_t action_rechercher_prec(actions_t pt, char jour, char *heure, char *nom)
{
    actions_t   cur = pt;
    actions_t   retour = NULL;
    paction_t   pdata;
    int         test_heure;
    int         test_nom;
    int         trouve = 0;

    while (list_suivant(cur) != NULL && !trouve)
    {
        pdata = (paction_t)list_data(list_suivant(cur));

        test_heure = strncmp(pdata->heure, heure, 2);
        test_nom = strncmp(pdata->nom, nom, 10);

        if ((test_heure == 0) && (test_nom == 0) && (jour == pdata->jour))
        {
            trouve = 1;
            retour = cur;
        }
        cur = list_suivant(cur);
    }
    return retour;
}

/* -------------------------------------------------------------------- */
/* action_jour_char           Retourne le jour d'une action             */
/*                                                                      */
/* En entrée: paction Action                                            */
/*            jour_dest Chaine où écrire le jour                        */
/*                                                                      */
/* En sortie: L'adresse où est écrite le jour                           */
/* -------------------------------------------------------------------- */
char * action_jour_char(paction_t paction, char *jour_dest)
{
    switch (paction->jour)
    {
        case '1':
            strcpy(jour_dest, "Lundi");
            break;
        case '2':
            strcpy(jour_dest, "Mardi");
            break;
        case '3':
            strcpy(jour_dest, "Mercredi");
            break;
        case '4':
            strcpy(jour_dest, "Jeudi");
            break;
        case '5':
            strcpy(jour_dest, "Vendredi");
            break;
        case '6':
            strcpy(jour_dest, "Samedi");
            break;
        case '7':
            strcpy(jour_dest, "Dimanche");
            break;

        default:
            strcpy(jour_dest, "Jour invalide");
    }

    return jour_dest;
}
