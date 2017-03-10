/* -------------------------------------------------------------------- */
/* Module Parser           Lecture/Ecriture depuis un fichier           */
/* Implémentation de la lecture et écriture                             */
/* -------------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "agenda.h"

/* -------------------------------------------------------------------- */
/* parser_charger              Lit filename et remplis la liste pt      */
/*                                                                      */
/* En entrée: filename Le path du fichier                               */
/*            pt La liste à écrire                                      */
/*                                                                      */
/* En sortie: Retourne une constante RETURN_SUCCESS en cas de succès    */
/*            CHARGER_ERREUR_OUVERTURE en cas d'ouverture impossible    */
/*            CHARGER_ERREUR_LECTURE en cas d'erreur de lecture         */
/* -------------------------------------------------------------------- */
int parser_charger(char *filename, list_t *pt){

    FILE  * stream;

    char    buf[READ_LINE_MAX_SIZE];
    char    annee[READ_ANNEE_SIZE];
    char    semaine[READ_SEMAINE_SIZE];
    char    jour;
    char    heure[READ_HEURE_SIZE];
    char    nom[READ_NOM_SIZE];

    int     retour = RETURN_SUCCESS;

    if ((stream = fopen(filename, "r")) == NULL)
    {
        retour = CHARGER_ERREUR_OUVERTURE;
    }
    else
    {
        while (fgets(buf, READ_LINE_MAX_SIZE, stream))
        {
            if (buf[strlen(buf) - 1] == '\n') buf[strlen(buf) - 1] = '\0';

            agenda_lecture_format(buf, annee, semaine, &jour, heure, nom);

            agenda_action_ajouter(pt, annee, semaine, jour, heure, nom);
        }

        if (ferror(stream)) retour = CHARGER_ERREUR_LECTURE;

        fclose(stream);
    }

    return retour;
}

/* -------------------------------------------------------------------- */
/* parser_sauvegarder              Enregistre l'agenda au format texte  */
/*                                                                      */
/* En entrée: filename Le path du fichier à écrire                      */
/*            pt La liste à sauvegarder                                 */
/*                                                                      */
/* En sortie: Retourne une constante RETURN_SUCCESS en cas de succès    */
/*            CHARGER_ERREUR_OUVERTURE en cas d'ouverture impossible    */
/*            CHARGER_ERREUR_ECRITURE en cas d'erreur d'écriture        */
/* -------------------------------------------------------------------- */
int parser_sauvegarder(char *filename, list_t pt){

    FILE  * stream;
    int     retour = RETURN_SUCCESS;

    if ((stream = fopen(filename, "w")) == NULL)
    {
        retour = CHARGER_ERREUR_OUVERTURE;
    }
    else
    {
        list_afficher(pt, &agenda_sauvegarder, stream);

        if (ferror(stream)) retour =  CHARGER_ERREUR_ECRITURE;

        fclose(stream);
    }

    return retour;
}