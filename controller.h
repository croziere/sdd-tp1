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

typedef struct controller
{
    void (*Do)(int, list_t);
    void (*ShowMenu)(void);
}controller_t, *Controller;

Controller Controller_new();

void controller_do(int, list_t);
void controller_show_menu(void);

#endif //TP1_CONTROLLER_H
