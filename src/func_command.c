/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-florent.brassart
** File description:
** func_command
*/

#include <unistd.h>
#include "../include/comand_list.h"
#include <string.h>
#include <stdio.h>
int user(char **args, int fd, int *user)
{
    write(fd, "331\n", 4);
    if (strcmp(args[1], "Anonymous"))
        *user = -1;
    else
        *user = 1;
    //printf("%d, %s\n", *user, args[1]);
    return(0);
}

int pass(char **args, int fd, int *user)
{
    if (*user != 1 || args[1])
        write(fd, "530\n", 4);
    else {
        write(fd, "230\n", 4);
        *user = 2;
    }
    //printf("%d\n", *user);
    return(0);
}

int cwd(char **args, int fd, int *user)
{
    if (*++args && chdir(*args))
        write(fd, "xxx\n", 4);
    else 
        write(fd, "250\n", 4);
    return(0);
}

int cdup(char **args, int fd, int *user)
{
    if (chdir(".."))
        write(fd, "xxx\n", 4);
    else 
        write(fd, "200\n", 4);
    return(0);
}

int quit(char **args, int fd, int *user)
{
    if (*user == 2) {
        write(fd, "221\n", 4);
        *user = 0;
    } else
        write(fd, "xxx\n", 4);
    //printf("%d\n", *user);
    return(0);
}

int dele(char **args, int fd, int *user)
{
    write(fd, "xxx\n", 4);
    return(0);
}

int pwd(char **args, int fd, int *user)
{
    write(fd, "530\n", 4);
    return(0);
}

int pasv(char **args, int fd, int *user)
{
    write(fd, "xxx\n", 4);
    return(0);
}

int port(char **args, int fd, int *user)
{
    write(fd, "xxx\n", 4);
    return(0);
}

int help(char **args, int fd, int *user)
{
    char **list_function = (char**)func;
    write(fd, "214\n", 4);
    for (; list_function++; write(fd, "\n", 1))
        write(fd, *list_function, strlen(*list_function));
    return(0);
}

int noop(char **args, int fd, int *user)
{
    write(fd, "200\n", 4);
    return(0);
}

int retr(char **args, int fd, int *user)
{
    write(fd, "xxx\n", 4);
    return(0);
}

int stor(char **args, int fd, int *user)
{
    write(fd, "xxx\n", 4);
    return(0);
}

int list(char **args, int fd, int *user)
{
    write(fd, "xxx\n", 4);
    return(0);
}

int nothing(char **args, int fd, int *user)
{
    write(fd, "xxx\n", 4);
    return(0);
}