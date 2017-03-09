//
// Created by Benjamin Rozière on 09/02/2017.
//

#ifndef TP1_HELPER_H
#define TP1_HELPER_H

#include <stdlib.h>
#include <errno.h>

#define malcx(ptr, size, error_msg) if((ptr = (__typeof__(ptr))malloc(size)) == NULL) { perror(error_msg);exit(errno); }

#define foreach(array, current) __typeof__(array) current; malcx(current, sizeof(__typeof__(*current)), "Alloc foreach impossible"); current->next = array; while((current = current->next) != NULL)

#define new(type, ...) type ## _new(__VA_ARGS__)

#define clrscr printf("\033[H\033[2J")

#define null NULL

#endif //TP1_HELPER_H
