/* -------------------------------------------------------------------- */
/* Module Helper           Macro utiles                                 */
/* -------------------------------------------------------------------- */
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
/* foreach           Déclaration de boucle de parcours d'une liste      */
/*                                                                      */
/* En entrée: array La liste à parcourir                                */
/*            current L'identifiant de l'élement courant                */
/* Exemple foreach(liste, cur)                                          */
/*         {                                                            */
/*              next(cur);                                              */
/*         }                                                            */
/* -------------------------------------------------------------------- */
#define foreach(array, current) __typeof__(array) current = array; while(current != NULL)

/* -------------------------------------------------------------------- */
/* next           Utilisé avec foreach, permet l'avancée de la boucle   */
/*                                                                      */
/* En entrée: cur Le pointeur sur l'élement courant de la liste         */
/* -------------------------------------------------------------------- */
#define next(cur) cur = list_suivant(cur)

/* -------------------------------------------------------------------- */
/* clrscr           Efface l'écran de la console (equiv. clear)         */
/* -------------------------------------------------------------------- */
#define clrscr printf("\033[H\033[2J")

#endif //TP1_HELPER_H
