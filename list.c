//
// Created by Benjamin Rozière on 09/02/2017.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "list.h"
#include "helper.h"

list_t init_list()
{
    return NULL;
}

/// Free a generic list
/// \param list
/// \param free_data
void liberer_list(list_t list, void (*free_data)(void *))
{
    maillon_t * cur;
    maillon_t * temp;

    cur = list;

    while (cur != NULL)
    {
        temp = cur;
        free_data(temp->data);
        cur = cur->next;
        free(temp);
    }
}

int estVide(list_t list)
{
    return (list == NULL);
}

void ajouterMaillon(maillon_t * prev, void * data)
{
    maillon_t * wrap;

    malcx(wrap, sizeof(maillon_t), "Impossible d'allouer le maillon")

    wrap->data = data;
    wrap->next = prev->next;

    prev->next = wrap;
}

void supprimerMaillon(maillon_t * prev, void (*free_data)(void *))
{
    maillon_t * temp;

    temp = prev->next;
    prev->next = temp->next;

    free_data(temp->data);
    free(temp);
}

