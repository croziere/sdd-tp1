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
}maillon_t, *list_t;

typedef struct GestionnaireList{
    void (*AjouterMaillon)(maillon_t*,void*);
    void (*LibererList)(list_t, void (*)(void *));
    int (*EstVide)(list_t);
    void (*SupprimerMaillon)(maillon_t * prev, void (*)(void *));
    void (*AfficherList)(list_t, void (*)(void *, FILE *), FILE*);
}GestionnaireList;

GestionnaireList GestionnaireList_new();
list_t init_list();
void liberer_list(list_t, void (*)(void *));
int estVide(list_t);
void ajouterMaillon(maillon_t *, void *);
void supprimerMaillon(maillon_t * prev, void (*)(void *));
void afficherList(list_t, void (*)(void *, FILE *), FILE*);
list_t list_t_new();

#endif //TP1_LIST_H