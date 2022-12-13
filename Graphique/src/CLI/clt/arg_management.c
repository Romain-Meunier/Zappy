/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-clovis.gilles [WSL: Ubuntu-20.04]
** File description:
** argGestion
*/
#include "../../Include/Include_clt/proto.h"

void display_help(int canal)
{
    write(canal, "USAGE: ./myteams_cli ip port\n",29);
    write(canal, "\t  ip is the server ip address on which ", 66);
    write(canal, "the server socket listens\n\t  port is the port ", 46);
    write(canal, "number on which the server socket listens\n", 42);
}

int sort_arg_bis(int ac, char **av)
{
    if (ac != 3) {
        write(2, "ERROR: only two arguments are allowed\n", 38);
        display_help(2);
        return (CODE_ERROR);
    } else if (str_is_digit(av[2]) == CODE_ERROR) {
        write(2, "ERROR: PORT is unavailable\n", 27);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

int sort_arg(int ac, char **av)
{
    if (ac <= 1) {
        display_help(2);
        return (CODE_ERROR);
    } else if (strcmp(av[1], "-help") == 0) {
        display_help(1);
        return (CODE_SEC_SUCCESS);
    }
    return (sort_arg_bis(ac, av));
}