#include "../includes/lib_func.h"

void    map_filled(char **map, t_pawns player)
{
    map[player.posi_C1][player.posj_C1] = 'C';
    map[player.posi_C2][player.posj_C2] = 'C';
    map[player.posi_K1][player.posj_K1] = 'K';
    map[player.posi_K2][player.posj_K2] = 'K';
    map[player.posi_L1][player.posj_L1] = 'L';
    map[player.posi_L2][player.posj_L2] = 'L';
    map[player.posi_T1][player.posj_T1] = 'T';
    map[player.posi_T2][player.posj_T2] = 'T';
}