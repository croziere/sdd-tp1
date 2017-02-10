//
// Created by Benjamin Rozière on 09/02/2017.
//

#ifndef TP1_CONTROLLER_H
#define TP1_CONTROLLER_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "helper.h"

typedef struct controller
{
    void (*Do)(int);
}controller_t, *Controller;

Controller Controller_new();

void controller_do(int);

#endif //TP1_CONTROLLER_H
