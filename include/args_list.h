/*
** EPITECH PROJECT, 2021
** B-YEP-410-MAR-4-1-zappy-romain1.meunier [WSL: Ubuntu-20.04]
** File description:
** args_list
*/

#ifndef ARGS_LIST_H_
#define ARGS_LIST_H_
#include <stddef.h>
#include "struct.h"

typedef int POINT_FUNC(int, int, char **, args_data_t *);
#define NB_ARGS 6

POINT_FUNC p_w_h_cnb_parser;
POINT_FUNC name_parser;
POINT_FUNC freq_parser;

static const char *args_list[] = {
    "-p",
    "-x",
    "-y",
    "-n",
    "-c",
    "-f",
    NULL
};

static POINT_FUNC *args_func_list[] = {
    &p_w_h_cnb_parser,
    &p_w_h_cnb_parser,
    &p_w_h_cnb_parser,
    &name_parser,
    &p_w_h_cnb_parser,
    &freq_parser,

};
#endif /* !ARGS_LIST_H_ */