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
    ctrl->ShowMenu = &controller_show_menu;

    return ctrl;
}

void controller_do(int choix, list_t list)
{
    switch (choix)
    {
        case 1:
            clrscr;
            break;

        case 2:
            afficherList(list, &afficherAgenda, stdout);
            break;

        default:
            break;
    }
}

void controller_show_menu(void)
{
    puts("-- Menu principal --");
    puts("\t[1] Efface l'écran");
    puts("\t[2] Affiche le contenu de l'agenda");
    puts("\t[0] Quitte le programme (et sauvegarde)");
}