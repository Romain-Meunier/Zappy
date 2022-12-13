/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier [WSL: Ubuntu-20.04]
** File description:
** errors_management
*/
#include "../include/proto.h"

int check_args_filled(args_data_t *data)
{
    if ((*data)->_port > 0 && (*data)->_width > 0 &&\
    (*data)->_height > 0) {
        if ((*data)->_client_nb > 0 && (*data)->_freq > 0\
        && (*data)->_check_teams_names != 0) {
            return (0);
        }
    }
    write(2, "There are arguments missing\n", 28);
    exit(84);
}

int str_is_digit(char *str)
{
    for(int comp = 0; str[comp] != '\0'; comp++) {
        if (str[comp] < 48 || str[comp] > 57)
            return (-1);
    }
    return (0);
}

void displayHelp(int canal)
{
    write(canal, "USAGE:\n\t./zappy_server -p port ", 31);
    write(canal, "-x width -y height -n name1 name2", 33);
    write(canal, " ... -c clientsNb -f freq\n\t", 27);
    write(canal, "port\tis the port number\n", 24);
    write(canal, "\twidth\tis the width of the world", 32);
    write(canal, "\n\theight\tis the height", 22);
    write(canal, " of the world\n\tnameX\tis the name ", 33);
    write(canal, "of the team X\n\tclientsNb\t", 25);
    write(canal, "is the number of authorized ", 28);
    write(canal, "clients per team\n\tfreq\t", 23);
    write(canal, "is the reciprocal of time unit ", 31);
    write(canal, "for execution of actions", 24);
}

void check_args(int ac, char **av, args_data_t *data)
{
    if (ac == 2) {
        if (strcmp(av[1], "-help") == 0) {
            displayHelp(1);
            exit(0);
        } else {
            write(2, "Error too less arguments\n", 25);
            displayHelp(2);
            exit(84);
        }
    } else if (ac > 12) {
        (*data)->_check_teams_names = 0;
        first_parsing(ac, av, data);
        check_args_filled(data);
    } else {
        write(2, "Error too less arguments\n", 25);
        displayHelp(2);
        exit(84);
    }
}