/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myteams-clovis.gilles [WSL: Ubuntu-20.04]
** File description:
** connection_management
*/
#include "../../Include/Include_clt/proto.h"

int prepare_connection(global_data_t *data, SOCKST *serv_addr)
{
    int sock;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return (-1);
    serv_addr->sin_family = AF_INET;
    serv_addr->sin_port = htons(atoi(data->port_char));
    if(inet_pton(AF_INET, data->ip_char, &serv_addr->sin_addr)<=0) 
        return (-1);
    if (connect(sock, (struct sockaddr *)serv_addr, sizeof(*serv_addr)) < 0)
        return (-1);
    return (sock);
}

int connection_server(global_data_t *data)
{
    int valread;
    char buffer[1024] = {0};

    send(data->sock, "1#CONNECTION\0", strlen("1#CONNECTION\0"), 0);
    valread = read(data->sock, buffer, 1024);
    char **tmp = str_to_word_array(buffer, '#');

    if (strcmp(tmp[0], "2") == 0) {
        write(1, "Connection done\n", 16);
        data->user_id = atoi(tmp[2]);
        return (CODE_SUCCESS);
    } else {
        write(2, "Error during connection\n", 24);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

int read_terminal(global_data_t *data)
{
    char *line = malloc(sizeof(char) * 50);
    size_t len = 0;

    getline(&line, &len, stdin);
    if (first_parsing(data, line) == 1)
        return (1);
    return (CODE_SUCCESS);
}

int socket_management(global_data_t *data)
{
    struct sockaddr_in serv_addr;
    fd_set readfds;
    fd_set writefds;
    
    data->sock = prepare_connection(data, &serv_addr);
    if (data->sock == -1) return (CODE_ERROR);
    if (connection_server(data) == CODE_ERROR) return (CODE_ERROR);
    FD_SET(data->sock, &readfds);
    FD_SET(0, &writefds);
    while (1) {
        select(data->sock + 1, &readfds, &writefds, NULL, NULL);
        if (FD_ISSET(data->sock, &readfds)) {
            printf("Msg incomming by server first\n");
        } else if (FD_ISSET(0, &writefds)) {
            if (read_terminal(data) == 1)
                return (CODE_SUCCESS);
        }
    }
    return (CODE_SUCCESS);
}