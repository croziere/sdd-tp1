//
// Created by gadoy on 09/02/2017.
//

#ifndef TP1_PARSER_H
#define TP1_PARSER_H
#define CHARGER_ERREUR_OUVERTURE -1
#define CHARGER_ERREUR_LECTURE -2
#define RETURN_SUCCESS 0
#include "list.h"

typedef struct parser {
    int (*Charger)(char*, list_t*);
    int (*Sauvegarder)(char*, list_t);
}parser;

parser* parser_new();
int Charger (char* filename, list_t* pt);
int Sauvegarder (char* filename, list_t pt);
#endif //TP1_PARSER_H
