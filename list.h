//
// Created by Benjamin Rozière on 09/02/2017.
//

#ifndef TP1_LIST_H
#define TP1_LIST_H

typedef struct maillon
{
    void           * data;
    struct maillon * next;
}maillon_t, *list_t;

list_t init_list();
void liberer_list(list_t, void (*)(void *));

int estVide(list_t);

void ajouterMaillon(maillon_t *, void *);
void supprimerMaillon(maillon_t * prev, void (*)(void *));

void afficherList(list_t, void (*)(void *, FILE *), FILE*);

#endif //TP1_LIST_H