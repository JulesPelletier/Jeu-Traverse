#include "../includes/lib_func.h"

int *saut(t_pawns player, int posi1, int posi2, int posj1, int posj2, char **map)
{
    int posi_final;
    int posj_final;
    int *pos_final;

    pos_final = malloc(sizeof(int) * 2);

    posi_final = posi1 + ((posi2 - posi1) * 2);
    posj_final = posj1 + ((posj2 - posj1) * 2);
    if (posj_final == 10)
        posj_final = posj_final - 1;
    pos_final[0] = posi_final;
    pos_final[1] = posj_final;

    return (pos_final);
}