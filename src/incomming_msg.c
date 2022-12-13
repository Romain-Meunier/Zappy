/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier [WSL: Ubuntu-20.04]
** File description:
** incomming_msg
*/
#include "../include/proto.h"

int user_deconnection(socket_data_t *data, int sd, int index, SOCKST *clie)
{
    int (*funcp)(char const *);

    getpeername(sd, (struct sockaddr*)&clie, (socklen_t*)&(*data)->_size_clt);
    player_t ptmp = find_playe_from_fd((*data)->_s_adata->_teams_list, sd);

    ptmp->fd = -1;
    close(sd);
    (*data)->_list_socket[index] = 0;
    return (0);
}

int message_reception(socket_data_t *data, int sd, char *msg, int index)
{
    msg[strlen(msg)] = '\0';
	comand_gestion(sd, str_to_word_array(msg), &(*data)->_s_adata);
    return (0);
}

int in_message_management(socket_data_t *data, SOCKST *clie, int index, int sd)
{
    int valread;
    char buffer[30];

    if ((valread = read(sd , buffer, 1024)) == 0) {
        user_deconnection(data, sd, index, clie); 
    } else {
        buffer[valread - 1] = '\0';
        if (message_reception(data, sd, buffer, index) == 84)
            return (84);
    }
    return (0);
}

int incomming_message(socket_data_t *data, SOCKST *clie)
{
    int sd = 0;

    for (int index = 0; index < MAX_CLIENT; index++) {
        sd = (*data)->_list_socket[index];
        if (FD_ISSET(sd, &(*data)->_readfds)) {
            if (in_message_management(data, clie, index, sd) == 84) {
                return (84);
            }
        }
    }
    return (0);
}