/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-florent.brassart
** File description:
** command
*/

#include "../include/comand_list.h"
#include "../include/proto.h"
#include <string.h>
#include <unistd.h>

int conection_to_player(int fd, char **agrs, args_data_t *s_sdata)
{
    if (agrs[0][strlen(agrs[0]) - 1] == '\n')
        agrs[0][strlen(agrs[0]) - 1] = '\0';
    char carn[1] = "\n";
    char cars[1] = " ";
    player_t ptmp = give_fd_to_player((*s_sdata)->_teams_list, fd, agrs[0]);

    if (!ptmp)
    {
        return (1);
    }
    char *ctmp = malloc(sizeof(ptmp->uuid) + 8);

    if (!ctmp) {
        write(2, "error malloc\n", strlen("error malloc\n"));
        write(fd, "error malloc, server shutdown\n", strlen("error malloc, server shutdown\n"));
        exit(84);
    }
    // strcat(ctmp, ptmp->uuid);
    // strcat(ctmp, carn);
    write(fd, ptmp->uuid, 16);
    write(fd, "\n", 1);
    free(ctmp);
    ctmp = malloc(strlen(int_to_string(ptmp->x)) + strlen(int_to_string(ptmp->y)) + 2);
    if (!ctmp) {
        write(2, "error malloc\n", strlen("error malloc\n"));
        write(fd, "error malloc, server shutdown\n", strlen("error malloc, server shutdown\n"));
        exit(84);
    }

    strcat(ctmp, int_to_string(ptmp->x));
    strcat(ctmp, cars);
    strcat(ctmp, int_to_string(ptmp->y));
    strcat(ctmp, carn);
    write(fd, ctmp, strlen(ctmp));
    free(ctmp);
    return (0);
}

int comand_gestion(int fd, char **agrs, args_data_t *s_sdata)
{
    char **array = (char **)func;

    POINTER **list = func_list;
    int i = 0;
    char snum[6];

    if (conection_to_player(fd, agrs, s_sdata) == 0)
        return (0);
    if (!find_playe_from_fd((*s_sdata)->_teams_list, fd)) {
        if (strcmp(agrs[0], "mtc\n") == 0 || strcmp(agrs[0], "mtc") == 0) {
            char *stock = parser_map((*s_sdata)->_map, (*s_sdata)->_width, (*s_sdata)->_height);
            write(fd, stock, strlen(stock));
            free(stock);
        } else {
            if (strcmp(agrs[0], "msz\n") == 0 || strcmp(agrs[0], "msz") == 0) {
                write(1, "msz ", strlen("msz "));
                char *stockx = int_to_string((*s_sdata)->_width);
                char *stocky = int_to_string((*s_sdata)->_height);

                write(fd, stockx, strlen(stockx));
                write(fd, stocky, strlen(stocky));
                free(stockx);
                free(stocky);
            }
        }
        return (0);
    } else
        which_command(fd, agrs, s_sdata);
    //list[i](agrs, fd, log);

    return (0);
}