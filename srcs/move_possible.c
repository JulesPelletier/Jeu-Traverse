#include "../includes/lib_func.h"

int     move_possible(int x, int y, char **map)
{
    if (is_pawn(map[x][y]) == 1)
        return (-1);
    else
        return (0);
}