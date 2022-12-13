/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** create_map
*/

#include "../include/map.h"

pos_t new_node(void)
{
    pos_t new = malloc(sizeof(square_t));
    for (int i = 0; i != RESSOURCES_NB; ++i)
        new->elem[i] = 0;
    new->top = NULL;
    new->bottom = NULL;
    new->left = NULL;
    new->right = NULL;
    return (new);
}

void left_to_right(pos_t map)
{
    pos_t tmp = map;
    while (tmp->right) {
        tmp = tmp->right;
    }
    while (tmp) {
        tmp->right = map;
        map->left = tmp;
        map = map->bottom;
        tmp = tmp->bottom;
    }
}

void top_to_bottom(pos_t map)
{
    pos_t tmp = map;
    while (tmp->bottom)
        tmp = tmp->bottom;
    while (!tmp->bottom) {
        tmp->bottom = map;
        map->top = tmp;
        map = map->right;
        tmp = tmp->right;
    }
}

void a_true_world(pos_t map)
{
    left_to_right(map);
    top_to_bottom(map);
}

int *global_int(void)
{
    static int global[2];

    return global;
}

void link_every_square(pos_t map, int width, int heigh)
{
    pos_t tmp = map;
    pos_t keep_left = map;
    int a = 0; 
    while (map->bottom) {
        int b = 0;
        ++a;
        tmp = map->bottom;
        while (map) {
            ++b;
            map->bottom = tmp;
            tmp->top = map;
            tmp = tmp->right;
            map = map->right;
        }
        keep_left = keep_left->bottom;
        map = keep_left;
    }
}
