/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier [WSL: Ubuntu-20.04]
** File description:
** parser_map
*/
#include "../include/map.h"

char *parser_map(pos_t map, int xmap ,int  ymap)
{
    char *result = malloc(sizeof(char) * (xmap * ymap + 2));
    int index = 0;

    if (!result) return (NULL);
    for (int y_index = 0; y_index < ymap; y_index++) {
        for (int x_index = 0; x_index < xmap; x_index++) {
            if (map->player != NULL)
                result[index] = 'P';
            else {
                int tmp = rand() % 7;

                result[index] = (map->elem[tmp] == 0) ? ' ' : ressources_name[tmp][0];
            }
            map = map->right;
            index++;
        }
        map = map->right;
        map = map->top;
    }
    result[index++] = '\n';
    result[index] = '\0';
    return (result);
}