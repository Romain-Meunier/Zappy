/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier [WSL: Ubuntu-20.04]
** File description:
** interact_management
*/
#include "../include/proto.h"

void new_connection(socket_data_t *data, int fd_socket, SOCKST *clie)
{
    if (FD_ISSET(fd_socket, &(*data)->_readfds)) {
        int new_socket = accept(fd_socket, (struct sockaddr *)clie,\
        (socklen_t *)&(*data)->_size_clt);
    
        if (new_socket < 0) exit(84);
        for (int index = 0; index < MAX_CLIENT; index++)
        {
            if((*data)->_list_socket[index] == 0) {
                (*data)->_list_socket[index] = new_socket;
                send(new_socket, CONNECTION_OK, strlen(CONNECTION_OK), 0);
                break;
            }
        }
    }
}

int communication_management(socket_data_t *data, int fd_socket, SOCKST *clie)
{
    new_connection(data, fd_socket, clie);
    if (incomming_message(data, clie) == 84) {
        write(2, "ERROR, message reception\n", 33);
        return (84);
    }
    return (0);
}