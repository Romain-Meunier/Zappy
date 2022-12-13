/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myteams-clovis.gilles [WSL: Ubuntu-20.04]
** File description:
** parsing_command
*/
#include "../../Include/Include_clt/proto.h"

void free_double(char ***array)
{
    for (int index = 0; *array[index] != NULL; index++)
        free(*array[index]);
    free(*array);
}


int login_management_two(global_data_t *data, char *line, char **tmp)
{
    if (arg_between_quotes(line) == NULL) {
            write(2, "Error, /login \"name\"\n", 21);
            return (CODE_ERROR);
    }
    char buffer[50];
    char *tmp_msg = malloc(sizeof(char) * (strlen("3#LOGIN#") +\
    strlen(arg_between_quotes(line)) + 2));

    strcpy(tmp_msg, "3#LOGIN#");
    if (!tmp_msg) return (CODE_ERROR);
    strcat(tmp_msg, arg_between_quotes(line));
    strcat(tmp_msg, "#");
    send(data->sock, tmp_msg, strlen(tmp_msg), 0);
    free(tmp_msg);
    read(data->sock, buffer, 50);
    data->user_name = malloc(sizeof(char) *\
    strlen(arg_between_quotes(line)) + 1);
    if (!data->user_name) return (CODE_ERROR);
    strcpy(data->user_name, arg_between_quotes(line));
    return (CODE_SUCCESS);
}

int login_management(global_data_t *data, char *line)
{
    char **tmp = str_to_word_array(line, ' ');

    if (!tmp) {
        write(2, "Error, during execution of the command\n", 39);
        return (CODE_ERROR);
    }
    if (strcmp(tmp[0], "/login") == 0 || tmp[1] != NULL) {
        if (login_management_two(data, line, tmp) == CODE_ERROR)
            return (CODE_ERROR);
    } else {
        write(2, "Error, command not found\n", 25);
        return (CODE_ERROR);
    }
}

int first_parsing(global_data_t *data, char *line)
{
    int (*funcp)(char const *, char const *);
    if (strlen(line) == 1) return (CODE_SEC_SUCCESS);
    if (strcmp(line, "/logout\n") == 0) {
        send(data->sock, SENDOUT, strlen(SENDOUT), 0);
        char buffer[50];

        read(data->sock, buffer, 50);
        if (!data->user_name)
            free(data->user_name);
    } else {
        login_management(data, line);
    }
    return (CODE_SUCCESS);
}