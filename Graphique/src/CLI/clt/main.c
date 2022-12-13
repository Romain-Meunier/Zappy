/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myteams-clovis.gilles [WSL: Ubuntu-20.04]
** File description:
** main
*/
#include "../../Include/Include_clt/proto.h"

int main(int ac, char** av)
{
    int arg_status = sort_arg(ac, av);
    global_data_t *data;

    if (arg_status == CODE_ERROR) return (CODE_ERROR);
    else if (arg_status == CODE_SEC_SUCCESS) return (CODE_SUCCESS);
    data = constructor_data(av[1], av[2]);
    if (!data) return (CODE_ERROR);
    socket_management(data);
    destructor_data(data);
    return (CODE_SUCCESS);
}