//
// Created by Benjamin Rozière on 09/02/2017.
//

#ifndef TP1_CONTROLLER_H
#define TP1_CONTROLLER_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "helper.h"
#include "list.h"

int     controller_main(int, char **);
void    controller_do(int, list_t);
void    controller_show_menu(void);
int     controller_ajouter_action(list_t);
int     controller_supprimer_action(list_t);

#endif //TP1_CONTROLLER_H
