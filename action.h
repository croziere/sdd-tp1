//
// Created by Benjamin Rozière on 03/02/2017.
//

#ifndef TP1_ACTION_H
#define TP1_ACTION_H

#include "list.h"

typedef struct action
{
    char jour;
    char heure[2];
    char nom[10];
    struct action * suiv;

}action_t;


#endif //TP1_ACTION_H
