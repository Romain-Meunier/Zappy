/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** delete_and_base_of_map
*/

#include "../include/map.h"

void delete_player_of_map(player_on_square_t *list)
{
    player_on_square_t *delayed = list;

    while (list) {
        delayed = list;
        list = list->next;
        free(delayed);
    }
}

void delete_map(pos_t map, int width, int heigh)
{
    pos_t tmp = map->bottom;

    for (int x = 0; x != heigh; ++x) {
        for (int y = 0; y != width; ++y) {
            if (y == width - 1) {
                delete_player_of_map(map->player);
                free(map);
                map = NULL;
            }
            else {
                map = map->right;
                delete_player_of_map(map->left->player);
                free(map->left);
                map->left = NULL;
            }
        }
        if (x == heigh - 1)
            break;
        map = tmp;
        tmp = tmp->bottom;
    }
}

pos_t create_map(int width, int heigh)
{
    pos_t map = NULL;
    pos_t keep_left = NULL;
    pos_t first = NULL;

    global_int()[0] = width;
    global_int()[1] = heigh;
    for (int x = 0; x != heigh; ++x) {
        for (int y = 1; y != width; ++y) {
            if (map) {
                map->right = new_node();
                map->right->left = map;
                map = map->right;
            } else {
                map = new_node();
                first = map;
                keep_left = map;
                map->right = new_node();
                map->right->left = map;
                map = map->right;
            }
        }
        if (x + 1 == heigh)
            break;
        keep_left->bottom = new_node();
        keep_left = keep_left->bottom;
        map = keep_left;
    }
    link_every_square(first, width, heigh);
    a_true_world(first);
    insert_ressources_in_map(first, width, heigh);
    return (first);
}