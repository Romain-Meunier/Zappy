/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier [WSL: Ubuntu-20.04]
** File description:
** proto
*/

#ifndef PROTO_H_
#define PROTO_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
/* Struct */
#include "struct.h"

/* Define messages */
#include "msg.h"

/* FUnctions gameplay */
#include "../server/include/map.h"

/* Errors management */
void check_args(int ac, char **av, args_data_t* data);
void displayHelp(int canal);
int str_is_digit(char *str);

/* Parser mangement */
void first_parsing(int ac, char **av, args_data_t *data);

/* Communication_management */
int socket_management(socket_data_t *data);
int incomming_message(socket_data_t *data, SOCKST *clie);

/* Interact_management */
int communication_management(socket_data_t *data, int fd_socket, SOCKST *clie);

void bind_and_listen(int *master, struct sockaddr_in *address);
void loop(int master, struct sockaddr_in info, int **client, int**);
void set_master(int *master);
void accept_new(int **client, int master, struct sockaddr_in info);
void read_incoming(int **client, fd_set *readfds, int**);
char **str_to_word_array(char *str);
int comand_gestion(int fd, char **agrs, args_data_t *s_sdata);

/*rodrigue proto*/
void reply(int fd, const char* message);
char *int_to_string(int nb);
char** parse_string_delim(const char *str, const char *del);
static int count_space(const char *str);
int map_size(int fd, char **agrs, args_data_t *s_sdata);

/* florent add*/
int which_command(int fd, char **buff, args_data_t *data);

#endif /* !PROTO_H_ */