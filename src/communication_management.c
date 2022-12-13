/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier [WSL: Ubuntu-20.04]
** File description:
** communication_management
*/
#include "../include/proto.h"

int socket_preparation(socket_data_t *data, int fd_socket, SOCKST *serv)
{
    for (int index = 0; index < MAX_CLIENT; index++)
        (*data)->_list_socket[index] = 0;
    if (fd_socket <= 0) return (-1);
    serv->sin_family = AF_INET;
    serv->sin_addr.s_addr = htonl(INADDR_ANY);
    serv->sin_port = htons((*data)->_port);
    if (bind(fd_socket, (struct sockaddr *)serv, sizeof(*serv)) != 0) {
        close(fd_socket);
        return (-1);
    }
    listen(fd_socket, MAX_CLIENT);
    return (fd_socket);
}

int select_preparation(socket_data_t *data, int fd_socket, int *max_sd)
{
    int sd = 0;

    FD_ZERO(&(*data)->_readfds);
    FD_SET(fd_socket, &(*data)->_readfds);
    max_sd[0] = fd_socket;
    for (int index = 0; index < MAX_CLIENT; index++)
    {
        sd = (*data)->_list_socket[index];
        if(sd > 0) {
            FD_SET(sd, &(*data)->_readfds);
        }
        if(sd > max_sd[0]) {
            max_sd[0] = sd;
        }
    }
    return (0);
}

int communication(SOCKST *clie, socket_data_t *data, int fd_socket)
{
    (*data)->_size_clt = sizeof(clie);
    int max_sd;

    while (1)
    {
        select_preparation(data, fd_socket, &max_sd);
        if (select(max_sd + 1, &(*data)->_readfds, NULL, NULL, NULL) < 0) {
            write(2, "Error during select\n", 20);
            return (84);
        }
        if (communication_management(data, fd_socket, clie) == 84) {
            return (84);
        }
    }
    return (0);
}

int socket_management(socket_data_t *data)
{
    SOCKST serv;
    int fd_socket;

    fd_socket = socket_preparation(data,\
    socket(AF_INET, SOCK_STREAM, 0), &serv);
    if (fd_socket < 0) exit(84);
    return (communication(&serv, data, fd_socket));
}