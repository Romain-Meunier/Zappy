/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myteams-clovis.gilles [WSL: Ubuntu-20.04]
** File description:
** struct_data
*/
#include "../../Include/Include_clt/proto.h"

global_data_t *constructor_data(char *ip_arg, char *port_arg)
{
    global_data_t *data = malloc(sizeof(global_data_t));

    data->port_char = malloc(sizeof(port_arg) * (strlen(port_arg) + 1));
    if (!data->port_char) return (NULL);
    strcpy(data->port_char, port_arg);
    data->ip_char = malloc(sizeof(ip_arg) * (strlen(ip_arg) + 1));
    if (!data->ip_char) return (NULL);
    strcpy(data->ip_char, ip_arg);
    return (data);
}

int destructor_data(global_data_t *data)
{
    free(data->port_char);
    free(data->ip_char);
    free(data);
    return (0);
}