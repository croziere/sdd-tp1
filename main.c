//
// Created by Benjamin Rozière on 03/02/2017.
//

#include <printf.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "helper.h"
#include "parser.h"

int main(int argc, char ** argv)
{
    char * path, buf;
    int choix;
    parser * p = new(parser);
    list_t agenda = init_list();

    if(argc > 1)
    {
        malcx(path, sizeof(char)*strlen(argv[1]), "Allocation argument impossible")
        strcpy(path, argv[1]);
        if(p->Charger(path, &agenda) != RETURN_SUCCESS)
        {
            fprintf(stderr, "Impossible de lire le fichier");
            return -1;
        }

        do
        {
            fprintf(stdout, "Action : ");
            fscanf(stdin, "%d%*c", &choix);

        }while (choix != 0);

        p->Sauvegarder(path, agenda);

    }
    else
    {
        fprintf(stderr, "Vous devez spécifier un fichier en argument\n");
    }

    return 0;
}
