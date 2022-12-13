/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** protocol_cmd.c
*/

#include <unistd.h>
#include "../include/proto.h"
#include <string.h>
#include <stdio.h>
#include "../server/include/player.h"

void reply(int fd, const char* message)
{
    write(fd, message, strlen(message));
}

int error_cmd(args_data_t* data, player_t* player, char *cmd)
{
    reply((*player)->fd, "ko\n");
}

int map_size(int fd, char **agrs, args_data_t *s_sdata)
{
    char breply[4096];
    char *snum = malloc(100);

    write(1, "mer\n", 2);

    breply[0] = 0;

    write(1, "3\n", 2);

    sprintf(snum, "%d", (*s_sdata)->_height);

    write(1, "4\n", 2);
    strcat(breply, "msz ");
    write(1, "5\n", 2);
    strcat(breply, snum);

    write(1, "6\n", 2);
    free(snum);
    snum = malloc(100);
    sprintf(snum, "%d", (*s_sdata)->_width);

    write(1, "7\n", 2);
    strcat(breply, snum);
    free(snum);
    write(1, "8\n", 2);
    write(1, "R\n", 2);
    reply(fd, breply);
    write(1, "9\n", 2);
    return (0);
}

/*int content_of_a_tile(args_data_t *data, player_t * player, char *cmd)
{
    char *reply = NULL;
    char **res = parse_string_delim(cmd, " \n");

    if (res[0] && res[1] && res[2])
        reply = ;
}*/

int name_of_all_the_teams(args_data_t* data, player_t* player, char* cmd)
{
    char breply[4096];

    breply[0] = 0;
    for (int i = 0; (*data)->_teams_names[i] != NULL; i++) {
        strcat(breply, "tna ");
        strcat(breply, (*data)->_teams_names[i]);
        strcat(breply, "\n");
    }
    reply((*player)->fd, breply);
    return EXIT_SUCCESS;
}