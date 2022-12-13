/*
** EPITECH PROJECT, 2021
** server
** File description:
** action
*/

#include "../include/action.h"
#include <stdio.h>
#include <unistd.h>

int square_in_vision(int lvl, int number)
{
    if (lvl)
        return (3 + number + square_in_vision(lvl - 1, number + 2));
    return (0);
}

void send_player(player_on_square_t *players, int fd)
{
    while (players) {
        write(fd, players->player->uuid, 16);
        write(fd, " ", 1);
        players = players->next;
    }
}

void send_ressources(pos_t square, int fd)
{
    for (int i = 0; i != RESSOURCES_NB; ++i) {
        if (square->elem[i]) {
            char *nb = int_to_string(square->elem[i]);
            write(fd, ressources_name[i], strlen(ressources_name[i]));
            write(fd, " ", 1);
            write(fd, nb, strlen(nb));
            write(fd, " ", 1);
            free(nb);
        }
    }
}

void send_ressources_of_player(player_t player)
{
    for (int i = 0; i != RESSOURCES_NB; ++i) {
        if (player->ressources[i]) {
            char *nb = int_to_string(player->ressources[i]);
            write(player->fd, ressources_name[i], strlen(ressources_name[i]));
            write(player->fd, " ", 1);
            write(player->fd, nb, strlen(nb));
            write(player->fd, ",", 1);
            free(nb);
        }
    }
}

void look(player_t player, pos_t map, __attribute__((unused)) char *message)
{
    pos_t player_position = square_from_coord(map, player->x, player->y);
    int vision = BASE_VISION;
    // printf("%d\n", square_in_vision(player->level, 0) + 1);
    // pos_t square_vue[square_in_vision(player->level, 0) + 1];
    int pos = 0;

    // square_vue[pos++] = player_position;
    map = player_position;
    write(player->fd, "[", 1);
    send_player(map->player, player->fd);
    send_ressources(player_position, player->fd);
    write(player->fd, ",", 1);
    for (int i = 0; i != player->level; ++i, vision += 2) {
        map = map->left;
        map = map->top;
        player_position = map;
        for (int j = 0; j != vision; ++j) {
            // square_vue[pos++] = player_position;
            send_player(map->player, player->fd);
            send_ressources(player_position, player->fd);
            player_position = player_position->right;
            if (i != player->level - 1)
                write(player->fd, ",", 1);
        }
    }
    write(player->fd, "]", 1);
    write(player->fd, "\n", 1);
}

void direction_left(player_t player, __attribute__((unused)) pos_t map, __attribute__((unused)) char *message)
{
    player->direction = (player->direction - 1);
    if (player->direction < 0)
        player->direction = LEFT;
    write(player->fd, "ok\n", 3);
}

void direction_rift(player_t player, __attribute__((unused)) pos_t map, __attribute__((unused)) char *message)
{
    player->direction = (player->direction + 1) % 4;
    write(player->fd, "ok\n", 3);
}

player_on_square_t *remove_player_from_square(player_on_square_t *stack, player_on_square_t *to_remove)
{
    player_on_square_t *tmp = stack;
    player_on_square_t *delayed = stack;

    if (stack == to_remove) {
        tmp = stack;
        stack = stack->next;
        return (stack);
    }
    tmp = tmp->next;
    while (tmp != to_remove) {
        delayed = tmp;
        tmp = tmp->next;
    }
    delayed->next = tmp->next;
    return (stack);
}

player_on_square_t *find_the_node_of_player(player_t player, player_on_square_t *stack)
{
    while (stack->player != player)
        stack = stack->next;
    return (stack);
}

player_on_square_t *from_created_node_add_player(player_on_square_t *dest, player_on_square_t *to_move)
{
    to_move->next = dest;
    dest = to_move;
    return (dest);
}

void move_player(player_t player, pos_t source, pos_t destination)
{
    player_on_square_t *node_player = find_the_node_of_player(player, source->player);

    source->player = remove_player_from_square(source->player, node_player);
    destination->player = from_created_node_add_player(destination->player, node_player);
    //write(player->fd, "ok\n", 3);
}

void move(player_t player, pos_t map, __attribute__((unused)) char *message)
{
    map = square_from_coord(map, player->x, player->y);
    if (player->direction == TOP) {
        move_player(player, map, map->top);
        player->y = player->y + 1 % global_int()[1];
    }
    if (player->direction == RIGHT) {
        move_player(player, map, map->right);
        player->x = player->x + 1 % global_int()[0];
    }
    if (player->direction == BOTTOM) {
        move_player(player, map, map->bottom);
        player->y = player->y - 1;
        if (player->y < 0)
            player->y = global_int()[1];
    }
    if (player->direction == LEFT) {
        move_player(player, map, map->left);
        player->x = player->x - 1;
        if (player->x < 0)
            player->x = global_int()[0];
    }
    write(player->fd, "ok\n", 3);
}

void watch_inventory(player_t player, __attribute__((unused)) pos_t map, __attribute__((unused)) char *message)
{
    write(player->fd, "[", 1);
    send_ressources_of_player(player);
    write(player->fd, "]", 1);
    write(player->fd, "\n", 1);
}

void fork_a_player(player_t player, pos_t map, __attribute__((unused)) char *message)
{
    player_t egg = new_player();

    map = square_from_coord(map, player->x, player->y);
    add_player_to_square_during_game(map, egg);
    egg->x = player->x;
    egg->y = player->y;
    egg->next = player->next;
    player->next = egg;
    write(player->fd, "ok\n", 3);

}

void force_move(player_t player, pos_t map, direction_t direction)
{
    map = square_from_coord(map, player->x, player->y);
    if (direction == TOP) {
        move_player(player, map, map->top);
        player->y = player->y + 1 % global_int()[1];
    }
    if (direction == RIGHT) {
        move_player(player, map, map->right);
        player->x = player->x + 1 % global_int()[0];
    }
    if (direction == BOTTOM) {
        move_player(player, map, map->bottom);
        player->y - 1;
        if (player->y < 0)
            player->y = player->y = global_int()[1];
    }
    if (direction == LEFT) {
        move_player(player, map, map->left);
        player->x = player->x - 1;
        if (player->x < 0)
            player->x = player->x = global_int()[0];
    }
}

void violation_of_peace(pos_t map, player_on_square_t *list_of_player, player_t reference)
{
    while (list_of_player) {
        if (list_of_player->player != reference)
            force_move(list_of_player->player, map, reference->direction);
        list_of_player = list_of_player->next;
    }
}

void eject_players(player_t player, pos_t map,  __attribute__((unused)) char *message)
{
    violation_of_peace(map, map->player, player);
    write(player->fd, "ok\n", 3);
}

void take_object(player_t player, pos_t map, char *obj)
{
    map = square_from_coord(map, player->x, player->y);
    player->ressources[obj[0]] += 1;
    map->elem[obj[0]] -= 1;
    write(player->fd, "ok\n", 3);
}

void drop_object(player_t player, pos_t map, char *obj)
{
    map = square_from_coord(map, player->x, player->y);
    player->ressources[obj[0]] -= 1;
    map->elem[obj[0]] += 1;
    write(player->fd, "ok\n", 3);
}

void elevation(player_t player, pos_t map, __attribute__((unused)) char *message)
{
    map = square_from_coord(map, player->x, player->y);
    function_evolution[player->level - 1](player, map);
}

void send_message_to_every_one(player_on_square_t *list, char *message)
{
    while (list) {
        if (list->player->fd != -1) {
            write(list->player->fd, message, strlen(message));
            write(list->player->fd, "\n", 1);
        }
        list = list->next;
    }
}

void broadcast(player_t player, pos_t map, char *message)
{
    int a = 3;

    map = square_from_coord(map, player->x, player->y);
    for (int x = 0; x != global_int()[0] / 2; ++x) {
        map = map->top;
        map = map->left;
        for (int i = 0; i != a; i++) {
            send_message_to_every_one(map->player, message);
            map = map->right;
        }
        map = map->left;
        for (int i = 0; i != a - 1; i++) {
            map = map->bottom;
            send_message_to_every_one(map->player, message);
        }
        for (int i = 0; i != a - 1; i++) {
            map = map->left;
            send_message_to_every_one(map->player, message);
        }
        for (int i = 0; i != a - 2; i++) {
            map = map->top;
            send_message_to_every_one(map->player, message);
        }
        map = map->top;
    }
    write(player->fd, "ok\n", 3);
}