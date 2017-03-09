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

list_t  init_list();
void    liberer_list(list_t, void (*)(void *));

int     est_vide(list_t);

void    ajouter_maillon(maillon_t **, void *);
void    supprimer_maillon(maillon_t *, void (*)(void *));

void    afficher_list(list_t, void (*)(void *, FILE *), FILE *);

#endif //TP1_LIST_H