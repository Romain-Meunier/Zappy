/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier [WSL: Ubuntu-20.04]
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_
#include "../server/include/map.h"
#define SOCKST struct sockaddr_in
#define MAX_CLIENT 42

struct args_data
{
    int _port;
    int _width;
    int _height;
    int _client_nb;
    int _freq;
    int _check_teams_names;
    char **_teams_names;
    team_t _teams_list;
    pos_t _map;
};
typedef struct args_data *args_data_t;

struct socket_data {
    int _port;
    int _list_socket[MAX_CLIENT];
    socklen_t _size_clt;
    fd_set _readfds;
    args_data_t _s_adata;
};
typedef struct socket_data *socket_data_t;


#endif /* !STRUCT_H_ */