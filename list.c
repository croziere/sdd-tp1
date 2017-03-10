/* -------------------------------------------------------------------- */
/* Module List           Gestion d'une liste chainée générique          */
/* -------------------------------------------------------------------- */

#include "list.h"
#include "helper.h"

/* -------------------------------------------------------------------- */
/* list_init           Créé une liste vide                              */
/*                                                                      */
/* En sortie: Une list_t vide                                           */
/* -------------------------------------------------------------------- */
list_t list_init()
{
    return NULL;
}

/* -------------------------------------------------------------------- */
/* list_liberer           Libère la mémoire d'une liste                 */
/*                                                                      */
/* En entrée: list La liste à libérer                                   */
/*            free_data Un pointeur de fonction sur celle permettant    */
/*            de libérer le contenu des maillons (data)                 */
/*                                                                      */
/* -------------------------------------------------------------------- */
void list_liberer(list_t list, void (*free_data)(void *))
{
    maillon_t * temp;

    foreach(list, cur)
    {
        temp = cur;
        free_data(list_data(temp));
        next(cur);
        free(temp);
    }

    free(list);
}

/* -------------------------------------------------------------------- */
/* list_est_vide               Recherche une semaine dans l'agenda      */
/*                                                                      */
/* En entrée: list La liste à tester                                    */
/*                                                                      */
/* En sortie: Retourne 1 si la liste est vide, O sinon                  */
/* -------------------------------------------------------------------- */
int list_est_vide(list_t list)
{
    return (list == NULL);
}

/* -------------------------------------------------------------------- */
/* list_ajouter_maillon        Ajoute un nouveau maillon après prev     */
/*                                                                      */
/* En entrée: prev Maillon précédent celui à ajouter                    */
/*            data Pointeur sur les données du maillon                  */
/* -------------------------------------------------------------------- */
void list_ajouter_maillon(maillon_t **prev, void *data)
{
    maillon_t * wrap = NULL;

    malcx(wrap, sizeof(maillon_t), "Impossible d'allouer le maillon")

    wrap->data = data;

    if(!list_est_vide(*prev))
    {
        wrap->next = list_suivant(*prev);
        (*prev)->next = wrap;
    }
    else
    {
        wrap->next = NULL;
        *prev = wrap;
    }

}

/* -------------------------------------------------------------------- */
/* list_supprimer_maillon               Supprime le maillon après prev  */
/*                                                                      */
/* En entrée: prev Le maillon avant celui à supprimer                   */
/*            free_data Pointeur sur la fonction de libération          */
/*            des données du maillon                                    */
/* -------------------------------------------------------------------- */
void list_supprimer_maillon(maillon_t *prev, void (*free_data)(void *))
{
    maillon_t * temp;

    temp = list_suivant(prev);
    prev->next = list_suivant(temp);

    free_data(list_data(temp));
    free(temp);
}

/* -------------------------------------------------------------------- */
/* list_afficher               Ecrit la liste sur stream                */
/*                                                                      */
/* En entrée: list La liste à écrire                                    */
/*            print_data Pointeur sur la fonction d'écriture des données*/
/*            stream Flux sur lequel écrire                             */
/* -------------------------------------------------------------------- */
void list_afficher(list_t list, void (*print_data)(void *, FILE *), FILE *stream)
{
    foreach(list, cur)
    {
        print_data(list_data(cur), stream);

        next(cur);
    }
}

/* -------------------------------------------------------------------- */
/* list_data               Retourne le pointeur des données du maillon  */
/* Permet de masquer l'implémentation de la structure                   */
/*                                                                      */
/* En entrée: pmaillon Le maillon d'où récupérer les données            */
/*                                                                      */
/* En sortie: Retourne un pointeur non typé sur les données (ou NULL)   */
/* -------------------------------------------------------------------- */
void  * list_data(maillon_t * pmaillon)
{
    return pmaillon->data;
}

/* -------------------------------------------------------------------- */
/* list_suivant                Retourne le maillon suivant              */
/* Permet de masquer l'implémentation de la structure                   */
/* En entrée: pmaillon Le maillon courant                               */
/*                                                                      */
/* En sortie: Retourne l'adresse du pointeur suivant (ou NULL)          */
/* -------------------------------------------------------------------- */
maillon_t * list_suivant(maillon_t * pmaillon)
{
    return pmaillon->next;
}

