//
// Created by Benjamin Rozière on 09/02/2017.
//

#ifndef TP1_HELPER_H
#define TP1_HELPER_H

#include <stdlib.h>
#include <errno.h>

/* -------------------------------------------------------------------- */
/* malcx           Alloue une zone mémoire de taille size et met son    */
/* adresse dans ptr, en cas d'échec quitte le programme avec le         */
/* message error_msg et errno                                           */
/*                                                                      */
/* En entrée: ptr Le pointeur où stocker l'adresse                      */
/*            size La taille de la zone à allouer                       */
/*            error_msg Le message d'erreur                             */
/*                                                                      */
/* -------------------------------------------------------------------- */
#define malcx(ptr, size, error_msg) if((ptr = (__typeof__(ptr))malloc(size)) == NULL) { perror(error_msg);exit(errno); }

/* -------------------------------------------------------------------- */
/* agenda_rechercher           Recherche une semaine dans l'agenda      */
/*                                                                      */
/* En entrée: pt La liste des semaines (Agenda)                         */
/*            annee Une chaine contenant l'année recherchée             */
/*            semaine Une chaine contenant la semaine recherchée        */
/*                                                                      */
/* En sortie: Retourne l'adresse de la semaine ou NULL si non trouvé    */
/* -------------------------------------------------------------------- */
#define foreach(array, current) __typeof__(array) current = array; while(current != NULL)

/* -------------------------------------------------------------------- */
/* agenda_rechercher           Recherche une semaine dans l'agenda      */
/*                                                                      */
/* En entrée: pt La liste des semaines (Agenda)                         */
/*            annee Une chaine contenant l'année recherchée             */
/*            semaine Une chaine contenant la semaine recherchée        */
/*                                                                      */
/* En sortie: Retourne l'adresse de la semaine ou NULL si non trouvé    */
/* -------------------------------------------------------------------- */
#define next(cur) cur = list_suivant(cur)

/* -------------------------------------------------------------------- */
/* clrscr           Efface l'écran de la console (equiv. clear)         */
/*                                                                      */
/* -------------------------------------------------------------------- */
#define clrscr printf("\033[H\033[2J")

#endif //TP1_HELPER_H
