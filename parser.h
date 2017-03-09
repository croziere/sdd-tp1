//
// Created by gadoy on 09/02/2017.
//

#ifndef TP1_PARSER_H
#define TP1_PARSER_H

#include "list.h"

#define CHARGER_ERREUR_OUVERTURE -1
#define CHARGER_ERREUR_LECTURE -2
#define RETURN_SUCCESS 0

int         parser_charger(char *, list_t *);
int         parser_sauvegarder(char *, list_t);

#endif //TP1_PARSER_H
