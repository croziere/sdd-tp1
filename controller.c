//
// Created by Benjamin Rozière on 09/02/2017.
//

#include "controller.h"
#include "agenda.h"
#include "parser.h"
#include <string.h>

int controller_main(int argc, char **argv)
{
    int choix;

    list_t agenda = list_init();

    if(argc > 1)
    {
        if(parser_charger(argv[1], &agenda) != RETURN_SUCCESS)
        {
            fputs("Impossible de lire le fichier", stderr);
            return -1;
        }

        do
        {
            controller_show_menu();
            fprintf(stdout, "Action : ");
            fflush(stdout);
            fscanf(stdin, "%d%*c", &choix);
            controller_do(choix, agenda);

        } while (choix != 0);

        parser_sauvegarder("test_sauvegarde", agenda);

        list_liberer(agenda, &agenda_liberer);

    }
    else
    {
        fputs("Vous devez spécifier un fichier en argument", stderr);
    }

    return EXIT_SUCCESS;
}

void controller_do(int choix, list_t list)
{
    switch (choix)
    {
        case 1:
            clrscr;
            break;

        case 2:
            list_afficher(list, &agenda_afficher, stdout);
            break;

        case 3:
            controller_ajouter_action(list);

        case 4:
            controller_supprimer_action(list);

        default:
            break;
    }
}

void controller_show_menu(void)
{
    puts("-- Menu principal --");
    puts("\t[1] Efface l'écran");
    puts("\t[2] Affiche le contenu de l'agenda");
    puts("\t[3] Ajouter une action");
    puts("\t[4] Supprimer une action");
    puts("\t[0] Quitte le programme (et sauvegarde)");
}

int controller_ajouter_action(list_t list){
    char annee[5];
    char semaine[3];
    char jour;
    char heure[3];
    char nom[11];
    size_t len_nom;
    puts("Année: ");
    scanf("%s%*c",annee);
    puts("Semaine: ");
    scanf("%s%*c",semaine);
    puts("Jour: ");
    scanf("%c%*c",&jour);
    puts("Heure: ");
    scanf("%s%*c",heure);
    puts("Nom: ");
    fgets(nom,11,stdin);
    fpurge(stdin);
    annee[4] = '\0';
    semaine[2] = '\0';
    heure[2] = '\0';
    len_nom = strlen(nom);
    if (len_nom < 10){
        nom[strlen(nom)-1] = '\0';
    }


    list_t pt_semaine = agenda_rechercher(list, annee, semaine);
    if (pt_semaine == null)
    {
        psemaine_t data = agenda_semaine_creer(annee, semaine, jour, heure, nom);
        list_ajouter_maillon(&list, data);
    }
    else
    {
        paction_t data = action_creer(jour, heure, nom);
        list_ajouter_maillon(&((psemaine_t) pt_semaine->data)->actions, data);
    }
    return RETURN_SUCCESS;
}

int controller_supprimer_action(list_t list){

    char annee[5];
    char semaine[3];
    char jour;
    char heure[3];
    char nom[11];
    size_t len_nom;
    puts("Année: ");
    scanf("%s%*c",annee);
    puts("Semaine: ");
    scanf("%s%*c",semaine);
    puts("Jour: ");
    scanf("%c%*c",&jour);
    puts("Heure: ");
    scanf("%s%*c",heure);
    puts("Nom: ");
    fgets(nom,11,stdin);
    fpurge(stdin);
    annee[4] = '\0';
    semaine[2] = '\0';
    heure[2] = '\0';
    len_nom = strlen(nom);
    if (len_nom < 10){
        nom[strlen(nom)-1] = '\0';
    }
    list_t pt_semaine = agenda_rechercher_prec(list, annee, semaine);

    if (pt_semaine != null){
        list_t pt_action = action_rechercher_prec(((psemaine_t) (pt_semaine->next->data))->actions, jour, heure, nom);
        if (pt_action != null){
            list_supprimer_maillon(pt_action, &free);
            psemaine_t data = (psemaine_t) (pt_semaine->next->data);
            if (data->actions->next == null){
                list_supprimer_maillon(pt_semaine, &free);
            }
        }
    }
    return RETURN_SUCCESS;
}