//
// Created by Benjamin Rozière on 09/02/2017.
//

#ifndef TP1_HELPER_H
#define TP1_HELPER_H

#define malcx(ptr, size, error_msg) if((ptr = (__typeof__(ptr))malloc(size)) == NULL) { perror(error_msg);exit(errno); }
#define foreach(array, current) __typeof__(array) current = array; while(current)

#define clrscr printf("\033[H\033[2J")

#endif //TP1_HELPER_H
