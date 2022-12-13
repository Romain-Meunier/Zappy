/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myteams-clovis.gilles [WSL: Ubuntu-20.04]
** File description:
** proto
*/

#ifndef PROTO_H_
#define PROTO_H_

#define SOCKST struct sockaddr_in
#define CODE_SUCCESS 0
#define CODE_SEC_SUCCESS 1
#define CODE_ERROR 84

#define REFRESH "mtc\n\0"
#define MSZ "msz\n\0"

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include "struct_data.h"
#include <dlfcn.h>

int str_is_digit(char *str);
int sort_arg(int ac, char **av);
int socket_management(global_data_t *data);
char **str_to_word_array(char *str);
char *arg_between_quotes(char *rsc);
char *mess_cat(char *base_message, int number);
void first_parsing(global_data_t *data);
#endif /* !PROTO_H_ */