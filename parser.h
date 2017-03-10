/* -------------------------------------------------------------------- */
/* Module Parser           Lecture/Ecriture depuis un fichier           */
/* Implémentation de la lecture et écriture                             */
/* -------------------------------------------------------------------- */
#ifndef TP1_PARSER_H
#define TP1_PARSER_H

#include "list.h"

#define CHARGER_ERREUR_OUVERTURE -1
#define CHARGER_ERREUR_LECTURE -2
#define CHARGER_ERREUR_ECRITURE -3
#define RETURN_SUCCESS 0

/* Taille lue par ligne dans le fichier */
#define READ_LINE_MAX_SIZE 30

/* Taille de la chaine annee */
#define READ_ANNEE_SIZE 5

/* Taille de la chaine semaine */
#define READ_SEMAINE_SIZE 3

/* Taille de la chaine heure */
#define READ_HEURE_SIZE 3

/* Taille de la chaine nom */
#define READ_NOM_SIZE 11

int         parser_charger(char *, list_t *);
int         parser_sauvegarder(char *, list_t);

#endif //TP1_PARSER_H
