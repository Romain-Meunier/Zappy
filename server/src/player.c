/*
** EPITECH PROJECT, 2021
** server
** File description:
** player
*/

//#include "../include/palyer.h"
#include "../include/map.h"

team_t new_team(void)
{
    team_t new = malloc(sizeof(list_of_team_t));

    new->next = NULL;
    new->players = NULL;
    new->teams_name = NULL;
    return (new);
}

player_t new_player(void)
{
    player_t new = malloc(sizeof(list_player_t));

    new->next = NULL;
    for (int i = 0; i != RESSOURCES_NB; ++i)
        new->ressources[i] = 0;
    new->direction = TOP;
    uuid_generate(new->uuid);
    new->fd = -1;
    new->x = 0;
    new->y = 0;
    new->level= 1;
    new->is_taken = 0;
    return (new);
}

team_t create_new_team(int width, int heigh, int client_number, char *team_name)
{
    team_t team = new_team();
    player_t player = NULL;

    team->teams_name = team_name;
    for (int i = 0; i != client_number; ++i) {
        player = new_player();
        player->next = team->players;
        player->x = rand() % width;
        player->y = rand() % heigh;
        team->players = player;
    }
    return (team);
}

player_on_square_t *new_player_on_square(void)
{
    player_on_square_t *new = malloc(sizeof(player_on_square_t));

    new->next = NULL;
    new->player = NULL;
    return (new);
}

void add_player_to_square_during_game(pos_t map, player_t player)
{
    player_on_square_t *new = new_player_on_square();

    new->player = player;
    new->next = map->player;
    map->player = new;
}

void add_player_to_square(pos_t map, player_t player)
{
    player_on_square_t *new = new_player_on_square();

    map = square_from_coord(map, player->x, player->y);
    new->player = player;
    new->next = map->player;
    map->player = new;
}

void set_player_on_map(pos_t map, team_t teams)
{
    while (teams) {
        player_t keep = teams->players;
        while (teams->players) {
            add_player_to_square(map, teams->players);
            teams->players = teams->players->next;
        }
        teams->players = keep;
        teams = teams->next;
    }
}

team_t create_all_teams(args_data_t data, pos_t map)
{
    team_t new = NULL;
    team_t tmp = NULL;

    for (int i = 0; data->_teams_names[i]; ++i) {
        tmp = new;
        new = create_new_team(data->_width, data->_height, data->_client_nb, data->_teams_names[i]);
        new->next = tmp;
    }
    return (new);
}

player_t find_playe_from_fd(team_t teams, int fd)
{
    while (teams) {
        player_t keep = teams->players;
        while (teams->players) {
            if(teams->players->fd == fd) {
                teams->players = keep;
                return (teams->players);
            }
            teams->players = teams->players->next;
        }
        teams->players = keep;
        teams = teams->next;
    }
    return (NULL);
}

player_t first_player_with_no_fd(player_t players, int fd)
{
    while (players) {
        if (players->fd == -1) {
            players->fd = fd;
            return (players);
        }
        players = players->next;
    }
    return (NULL);
}

player_t give_fd_to_player(team_t teams, int fd, char *name)
{
    while (teams) {
        if (!strcmp(teams->teams_name, name))
            return (first_player_with_no_fd(teams->players, fd));
        teams = teams->next;
    }
    return (NULL);
}

void reset_fd_to_player(team_t teams, int fd)
{
    while (teams) {
        player_t keep = teams->players;
        while (teams->players) {
            if (teams->players->fd == fd) {
                teams->players = keep;
                teams->players->fd = -1;
                return;
            }
            teams->players = teams->players->next;
        }
        teams->players = keep;
        teams = teams->next;
    }
}

void delete_players(player_t player)
{
    player_t to_del;

    while (player) {
        to_del = player;
        free(to_del);
        player = player->next;
    }
}

void delete_teams(team_t teams)
{
    team_t to_del;

    while (teams) {
        to_del = teams;
        delete_players(to_del->players);
        free(to_del);
        teams = teams->next;
    }
}