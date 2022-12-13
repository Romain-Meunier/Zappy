/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** communication
*/

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include "../server/include/action.h"

typedef void COMMAND_AI(player_t, pos_t, char*);

static char *com_ia[] = {
    "Look",
    "Left",
    "Right",
    "Forward",
    "Inventory",
    "Fork",
    "Take_object",
    "Set_object",
    "elevation",
    "broadcast",
    "Eject"
};

static COMMAND_AI *command_ai[] = {
    &look,
    &direction_left,
    &direction_rift,
    &move,
    &watch_inventory,
    &fork_a_player,
    &take_object,
    &drop_object,
    &elevation,
    &broadcast,
    &eject_players
};

#endif /* !COMMUNICATION_H_ */
