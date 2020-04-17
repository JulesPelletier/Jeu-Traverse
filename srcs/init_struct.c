#include "../includes/lib_func.h"

void    init_rules(t_rules *rules)
{
    rules->mode = 0;
    rules->name_player = NULL;
    rules->number_players = 0;
}

void    configure_struct_1(t_pawns *player)
{
    player->posi_K1 = 0;
    player->posj_K1 = 1;
    player->posi_T1 = 0;
    player->posj_T1 = 2;
    player->posi_L1 = 0;
    player->posj_L1 = 3;
    player->posi_C1 = 0;
    player->posj_C1 = 4;
    player->posi_C2 = 0;
    player->posj_C2 = 5;
    player->posi_L2 = 0;
    player->posj_L2 = 6;
    player->posi_T2 = 0;
    player->posj_T2 = 7;
    player->posi_K2 = 0;
    player->posj_K2 = 8;
    player->player_number = 1;
    player->player_won = 0;
    player->player_played = 0;
}

void    configure_struct_2(t_pawns *player)
{
    player->posi_K1 = 9;
    player->posj_K1 = 1;
    player->posi_T1 = 9;
    player->posj_T1 = 2;
    player->posi_L1 = 9;
    player->posj_L1 = 3;
    player->posi_C1 = 9;
    player->posj_C1 = 4;
    player->posi_C2 = 9;
    player->posj_C2 = 5;
    player->posi_L2 = 9;
    player->posj_L2 = 6;
    player->posi_T2 = 9;
    player->posj_T2 = 7;
    player->posi_K2 = 9;
    player->posj_K2 = 8;
    player->player_number = 2;
    player->player_won = 0;
    player->player_played = 0;
}