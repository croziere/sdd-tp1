//
// Created by Benjamin Rozière on 03/02/2017.
//

#ifndef TP1_ACTION_H
#define TP1_ACTION_H

typedef struct action
{
    char jour;
    char heure[2];
    char nom[10];
}action_t, *paction_t;

paction_t initAction(void);

void afficherActions(paction_t);
void afficherAction(paction_t);

#endif //TP1_ACTION_H
