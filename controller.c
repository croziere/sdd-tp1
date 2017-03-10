/* -------------------------------------------------------------------- */
/* Module Controller           Gestion des actions utilisateur          */
/* Implémentation des actions                                           */
/* -------------------------------------------------------------------- */

#include <string.h>
#include "controller.h"
#include "agenda.h"
#include "parser.h"

/* -------------------------------------------------------------------- */
/* controller_main               Menu principal                         */
/*                                                                      */
/* En entrée: argc Nombres d'arguments du programme                     */
/*            argv Tableau des arguments                                */
/*                                                                      */
/* En sortie: EXIT_SUCCESS si le programme s'est executé correctement   */
/* -------------------------------------------------------------------- */
int controller_main(int argc, char **argv)
{
    int         choix;
    int         retour = EXIT_SUCCESS;
    agenda_t    agenda = agenda_creer();

    if (argc > 1)
    {
        if (parser_charger(argv[1], &agenda) != RETURN_SUCCESS)
        {
            fputs("Impossible de lire le fichier", stderr);
            retour = EXIT_FAILURE;
        }
        else
        {
            do
            {
                controller_show_menu();
                fprintf(stdout, "Action : ");
                fflush(stdout);
                fscanf(stdin, "%d%*c", &choix);
                controller_do(choix, agenda);

            } while (choix != 0);

            if (parser_sauvegarder("test_sauvegarde", agenda) != RETURN_SUCCESS)
            {
                fputs("Impossible de sauvegarder le fichier", stderr);
                retour = EXIT_FAILURE;
            }

            agenda_liberer(agenda);
        }
    }
    else
    {
        fputs("Vous devez spécifier un fichier en argument", stderr);
    }

    return retour;
}

/* -------------------------------------------------------------------- */
/* controller_do               Choisit et execute l'action utilisateur  */
/*                                                                      */
/* En entrée: choix Choix de l'utilisateur                              */
/*            list L'agenda                                             */
/* -------------------------------------------------------------------- */
void controller_do(int choix, list_t agenda)
{
    switch (choix)
    {
        case 1:
            clrscr;
            break;

        case 2:
            agenda_afficher_stdout(agenda);
            break;

        case 3:
            controller_ajouter_action(agenda);
            break;

        case 4:
            controller_supprimer_action(agenda);
            break;

        default:
            clrscr;
            break;
    }
}

/* -------------------------------------------------------------------- */
/* controller_show_menu               Affiche le menu sur stdout        */
/* -------------------------------------------------------------------- */
void controller_show_menu(void)
{
    puts("-- Menu principal --");
    puts("\t[1] Efface l'écran");
    puts("\t[2] Affiche le contenu de l'agenda");
    puts("\t[3] Ajouter une action");
    puts("\t[4] Supprimer une action");
    puts("\t[0] Quitte le programme (et sauvegarde)");
}

/* -------------------------------------------------------------------- */
/* controller_ajouter_action               Création d'une action        */
/*                                                                      */
/* En entrée: list L'agenda                                             */
/* -------------------------------------------------------------------- */
int controller_ajouter_action(list_t list)
{
    char    annee[5];
    char    semaine[3];
    char    jour;
    char    heure[3];
    char    nom[11];
    size_t  len_nom;

    puts("Année : ");
    scanf("%s%*c", annee);

    puts("Semaine : ");
    scanf("%s%*c", semaine);

    puts("Jour : ");
    scanf("%c%*c", &jour);

    puts("Heure : ");
    scanf("%s%*c", heure);

    puts("Nom : ");
    fgets(nom, 11, stdin);

    fflush(stdin);

    annee[4] = '\0';
    semaine[2] = '\0';
    heure[2] = '\0';

    len_nom = strlen(nom);

    if (len_nom < 10){
        nom[strlen(nom)-1] = '\0';
    }

    agenda_action_ajouter(&list, annee, semaine, jour, heure, nom);

    return RETURN_SUCCESS;
}

/* -------------------------------------------------------------------- */
/* controller_supprimer_action   Suppression d'une action               */
/*                                                                      */
/* En entrée: list L'agenda                                             */
/* -------------------------------------------------------------------- */
int controller_supprimer_action(list_t list){

    char    annee[5];
    char    semaine[3];
    char    jour;
    char    heure[3];
    char    nom[11];
    size_t  len_nom;

    puts("Année : ");
    scanf("%s%*c", annee);

    puts("Semaine : ");
    scanf("%s%*c", semaine);

    puts("Jour : ");
    scanf("%c%*c", &jour);

    puts("Heure : ");
    scanf("%s%*c", heure);

    puts("Nom : ");
    fgets(nom, 11, stdin);

    fflush(stdin);

    annee[4] = '\0';
    semaine[2] = '\0';
    heure[2] = '\0';

    len_nom = strlen(nom);

    if (len_nom < 10)
    {
        nom[strlen(nom)-1] = '\0';
    }
    list_t pt_semaine = agenda_rechercher_prec(list, annee, semaine);

    if (pt_semaine != NULL)
    {
        list_t pt_action = action_rechercher_prec(((psemaine_t) list_data(list_suivant(pt_semaine)))->actions, jour, heure, nom);
        if (pt_action != NULL)
        {
            list_supprimer_maillon(pt_action, &free);
            psemaine_t data = (psemaine_t) list_data(list_suivant(pt_semaine));
            if (list_suivant(data->actions) == NULL)
            {
                list_supprimer_maillon(pt_semaine, &free);
            }
        }
    }
    return RETURN_SUCCESS;
}