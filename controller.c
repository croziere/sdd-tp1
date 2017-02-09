//
// Created by Benjamin Rozière on 09/02/2017.
//

#include "controller.h"

Controller Controller_new()
{
    Controller ctrl;
    malcx(ctrl, sizeof(controller_t), "Impossible d'allouer le controlleur");
    ctrl->Do = &controller_do;
}

void controller_do(int choix)
{
    switch (choix)
    {
        case 1:
            fprintf(stdout, "Choix 1\n");
            break;

        default:
            break;
    }
}