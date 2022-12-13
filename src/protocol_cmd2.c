/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** protocol_cmd2.c
*/

#include <unistd.h>
#include "../include/proto.h"
#include <string.h>
#include <stdio.h>
#include "../server/include/player.h"

/*int player_position(args_data_t *data, player_t *player, char *cmd)
{
    char breply[4096];

    breply[0] = 0;
    strcat(breply, "ppo ");
}*/

int time_unit_request(args_data_t *data, player_t *player, char *cmd)
{
    char breply[4096];
    char snum[6];

    breply[0] = 0;
    sprintf(snum, "%d", (*data)->_freq);
    strcat(breply, "sgt ");
    strcat(breply, snum);
    strcat(breply, "\n");
    reply((*player)->fd, breply);
    return EXIT_SUCCESS;
}

int player_info(args_data_t *data, char **args, int fd)
{
    /*if (!args[6])
        return(84);
    if (args[6][strlen(args[6]) - 1] == '\n') {

    }

    player_t give_fd_to_player((*data)._teams_list, fd, name);

    char breply[4096];
    team_t *team;

    breply[0] = 0;
    strcat(breply, "pnw ");
    strcat(breply, int_to_string((*player)->fd));
    strcat(breply, " ");
    strcat(breply, int_to_string((*player)->x));
    strcat(breply, " ");
    strcat(breply, int_to_string((*player)->y));
    strcat(breply, " ");
    strcat(breply, int_to_string((*player)->direction));
    strcat(breply, " ");
    strcat(breply, int_to_string((*player)->level));
    strcat(breply, " ");
    strcat(breply, (*team)->teams_name);
    strcat(breply, "\n");
    reply(fd, breply);*/
    return EXIT_SUCCESS;
}