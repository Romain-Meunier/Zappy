/*
** EPITECH PROJECT, 2021
** server
** File description:
** palyer
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <uuid/uuid.h>
#include <string.h>
#include "ressource.h"
#include <stdlib.h>
// #include "../../include/struct.h"
typedef struct square_s square_t, *pos_t;

typedef enum {
    TOP,
    RIGHT,
    BOTTOM,
    LEFT
}direction_t;

typedef struct list_player_s {
    struct list_player_s *next;
    int ressources[RESSOURCES_NB];
    direction_t direction;
    uuid_t uuid;
    int fd;
    int x;
    int y;
    int level;
    int is_taken;
}list_player_t, *player_t;

typedef struct team_s {
    struct team_s *next;
    player_t players;
    char *teams_name;
}list_of_team_t, *team_t;

typedef struct all_player_s
{
    struct all_player_s *next;
    player_t player;
}all_player_t;

#ifndef STRUCT_H_
struct args_data
{
    int _port;
    int _width;
    int _height;
    int _client_nb;
    int _freq;
    int _check_teams_names;
    char **_teams_names;
    team_t _teams_list;
    pos_t _map;
};
#endif

typedef struct args_data *args_data_t;
void add_player_to_square(pos_t map, player_t player);
void add_player_to_square_during_game(pos_t map, player_t player);


player_t new_player(void);

/**
** @brief delete all the teams
** 
** @param teams list of all the teams
**/
void delete_teams(team_t teams);

/**
** @brief remouve the fd to a player if  plyer was disconected
** 
** @param teams will find fd in the team
** @param fd the file descriptor to search
**/
void reset_fd_to_player(team_t teams, int fd);

/**
** @brief remouve th
** 
** @param the_teams list of teams
** @param fd the file descriptor to the client
** @param name name of the player wich will recive client
**/
player_t give_fd_to_player(team_t teams, int fd, char *name);

/**
** @brief find client from file descriptor
** 
** @param the_teams list of teams
** @param fd the file descriptor to the client
**/
player_t find_playe_from_fd(team_t teams, int fd);

/**
** @brief will create all the teams
** 
** @param data_structure structure with all element from server
** @param map map to set player on it
**/
team_t create_all_teams(args_data_t data, pos_t map);

/**
** @brief will put all player in the corect place in the map
** 
** @param map the map
** @param teams list of teams
**/
void set_player_on_map(pos_t map, team_t teams);

#endif /* !PLYAER_H_ */