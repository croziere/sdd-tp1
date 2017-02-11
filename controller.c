//
// Created by Benjamin Rozière on 09/02/2017.
//

#include "controller.h"
#include "list.h"
#include "agenda.h"

Controller Controller_new()
{
    Controller ctrl;
    malcx(ctrl, sizeof(controller_t), "Impossible d'allouer le controlleur");
    ctrl->Do = &controller_do;

    return ctrl;
}

void controller_do(int choix, list_t list)
{
    switch (choix)
    {
        case 1:
            fprintf(stdout, "Choix 1\n");
            break;

        case 2:
            afficherList(list, &afficherAgenda, stdout);
            break;

        default:
            break;
    }
}