#include "../includes/lib_func.h"

int     check_move(t_pawns player, int posi1, int posj1, int posi2, int posj2, char **map)
{
    int     move_x;
    int     move_y;

    move_x = 0;
    move_y = 0;
    if (map[posi1][posj1] == 'K')
    {
        if (((posi1 - posi2 == 1) || (posi1 - posi2 == -1)) && (posj1 == posj2))
            swap(posi1, posi2, posj1, posj2, map);
        else if (((posj1 - posj2 == 1) || (posj1 - posj2 == -1)) && (posi1 == posi2))
            swap(posi1, posi2, posj1, posj2, map);
        else
        {
            printf(RED"ERREUR : deplacement impossible pour ce pion\n");
            return (-1);
        }
    }
    else if (map[posi1][posj1] == 'L')
    {
        if (((posi1 - posi2 == 1) && (posj1 - posj2 == 1))
            || ((posi1 - posi2 == 1) && (posj1 - posj2 == -1))
            || ((posi1 - posi2 == -1) && (posj1 - posj2 == 1))
            || ((posi1 - posi2 == -1) && (posj1 - posj2 == -1)))
            swap(posi1, posi2, posj1, posj2, map);
        else
        {
            printf(RED"ERREUR : deplacement impossible pour ce pion\n");
            return (-1);
        }
        
    }
    else if (map[posi1][posj1] == 'T')
    {
        if (player.player_number == 1)
        {
            if (((posi1 - posi2 == -1) && (posj1 - posj2 == -1))
                || ((posi1 - posi2 == -1) && (posj1 - posj2 == 1))
                || ((posi1 - posi2 == 1) && (posj1 == posj2)))
                swap(posi1, posi2, posj1, posj2, map);
            else
            {
                printf(RED"ERREUR : deplacement impossible pour ce pion\n");
                return (-1);
            }
        }
        else if (player.player_number == 2)
        {
            if (((posi1 - posi2 == 1) && (posj1 - posj2 == -1))
                || ((posi1 - posi2 == 1) && (posj1 - posj2 == 1))
                || ((posi1 - posi2 == -1) && (posj1 == posj2)))
                swap(posi1, posi2, posj1, posj2, map);
            else
            {
                printf(RED"ERREUR : deplacement impossible pour ce pion\n");
                return (-1);
            }
        }
        
    }
    else if (map[posi1][posj1] == 'C')
    {
        if (((posi1 - posi2 == 1) && (posj1 - posj2 == 1))
            || ((posi1 - posi2 == 1) && (posj1 - posj2 == -1))
            || ((posi1 - posi2 == -1) && (posj1 - posj2 == 1))
            || ((posi1 - posi2 == -1) && (posj1 - posj2 == -1))
            || ((posi1 - posi2 == 1 || posi1 - posi2 == -1) && (posj1 == posj2))
            || ((posj1 - posj2 == 1 || posj1 - posj2 == -1) && (posi1 == posi2)))
            swap(posi1, posi2, posj1, posj2, map);
        else
        {
            printf(RED"ERREUR : deplacement impossible pour ce pion\n");
            return (-1);
        }
        
    }
   return (0);
}

int     check_move_IA(t_pawns player, int posi1, int posj1, int posi2, int posj2, char **map)
{
    int     move_x;
    int     move_y;

    move_x = 0;
    move_y = 0;
    if (map[posi1][posj1] == 'K')
    {
        if (((posi1 - posi2 == 1) || (posi1 - posi2 == -1)) && (posj1 == posj2))
            swap(posi1, posi2, posj1, posj2, map);
        else if (((posj1 - posj2 == 1) || (posj1 - posj2 == -1)) && (posi1 == posi2))
            swap(posi1, posi2, posj1, posj2, map);
        else
            return (-1);
    }
    else if (map[posi1][posj1] == 'L')
    {
        if (((posi1 - posi2 == 1) && (posj1 - posj2 == 1))
            || ((posi1 - posi2 == 1) && (posj1 - posj2 == -1))
            || ((posi1 - posi2 == -1) && (posj1 - posj2 == 1))
            || ((posi1 - posi2 == -1) && (posj1 - posj2 == -1)))
            swap(posi1, posi2, posj1, posj2, map);
        else
            return (-1);
    }
    else if (map[posi1][posj1] == 'T')
    {
        if (player.player_number == 1)
        {
            if (((posi1 - posi2 == -1) && (posj1 - posj2 == -1))
                || ((posi1 - posi2 == -1) && (posj1 - posj2 == 1))
                || ((posi1 - posi2 == 1) && (posj1 == posj2)))
                swap(posi1, posi2, posj1, posj2, map);
            else
                return (-1);
        }
        else if (player.player_number == 2)
        {
            if (((posi1 - posi2 == 1) && (posj1 - posj2 == -1))
                || ((posi1 - posi2 == 1) && (posj1 - posj2 == 1))
                || ((posi1 - posi2 == -1) && (posj1 == posj2)))
                swap(posi1, posi2, posj1, posj2, map);
            else
                return (-1);
        }
        
    }
    else if (map[posi1][posj1] == 'C')
    {
        if (((posi1 - posi2 == 1) && (posj1 - posj2 == 1))
            || ((posi1 - posi2 == 1) && (posj1 - posj2 == -1))
            || ((posi1 - posi2 == -1) && (posj1 - posj2 == 1))
            || ((posi1 - posi2 == -1) && (posj1 - posj2 == -1))
            || ((posi1 - posi2 == 1 || posi1 - posi2 == -1) && (posj1 == posj2))
            || ((posj1 - posj2 == 1 || posj1 - posj2 == -1) && (posi1 == posi2)))
            swap(posi1, posi2, posj1, posj2, map);
        else
            return (-1);
    }
    return (0);
}

int     error_pawn(t_pawns player, int posi1)
{
    if ((posi1 != player.posi_C1) && (posi1 != player.posi_C2) && (posi1 != player.posi_K1)
        && (posi1 != player.posi_K2) && (posi1 != player.posi_L1) && (posi1 != player.posi_L2)
        && (posi1 != player.posi_T1) && (posi1 != player.posi_T2))
    {
        printf(RED"ERREUR : pas votre pion\n");
        return (-1);
    }
    return (0);
}

int     check_arrival(t_pawns player, int posi1, int posj1, int posi2, int posj2, char **map)
{
    if (is_pawn(map[posi2][posj2]) == '1')
        return (-1);
    else
        return (0);
}

int     check_starting_pos(int posi1, int posj1, char **map)
{
    if (map[posi1][posj1] == '0')
    {
        printf(RED"PROBLEME : pas de pion sur la case de depart\n");
        return (-1);
    }
    return (0);
}