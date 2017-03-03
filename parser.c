//
// Created by gadoy on 09/02/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "list.h"
#include "parser.h"
#include "helper.h"
#include "agenda.h"

parser* parser_new (){
    parser* pt;
    malcx(pt, sizeof(parser),"Allocation du parser échouée")
    pt->Charger = &Charger;
    pt->Sauvegarder = &Sauvegarder;

    return pt;
}

int Charger (char* filename, list_t* pt){

    FILE * stream;
    char buf[30];
    char annee[5];
    char semaine[3];
    char jour;
    char heure[3];
    char nom[11];
    psemaine_t * cur;
    int retour;

    GestionnaireSemaine gestionnaireSemaine = new(GestionnaireSemaine);
    GestionnaireList gestionnaireList = new(GestionnaireList);

    if((stream = fopen(filename, "r")) == null)
    {
        return CHARGER_ERREUR_OUVERTURE;
    }

    while (fgets(buf, 30, stream))
    {
        buf[strlen(buf) - 1] = '\0';

        strncpy(annee, buf, 4);
        strncpy(semaine, buf+4, 2);
        strncpy(&jour, buf+6, 1);
        strncpy(heure, buf+7, 2);
        strcpy(nom, buf+9);

        annee[4] = '\0';
        semaine[2] = '\0';
        heure[2] = '\0';

        list_t pt_semaine = gestionnaireSemaine.Recherche(*pt, annee, semaine);
        if (pt_semaine == null)
        {
            psemaine_t data = new(semaine_t, annee, semaine, jour,heure,nom);
            gestionnaireList.AjouterMaillon(pt, data);
        }
        else
        {
            paction_t data = new(action_t, jour, heure, nom);
            gestionnaireList.AjouterMaillon(&((psemaine_t)pt_semaine->data)->actions, data);
        }

    }

    if(ferror(stream))
    {
        retour = CHARGER_ERREUR_LECTURE;
    }else{
        retour = RETURN_SUCCESS;
    }

    fclose(stream);

    return retour;
}

int Sauvegarder (char* filename, list_t pt){

    FILE * stream;

    if((stream = fopen(filename, "w")) == NULL)
    {
        return  CHARGER_ERREUR_OUVERTURE;
    }

    afficherList(pt, &saveAgenda, stream);

    if(ferror(stream)) {
        return CHARGER_ERREUR_LECTURE;
    }

    fclose(stream);

    return RETURN_SUCCESS;

}