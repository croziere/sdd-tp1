//
// Created by Benjamin Rozière on 09/02/2017.
//

#ifndef TP1_LIST_H
#define TP1_LIST_H

#include <stdio.h>

typedef struct maillon
{
    void           * data;
    struct maillon * next;
} maillon_t, * list_t;

list_t  list_init();
void    list_liberer(list_t, void (*)(void *));

int     list_est_vide(list_t);

void    list_ajouter_maillon(maillon_t **, void *);
void    list_supprimer_maillon(maillon_t *, void (*)(void *));

void    list_afficher(list_t, void (*)(void *, FILE *), FILE *);

#endif //TP1_LIST_H