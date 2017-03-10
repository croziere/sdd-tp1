/* -------------------------------------------------------------------- */
/* Module Controller           Gestion des actions utilisateur          */
/* -------------------------------------------------------------------- */

#ifndef TP1_CONTROLLER_H
#define TP1_CONTROLLER_H

#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#include "list.h"

/* Menu principal et affichage */
int     controller_main(int, char **);
void    controller_do(int, list_t);
void    controller_show_menu(void);

/* Actions */
int     controller_ajouter_action(list_t);
int     controller_supprimer_action(list_t);

#endif //TP1_CONTROLLER_H
