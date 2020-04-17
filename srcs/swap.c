#include "../includes/lib_func.h"

void    swap(int posi1, int posi2, int posj1, int posj2, char **map)
{
    char    temp;

    temp = map[posi1][posj1];
    map[posi1][posj1] = map[posi2][posj2];
    map[posi2][posj2] = temp;
}