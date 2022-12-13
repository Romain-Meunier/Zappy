/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** communication_ia
*/

#include "../include/communication.h"
#include <stdio.h>
#include <unistd.h>

int which_command(int fd, char **buff, args_data_t *data)
{
    player_t player = find_playe_from_fd((*data)->_teams_list, fd);
    int i = 0;

    if (!*buff) {
        reset_fd_to_player((*data)->_teams_list, fd);
        close(fd);
        return (0);
    }
    for (i = 0; com_ia[i] && strcmp(com_ia[i], buff[0]); ++i);
    command_ai[i](player, (*data)->_map, buff[1]);
    return (0);
}
