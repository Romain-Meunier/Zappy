/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** protocol_util.c
*/

#include "../include/proto.h"
#include "../server/include/ressource.h"

char *int_to_string(int nb)
{
    char *num = malloc(sizeof(char) * 6);
    int a;
 
    a = sprintf(num, "%d", nb);
    num[a] = '\0';
    printf("%d\n", a);
    return num;
}

static int count_space(const char *str)
{
    char bstr[4096];
    int i = 0;
    char delim[] = " ";
    strcpy(bstr, str);
    char *ptr = strtok(bstr, delim);

    for (; ptr != NULL; ptr = strtok(NULL, delim))
        i++;
    return i;
}

char** parse_string_delim(const char *str, const char *del)
{
    char bstr[4096];
    char delim[4];
    int nb_words = count_space(str);
    char **arr = NULL;
    int i = 0;
    char *ptr;

    strcpy(bstr, str);
    strcpy(delim, del);
    ptr = strtok(bstr, delim);
    arr = malloc(sizeof(char*) * (nb_words + 1));
    for(; ptr != NULL; ptr = strtok(NULL, delim), i++)
        arr[i] = strdup(ptr);
    arr[i]= NULL;
    return arr;
}

char *content_for_one_tile(args_data_t *data, int x, int y)
{
    char *reply = malloc(sizeof(char) * 4096);
}