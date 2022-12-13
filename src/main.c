/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-florent.brassart
** File description:
** test_multi
*/

#include "../include/proto.h"

int main(int ac , char **av)
{
    struct socket_data *s_sdata = malloc(sizeof(struct socket_data));
    s_sdata->_s_adata = malloc(sizeof(struct args_data));

    if (!s_sdata) return (84);
    if (!s_sdata->_s_adata) return (84);
    check_args(ac, av, &s_sdata->_s_adata);
    s_sdata->_port = s_sdata->_s_adata->_port;
    s_sdata->_s_adata->_map = create_map(s_sdata->_s_adata->_width,\
    s_sdata->_s_adata->_height);
    s_sdata->_s_adata->_teams_list = create_all_teams(s_sdata->_s_adata, s_sdata->_s_adata->_map);
    set_player_on_map(s_sdata->_s_adata->_map,\
    s_sdata->_s_adata->_teams_list);
    socket_management(&s_sdata);
    delete_map(s_sdata->_s_adata->_map, s_sdata->_s_adata->_width,\
    s_sdata->_s_adata->_height);
    return 0;
}
