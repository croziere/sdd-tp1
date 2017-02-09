//
// Created by gadoy on 09/02/2017.
//

#ifndef TP1_PARSER_H
#define TP1_PARSER_H
#define CHARGER_ERREUR_OUVERTURE -1
#define CHARGER_ERREUR_LECTURE -2
#define RETURN_SUCCESS 0
#define null NULL
#include "list.h"

typedef struct parser {
    int (*Charger)(char*, list_t*);
    void (*Sauvegarder)(char*, list_t);
}parser;

parser* parser_new();
int Charger (char* filename, list_t* pt);
void Sauvegarder (char* filename, list_t pt);
#endif //TP1_PARSER_H
