/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include <stddef.h>
#include <stdlib.h>
#include "ressource.h"
#include "player.h"

#define RESSOUCES(proba, cell) (cells * proba ? cells * proba : 1)

static double proba_at_creattion[] = {
    0.5, // food
    0.3, // linemate
    0.15, // deraumere
    0.1, // sibur
    0.1, // mendiane
    0.08, // phiras
    0.05 // thystame
};

// typedef struct element_s {
//     int elem;
//     struct element_s *next;
// }element_t, *elem_t;

typedef struct player_on_square_s {
    struct player_on_square_s *next;
    player_t player;
}player_on_square_t;

typedef struct square_s {
    int elem[RESSOURCES_NB];
    player_on_square_t *player;
    struct square_s *top;
    struct square_s *bottom;
    struct square_s *left;
    struct square_s *right;
}square_t, *pos_t;



pos_t new_node(void);
void left_to_right(pos_t map);
void top_to_bottom(pos_t map);
void a_true_world(pos_t map);
void link_every_square(pos_t map, int width, int heigh);
int *global_int(void);

/**
** @brief delete the map
**
** @param width of the map
** @param heigh of the map
**/
pos_t create_map(int width, int heigh);

/**
** @brief delete the map
**
** @param map pointer of the map
** @param width of the map
** @param heigh of the map
**/
void delete_map(pos_t map, int width, int heigh);

/**
** @brief generate all ressource in the map
**
** @param map pointer of the map
** @param width of the map
** @param heigh of the map
**/
void insert_ressources_in_map(pos_t map, int width, int heigh);

/**
** @brief from a squre return the quare to a position
**
** @param map pointer of the map
** @param x square x to the target
** @param y suqre y to the targer
**/
pos_t square_from_coord(pos_t map, int x, int y);

char *parser_map(pos_t map, int xmap ,int  ymap);

#endif /* !MAP_H_ */
