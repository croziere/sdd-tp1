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
    return null;
}

/// Free a generic list
/// \param list
/// \param free_data
void liberer_list(list_t list, void (*free_data)(void *))
{
    maillon_t * cur;
    maillon_t * temp;

    cur = list->next;

    while (cur != NULL)
    {
        temp = cur;
        free_data(temp->data);
        cur = cur->next;
        free(temp);
    }

    free(list);
}

/// Return 0 if the list is empty
/// \param list
/// \return
int estVide(list_t list)
{
    return (list == NULL);
}

/// Add a node in the list
/// \param prev
/// \param data
void ajouter_maillon(maillon_t **prev, void *data)
{
    maillon_t * wrap = null;

    malcx(wrap, sizeof(maillon_t), "Impossible d'allouer le maillon")

    wrap->data = data;

    if(*prev != null)
    {
        wrap->next = (*prev)->next;
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
void supprimer_maillon(maillon_t *prev, void (*free_data)(void *))
{
    maillon_t * temp;

    temp = prev->next;
    prev->next = temp->next;

    free_data(temp->data);
    free(temp);
}

/// Display the list on stream
/// \param list
/// \param print_data
/// \param stream
void afficher_list(list_t list, void (*print_data)(void *, FILE *), FILE *stream)
{
    foreach(list, cur)
    {
        print_data(cur->data, stream);
    }
}

