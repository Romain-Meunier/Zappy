/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** evolution
*/

#include "../include/action.h"

void to_level_two(player_t player, pos_t map)
{
    if (len_of_list(map->player) <= 1) {
        KO;
        return;
    }
    if (player->ressources[1] >= 1)
        player->level++;
}

void to_level_three(player_t player, pos_t map)
{
    if (len_of_list(map->player) <= 2) {
        KO;
        return;
    }
    if (player->ressources[1] < 1) {
        KO;
        return;
    }
    if (player->ressources[2] < 1) {
        KO;
        return;
    }
    if (player->ressources[3] < 1) {
        KO;
        return;
    }
    player->level++;
}

void to_level_four(player_t player, pos_t map)
{
    if (len_of_list(map->player) <= 2) {
        KO;
        return;
    }
    if (player->ressources[1] < 2) {
        KO;
        return;
    }
    if (player->ressources[3] < 1) {
        KO;
        return;
    }
    if (player->ressources[5] < 2) {
        KO;
        return;
    }
    player->level++;
}

void to_level_five(player_t player, pos_t map)
{
    if (len_of_list(map->player) <= 4) {
        KO;
        return;
    }
    if (player->ressources[1] < 1) {
        KO;
        return;
    }
    if (player->ressources[2] < 1) {
        KO;
        return;
    }
    if (player->ressources[3] < 2) {
        KO;
        return;
    }
    if (player->ressources[5] < 1) {
        KO;
        return;
    }
    player->level++;
}

void to_level_six(player_t player, pos_t map)
{
    if (len_of_list(map->player) <= 4) {
        KO;
        return;
    }
    if (player->ressources[1] < 1) {
        KO;
        return;
    }
    if (player->ressources[2] < 2) {
        KO;
        return;
    }
    if (player->ressources[3] < 1) {
        KO;
        return;
    }
    if (player->ressources[4] < 3) {
        KO;
        return;
    }
    player->level++;
}

void to_level_seven(player_t player, pos_t map)
{
    if (len_of_list(map->player) <= 6) {
        KO;
        return;
    }
    if (player->ressources[1] < 1) {
        KO;
        return;
    }
    if (player->ressources[2] < 2) {
        KO;
        return;
    }
    if (player->ressources[3] < 3) {
        KO;
        return;
    }
    if (player->ressources[5] < 1) {
        KO;
        return;
    }
    player->level++;
}

void to_level_height(player_t player, pos_t map)
{
    if (len_of_list(map->player) <= 6) {
        KO;
        return;
    }
    if (player->ressources[1] < 2) {
        KO;
        return;
    }
    if (player->ressources[2] < 2) {
        KO;
        return;
    }
    if (player->ressources[3] < 2) {
        KO;
        return;
    }
    if (player->ressources[4] < 2) {
        KO;
        return;
    }
    if (player->ressources[5] < 2) {
        KO;
        return;
    }
    if (player->ressources[6] < 1) {
        KO;
        return;
    }
    player->level++;
}