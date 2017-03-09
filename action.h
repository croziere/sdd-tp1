//
// Created by Benjamin Rozière on 03/02/2017.
//

#ifndef TP1_ACTION_H
#define TP1_ACTION_H

typedef struct action
{
    char jour;
    char heure[3];
    char nom[11];
}action_t, *paction_t;


typedef struct gestionnaireAction {

}GestionnaireAction;

paction_t action_t_new(char, char *, char *);

void afficherAction(void *, FILE * stream);

void saveAction(void * , FILE*);

#endif //TP1_ACTION_H
