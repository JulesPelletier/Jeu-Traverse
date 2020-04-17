#include "../includes/lib_func.h"

t_pawns     upadte_pos(t_pawns player, int posi1, int posj1, int posi2, int posj2)
{
    if ((player.posi_C1 == posi1) && (player.posj_C1 == posj1))
    {
        player.posi_C1 = posi2;
        player.posj_C1 = posj2;
    }
    if ((player.posi_C2 == posi1) && (player.posj_C2 == posj1))
    {
        player.posi_C2 = posi2;
        player.posj_C2 = posj2;
    }
    if ((player.posi_K1 == posi1) && (player.posj_K1 == posj1))
    {
        player.posi_K1 = posi2;
        player.posj_K1 = posj2;
    }
    if ((player.posi_K2 == posi1) && (player.posj_K2 == posj1))
    {
        player.posi_K2 = posi2;
        player.posj_K2 = posj2;
    }
    if ((player.posi_L1 == posi1) && (player.posj_L1 == posj1))
    {
        player.posi_L1 = posi2;
        player.posj_L1 = posj2;
    }
    if ((player.posi_L2 == posi1) && (player.posj_L2 == posj1))
    {
        player.posi_L2 = posi2;
        player.posj_L2 = posj2;
    }
    if ((player.posi_T1 == posi1) && (player.posj_T1 == posj1))
    {
        player.posi_T1 = posi2;
        player.posj_T1 = posj2;
    }
    if ((player.posi_T2 == posi1) && (player.posj_T2 == posj1))
    {
        player.posi_T2 = posi2;
        player.posj_T2 = posj2;
    }
    return (player);
}