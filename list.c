//
// Created by Benjamin Rozière on 09/02/2017.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "list.h"
#include "helper.h"

list_t list_init()
{
    return NULL;
}

/// Free a generic list
/// \param list
/// \param free_data
void list_liberer(list_t list, void (*free_data)(void *))
{
    maillon_t * cur;
    maillon_t * temp;

    cur = list_suivant(list);

    while (cur != NULL)
    {
        temp = cur;
        free_data(list_data(temp));
        cur = list_suivant(cur);
        free(temp);
    }

    free(list);
}

/// Return 0 if the list is empty
/// \param list
/// \return
int list_est_vide(list_t list)
{
    return (list == NULL);
}

/// Add a node in the list
/// \param prev
/// \param data
void list_ajouter_maillon(maillon_t **prev, void *data)
{
    maillon_t * wrap = NULL;

    malcx(wrap, sizeof(maillon_t), "Impossible d'allouer le maillon")

    wrap->data = data;

    if(*prev != NULL)
    {
        wrap->next = list_suivant(*prev);
        (*prev)->next = wrap;
    }
    else
    {
        wrap->next = NULL;
        *prev = wrap;
    }

}

/// Remove a node from the list
/// \param prev
/// \param free_data
void list_supprimer_maillon(maillon_t *prev, void (*free_data)(void *))
{
    maillon_t * temp;

    temp = list_suivant(prev);
    prev->next = list_suivant(temp);

    free_data(list_data(temp));
    free(temp);
}

/// Display the list on stream
/// \param list
/// \param print_data
/// \param stream
void list_afficher(list_t list, void (*print_data)(void *, FILE *), FILE *stream)
{
    foreach(list, cur)
    {
        print_data(list_data(cur), stream);

        next(cur);
    }
}

void  * list_data(maillon_t * pmaillon)
{
    return pmaillon->data;
}

maillon_t * list_suivant(maillon_t * pmaillon)
{
    return pmaillon->next;
}

