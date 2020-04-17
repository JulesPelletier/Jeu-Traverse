#include "../includes/lib_func.h"

int     check_rounds(int compteur, char **map, t_pawns *players)
{
    int j;
    int res1;
    int res2;

    j = 0;
    res1 = 0;
    res2 = 0;
    if (compteur == 30)
    {
        while (j < 10)
        {
            if (map[0][j] == '0')
                res1++;
            if (map[9][j] == '0')
                res2++;
            j++;
        }
        if (res1 != 8)
        {
            printf("GAME OVER : Player 1 n'a pas sorti toutes ses pieces en 30 coups\n");
            players[1].player_won = 1;
            return (-1);
        }
        if (res2 != 8)
        {
            printf("GAME OVER : Player 2 n'a pas sorti toutes ses pieces en 30 coups\n");
            players[0].player_won = 1;
            return (-1);
        }
    }
    return (0);
}