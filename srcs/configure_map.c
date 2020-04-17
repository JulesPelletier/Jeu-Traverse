#include "../includes/lib_func.h"

void    configure_map_2(char **map)
{
    int i;
    int taille;

    i = 1;
    taille = strlen(map[0]);
    printf("taille : %d\n", taille);
    while (i < 5)
    {
        if (i == 1)
        {
            map[0][i] = 'K';
            map[0][taille - i - 1] = 'K';
            map[taille - 1][i] = 'K';
            map[taille - 1][taille - i - 1] = 'K';
        }
        else if (i == 2)
        {
            map[0][i] = 'T';
            map[0][taille - i - 1] = 'T';
            map[taille - 1][i] = 'T';
            map[taille - 1][taille - i - 1] = 'T';
        }
        else if (i == 3)
        {
            map[0][i] = 'L';
            map[0][taille - i - 1] = 'L';
            map[taille - 1][i] = 'L';
            map[taille - 1][taille - i - 1] = 'L';
        }
        else
        {
            map[0][i] = 'C';
            map[0][taille - i - 1] = 'C';
            map[taille - 1][i] = 'C';
            map[taille - 1][taille - i - 1] = 'C';
        }
        i++;
    }
}