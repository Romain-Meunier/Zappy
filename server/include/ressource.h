/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** ressource
*/

#ifndef RESSOURCE_H_
#define RESSOURCE_H_

#define RESSOURCES_NB 7

#include <string.h>

static const char *ressources_name[] = {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"
};

typedef struct list_of_ressources_s {
    struct list_of_ressources_s *next;
    int number;
    int refferences;
}list_of_ressources_t;

char *int_to_string(int nb);
int len_of_list(void *list);

#endif /* !RESSOURCE_H_ */
