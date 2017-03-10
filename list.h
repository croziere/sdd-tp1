/* -------------------------------------------------------------------- */
/* Module List           Gestion d'une liste chainée générique          */
/* Déclaration de maillon_t et list_t                                   */
/* -------------------------------------------------------------------- */

#ifndef TP1_LIST_H
#define TP1_LIST_H

#include <stdio.h>

/* -------------------------------------------------------------------- */
/* Représente une liste chainée                                         */
/*                                                                      */
/* Attributs : data Pointeur non typé vers les données du maillon       */
/*             next Pointeur vers le maillon suivant                    */
/*                                                                      */
/* Types : maillon_t Représente un maillon                              */
/*         list_t Pointeur sur maillon, utilisé pour simplifier         */
/*                l'écriture de la tête de liste                        */
/* -------------------------------------------------------------------- */
typedef struct maillon
{
    void           * data;
    struct maillon * next;
} maillon_t, * list_t;

/* Fonction de création/destruction */
list_t      list_init();
void        list_liberer(list_t, void (*)(void *));

/* Tests */
int         list_est_vide(list_t);

/* Gestion des maillons */
void        list_ajouter_maillon(maillon_t **, void *);
void        list_supprimer_maillon(maillon_t *, void (*)(void *));
void  *     list_data(maillon_t *);
maillon_t * list_suivant(maillon_t *);

/* Affichage */
void        list_afficher(list_t, void (*)(void *, FILE *), FILE *);

#endif //TP1_LIST_H