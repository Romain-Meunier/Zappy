/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier [WSL: Ubuntu-20.04]
** File description:
** args_functions
*/
#include "../include/proto.h"
#include "../include/args_list.h"

int p_w_h_cnb_parser(int itmp, int index, char **av, args_data_t *data)
{
    if (av[index + 1] != NULL) {
        if (str_is_digit(av[index + 1]) == 1) return (-1);
        if (atoi(av[index + 1]) == 0) return (-1);
        switch (itmp)
        {
            case 0:
                (*data)->_port = atoi(av[index + 1]);
                break;
            case 1:
                (*data)->_width = atoi(av[index + 1]);
                break;
            case 2:
                (*data)->_height = atoi(av[index + 1]);
                break;
            default:
                (*data)->_client_nb = atoi(av[index + 1]);
                break;
        }
        return (index + 1);
    }
    return (-1);
}

int name_parser(int itmp, int index, char **av, args_data_t *data)
{
    int nb_name = 0;
    int index_arr;
    int index_fill = 0;

    for (index_arr = index + 1; av[index_arr] != NULL; index_arr++) {
        if (av[index_arr][0] == '-') break;
        nb_name++;
    }
    (*data)->_teams_names = malloc(sizeof(char *) * (nb_name + 1));
    if (!(*data)->_teams_names) return (-1);
    for (index_arr = index + 1; av[index_arr] != NULL; index_arr++, index_fill++) {
        if (av[index_arr][0] == '-') break;
        (*data)->_teams_names[index_fill] = av[index_arr];
    }
    (*data)->_teams_names[index_fill] = NULL;
    (*data)->_check_teams_names = 1;
    return (index_arr - 1);
}

int freq_parser(int itmp, int index, char **av, args_data_t *data)
{
    if (av[index + 1] != NULL) {
        if (str_is_digit(av[index + 1]) == 1) return (-1);
        if (atoi(av[index + 1]) == 0) return (-1);
        (*data)->_freq = atoi(av[index + 1]);
        return (index + 1);
    }
    return (-1);
}