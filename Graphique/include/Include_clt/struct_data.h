/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myteams-clovis.gilles [WSL: Ubuntu-20.04]
** File description:
** struct_data
*/

#ifndef STRUCT_DATA_H_
#define STRUCT_DATA_H_

struct global_data {
    int sock;
    int user_id;
    int x;
    int y;
    char *ip_char;
    char *port_char;
};
typedef struct global_data global_data_t;
global_data_t *constructor_data(char *port_arg);
int destructor_data(global_data_t *data);
#endif /* !STRUCT_DATA_H_ */