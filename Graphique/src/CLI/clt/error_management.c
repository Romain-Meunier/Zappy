/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-clovis.gilles [WSL: Ubuntu-20.04]
** File description:
** error
*/
#include "../../Include/Include_clt/proto.h"

char *arg_between_quotes(char *rsc)
{
    int index_cpy = 0;
    int nb_q = 0;
    int size_cpy = 0;
    char *target;

    for (int index = 0; rsc[index] != '\0'; index++) {
        if (rsc[index] == '\"') nb_q++;
        if (nb_q == 1) size_cpy++;
    }
    if (nb_q != 2) return (NULL);
    target = malloc(sizeof(char) * (size_cpy));
    if (!target) return (NULL);
    for (int index = 0, nb_q = 0; rsc[index] != '\0'; index++) {
        if (rsc[index - 1] == '\"') nb_q++;
        if (nb_q == 1) {
            target[index_cpy] = rsc[index];
            index_cpy++;
        }
    }
    target[size_cpy - 1] = '\0';
    return (target);
}

int str_is_digit(char *str)
{
    for(int comp = 0; str[comp] != '\0'; comp++) {
        if (str[comp] < 48 || str[comp] > 57) {
            return (CODE_ERROR);
        }
    }
    return (CODE_SUCCESS);
}

char *mess_cat(char *base_message, int number)
{    
    char tmp_id[2] = "";
    char *msg;

    msg = malloc(sizeof(char) * (strlen(base_message) + strlen(tmp_id) + 1));
    if (!msg) return ("84 ERROR");
    sprintf(tmp_id, "%d", number);
    strcpy(msg, base_message);
    strcat(msg, tmp_id);
    return (msg);
}