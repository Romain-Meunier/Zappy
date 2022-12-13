/*
** EPITECH PROJECT, 2021
** server
** File description:
** action
*/

#ifndef ACTION_H_
#define ACTION_H_


#include "../include/map.h"
#include <unistd.h>

#define BASE_VISION 3
#define KO write(player->fd, "ok\n", 3)
typedef void EVOLUTION(player_t, pos_t);

EVOLUTION to_level_two;
EVOLUTION to_level_three;
EVOLUTION to_level_four;
EVOLUTION to_level_five;
EVOLUTION to_level_six;
EVOLUTION to_level_seven;
EVOLUTION to_level_height;

static EVOLUTION *function_evolution[] = {
    &to_level_two,
    &to_level_three,
    &to_level_four,
    &to_level_five,
    &to_level_six,
    &to_level_seven,
    &to_level_height
};

void look(player_t player, pos_t map, __attribute__((unused)) char *message);
void direction_left(player_t player, __attribute__((unused)) pos_t map, __attribute__((unused)) char *message);
void direction_rift(player_t player, __attribute__((unused)) pos_t map, __attribute__((unused)) char *message);
void move(player_t player, pos_t map,  __attribute__((unused)) char *message);
void watch_inventory(player_t player, __attribute__((unused)) pos_t map, __attribute__((unused)) char *message);
void fork_a_player(player_t player, pos_t map, __attribute__((unused)) char *message);
void take_object(player_t player, pos_t map, char *message);
void drop_object(player_t player, pos_t map, char *message);
void elevation(player_t player, pos_t map, __attribute__((unused)) char *message);
void broadcast(player_t player, pos_t map, char *message);
void eject_players(player_t player, pos_t map, __attribute__((unused)) char *message);

#endif /* !ACTION_H_ */
