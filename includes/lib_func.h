#ifndef _LIB_FUNC_H_
# define _LIB_FUNC_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"


typedef struct  s_pawns
{
    int     posi_K1;
    int     posj_K1;
    int     posi_T1;
    int     posj_T1;
    int     posi_L1;
    int     posj_L1;
    int     posi_C1;
    int     posj_C1;
    int     posi_C2;
    int     posj_C2;
    int     posi_L2;
    int     posj_L2;
    int     posi_T2;
    int     posj_T2;
    int     posi_K2;
    int     posj_K2;
    int     player_number;
    int     player_won;
    int     player_played;
}               t_pawns;

typedef struct  s_rules
{
    int     number_players;
    int     mode;
    char    **name_player;
    int     error;
}               t_rules;


char        **create_map(int taille);
void        affichage_map(char **map);
void        affichage_map_bis(char **map, t_pawns *players);
void        affichage_simple(char **map);
int         is_pawn(char c);
int		    isalpha(int c);
int         move_possible(int x, int y, char **map);
void        map_filled(char **map, t_pawns player);
void        swap(int posi1, int posi2, int posj1, int posj2, char **map);
int         *saut(t_pawns player, int posi1, int posi2, int posj1, int posj2, char **map);

t_pawns     update_pos(t_pawns player, int posi1, int posj1, int posi2, int posj2);

void        init_rules(t_rules *rules);
void        configure_struct_1(t_pawns *player);
void        configure_struct_2(t_pawns *player);

t_rules     check_rules(int ac, char **av);
int         check_rules_params(t_rules rules);
int         check_move(t_pawns player, int posi1, int posj1, int posi2, int posj2, char **map);
int         check_move_IA(t_pawns player, int posi1, int posj1, int posi2, int posj2, char **map);
int         error_pawn(t_pawns player, int posi1);
int         check_arrival(t_pawns player, int posi1, int posi2, int posj1, int posj2, char **map);
int         check_inputs(int posi1, int posi2, int posj1, int posj2);
int         check_starting_pos(int posi1, int posj1, char **map);
int         check_rounds(int compteur, char **map, t_pawns *players);
void        check_victory(t_pawns player);

int         check_IA(t_pawns player, int posi1, int posj1);




#endif