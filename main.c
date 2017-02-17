//
// Created by Benjamin Rozière on 03/02/2017.
//

#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "helper.h"
#include "parser.h"
#include "controller.h"
#include "agenda.h"

int main(int argc, char ** argv)
{
    int choix;

    parser * p = new(parser);
    list_t agenda = new(list_t);
    Controller ctrl = new(Controller);

    if(argc > 1)
    {
        if(p->Charger(argv[1], &agenda) != RETURN_SUCCESS)
        {
            fprintf(stderr, "Impossible de lire le fichier");
            return -1;
        }

        do
        {
            ctrl->ShowMenu();
            fprintf(stdout, "Action : ");
            fflush(stdout);
            fscanf(stdin, "%d%*c", &choix);
            ctrl->Do(choix, agenda);

        }while (choix != 0);

        p->Sauvegarder("test_sauvegarde", agenda);

        liberer_list(agenda, &libererAgenda);

    }
    else
    {
        fprintf(stderr, "Vous devez spécifier un fichier en argument\n");
    }

    return 0;
}
