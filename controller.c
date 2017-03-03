//
// Created by Benjamin Rozière on 09/02/2017.
//

#include "controller.h"
#include "list.h"
#include "agenda.h"
#include "parser.h"
#include <string.h>

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

        case 3:
            ajouter_action(list);

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
    puts("\t[0] Quitte le programme (et sauvegarde)");
}

int ajouter_action(list_t list){
    GestionnaireSemaine gestionnaireSemaine = new(GestionnaireSemaine);
    GestionnaireList gestionnaireList = new(GestionnaireList);
    char annee[5];
    char semaine[3];
    char jour;
    char heure[3];
    char nom[11];
    int len_nom;
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


    list_t pt_semaine = gestionnaireSemaine.Recherche(list, annee, semaine);
    if (pt_semaine == null)
    {
        psemaine_t data = new(semaine_t, annee, semaine, jour,heure,nom);
        gestionnaireList.AjouterMaillon(&list, data);
    }
    else
    {
        paction_t data = new(action_t, jour, heure, nom);
        gestionnaireList.AjouterMaillon(&((psemaine_t)pt_semaine->data)->actions, data);
    }
}