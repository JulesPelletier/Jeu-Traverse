#include "../includes/lib_func.h"

void    check_victory(t_pawns player)
{
    if (player.player_number == 1)
    {
        if ((player.posi_C1 == 9 && player.posi_C2 == 9 && player.posi_K1 == 9 
            && player.posi_K2 == 9 && player.posi_L1 == 9 && player.posi_L2 == 9
            && player.posi_T1 == 9 && player.posi_T2 == 9)
            && (player.posj_C1 != 0 && player.posj_C1 != 9)
            && (player.posj_C2 != 0 && player.posj_C2 != 9)
            && (player.posj_L1 != 0 && player.posj_L1 != 9)
            && (player.posj_L2 != 0 && player.posj_L2 != 9)
            && (player.posj_K1 != 0 && player.posj_K1 != 9)
            && (player.posj_K1 != 0 && player.posj_K1 != 9)
            && (player.posj_T1 != 0 && player.posj_T1 != 9)
            && (player.posj_T2 != 0 && player.posj_T2 != 9))
            player.player_won = 1;
    }
    if (player.player_number == 2)
    {
        if ((player.posi_C1 == 0 && player.posi_C2 == 0 && player.posi_K1 == 0 
            && player.posi_K2 == 0 && player.posi_L1 == 0 && player.posi_L2 == 0
            && player.posi_T1 == 0 && player.posi_T2 == 0)
            && (player.posj_C1 != 0 && player.posj_C1 != 9)
            && (player.posj_C2 != 0 && player.posj_C2 != 9)
            && (player.posj_L1 != 0 && player.posj_L1 != 9)
            && (player.posj_L2 != 0 && player.posj_L2 != 9)
            && (player.posj_K1 != 0 && player.posj_K1 != 9)
            && (player.posj_K1 != 0 && player.posj_K1 != 9)
            && (player.posj_T1 != 0 && player.posj_T1 != 9)
            && (player.posj_T2 != 0 && player.posj_T2 != 9))
            player.player_won = 1;
    }
}