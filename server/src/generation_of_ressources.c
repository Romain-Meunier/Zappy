/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** generation_of_ressources
*/

#include "../include/map.h"
#include <time.h>
#include <stdio.h>

list_of_ressources_t *add_ressources(list_of_ressources_t* list, int type, double proba, int cells) {
    list_of_ressources_t *new = malloc(sizeof(list_of_ressources_t));

    new->next = list;
    new->number = RESSOUCES(proba, cells);
    new->refferences = type;
}

list_of_ressources_t *delete_element(list_of_ressources_t *stack, list_of_ressources_t *to_delete)
{
    list_of_ressources_t *tmp = stack;
    list_of_ressources_t *delayed = stack;

    if (stack == to_delete) {
        tmp = stack;
        stack = stack->next;
        free(tmp);
        return (stack);
    }
    tmp = tmp->next;
    while (tmp != to_delete) {
        delayed = tmp;
        tmp = tmp->next;
    }
    delayed->next = tmp->next;
    free(tmp);
    return (stack);
}

int len_of_list(void *list)
{
    int i;
    for (i = 0; list; ++i)
        list = *(void**)list;
    return i;
}

list_of_ressources_t *generate_ressources_list(int width, int heigh)
{
    int cells = width * heigh;
    list_of_ressources_t *list = NULL;

    for (int i = 0; proba_at_creattion[i]; ++i)
        list = add_ressources(list, i, proba_at_creattion[i], cells);
    return (list);
}

void give_element_to_square(pos_t square, int type)
{
    square->elem[type]++;
}

void *return_list_element(void *begin, int pos)
{
    while (pos--)
        begin = *(void**)begin;
    return (begin);
}

pos_t square_from_coord(pos_t map, int x, int y)
{
    if (x > 0)
        return (square_from_coord(map->right, x - 1, y));
    if (x < 0)
        return (square_from_coord(map->left, x + 1, y));
    if (y > 0)
        return (square_from_coord(map->top, x, y - 1));
    if (y < 0)
        return (square_from_coord(map->bottom, x, y + 1));
    return (map);
}

void insert_ressources_in_map(pos_t map, int width, int heigh)
{
    list_of_ressources_t *ressources = generate_ressources_list(width, heigh);
    list_of_ressources_t *res;
    pos_t rand_square = NULL;

    srand(time(NULL));
    for (int y = 0; y != heigh; ++y) {
        for (int x = 0; x != width; ++x) {
            res = return_list_element(ressources, rand() % len_of_list(ressources));
            give_element_to_square(map, res->refferences);
            if (!--res->number)
                ressources = delete_element(ressources, res);
            map = map->right;
        }
        map = map->bottom;
    }
    while (ressources) {
        res = return_list_element(ressources, rand() % len_of_list(ressources));
        rand_square = square_from_coord(map, rand() % width, rand() % heigh);
        give_element_to_square(rand_square, res->refferences);
        if (!--res->number)
            ressources = delete_element(ressources, res);
    }
}