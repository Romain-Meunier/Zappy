/*
** EPITECH PROJECT, 2020
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** mapzappy.cpp
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <sstream>
#include "../../include/General.hpp"

std::vector<std::string>parse_map(std::string input, int x, int y)
{
    char *str = (char *) malloc(sizeof(char) * 10+1);
    std::vector<std::string> tokens;
    int comp = 0;
    int comp2 = 0;
    int size = input.size();
    int k = 0;
    int i = 0;
    size = size/x;
    while (i < size + 1) {
        str[comp] = input[comp2];
        if (comp == (x - 1)) {
            tokens.push_back(str);
            comp = 0;
            i = i + 1;

        }
        comp++;
        comp2++;
    }
    return (tokens);
}

/*int main(int ac, char **av)
{
    int i = 0;
    int sto = 0;
    char *str = "        tm f     l  P   d f       l          1011   ff    s fl f         Pp f       l   f  m     P          P l  m";
    char *num = (char *) malloc(sizeof(char) * 4 + 1);
    char *my_x = malloc(3 + 1);
    char *my_y = malloc(3 + 1);

    num = "1011";
    for (i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 48) && (str[i] <= 57))
            //num[sto] == str[i];
            //std::cout << str[i] << std::endl;
            sto = sto + 1;
    }
    my_x[2] = '\0';
    my_y[2] = '\0';
    my_x[0] = num[0];
    my_x[1] = num[1];
    my_y[0] = num[2];
    my_y[1] = num[3];

    std::cout << my_x << std::endl << my_y;
}*/