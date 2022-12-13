/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-clovis.gilles [WSL: Ubuntu-20.04]
** File description:
** str_to_word_array
*/
#include "../../Include/Include_clt/proto.h"

int count_line(char *str, char separ, int index)
{
    int comp = 0;

    for (; str[index] != '\0' && str[index] != separ; index++, comp++);
    return (comp);
}

int count_separ(char *str, char separ)
{
    int comp = 1;

    for(int index = 0; str[index] != '\0'; index++)
    {
        if (str[index] == separ) {
           comp++;
        }
    }
    return (comp);
}

char **str_to_word_array(char *str, char sep)
{
    int nb_separ = count_separ(str, sep);
    char **array = (char **)malloc(sizeof(char *) * (nb_separ + 1));
    int index_line;
    int index = 0;
    int index_array;

    if (nb_separ < 1) return (NULL);
    if (!array) return (NULL);
    for (index_array = 0; index_array < nb_separ; index_array++) {
        array[index_array] = (char *)malloc(sizeof(char) *\
        (count_line(str, sep, index) + 1));
        if (!array[index_array]) return (NULL);
        index_line = 0;
        for(; str[index] != sep && str[index] != '\0'; index_line++, index++)
            array[index_array][index_line] = str[index];
        array[index_array][index_line] = '\0';
        index++;
    }
    array[index_array] = NULL;
    return (array);
}