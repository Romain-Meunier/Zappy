/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier [WSL: Ubuntu-20.04]
** File description:
** parser_management
*/
#include "../include/proto.h"
#include "../include/args_list.h"

int find_args(int index, char **av, args_data_t *data)
{
    for (int index_array = 0; NB_ARGS > index_array; index_array++) {
        if (strcmp(av[index], args_list[index_array]) == 0) {
            int itmp = args_func_list[index_array](index_array, index, av, data);

            if (itmp == -1)
                break;
            else
                return (itmp);
        }
    }
    write(2, "Error some arguments don't exist\n", 33);
    exit(84);
}

void first_parsing(int ac, char **av, args_data_t *data)
{
    for (int index = 1; index < ac; index++) {
        if (av[index][0] == '-')
            index = find_args(index, av, data);
        else {
            write(2, "Error bad usage\n", 16);
            displayHelp(2);
            exit(84);
        }
    }
}