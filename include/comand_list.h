/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-florent.brassart
** File description:
** comand_list
*/

#ifndef COMAND_LIST_H_
#define COMAND_LIST_H_

#include <stddef.h>
typedef int POINTER(char**, int, int*);

POINTER user;
POINTER pass;
POINTER cwd;
POINTER cdup;
POINTER quit;
POINTER dele;
POINTER pwd;
POINTER pasv;
POINTER port;
POINTER help;
POINTER noop;
POINTER retr;
POINTER stor;
POINTER list;
POINTER nothing;

static const char *func[] = {
    "USER",
    "PASS",
    "CWD",
    "CDUP",
    "QUIT",
    "DELE",
    "PWD",
    "PASV",
    "PORT",
    "HELP",
    "NOOP",
    "RETR",
    "STOR",
    "LIST",
    NULL
};

static POINTER *func_list[] = {
    &user,
    &pass,
    &cwd,
    &cdup,
    &quit,
    &dele,
    &pwd,
    &pasv,
    &port,
    &help,
    &noop,
    &retr,
    &stor,
    &list,
    &nothing
};

#endif /* !COMAND_LIST_H_ */
