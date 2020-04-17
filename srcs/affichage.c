#include "../includes/lib_func.h"

int    color_code_1(t_pawns players, int i, int j)
{
    if ((i == players.posi_C1 && j == players.posj_C1)
        || (i == players.posi_C2 && j == players.posj_C2))
    {
        printf(BLU"C ");
        return (0);
    }
    if ((i == players.posi_K1 && j == players.posj_K1)
        || (i == players.posi_K2 && j == players.posj_K2))
    {
        printf(BLU"K ");
        return (0);
    }
    if ((i == players.posi_T1 && j == players.posj_T1)
        || (i == players.posi_T2 && j == players.posj_T2))
    {
        printf(BLU"T ");
        return (0);
    }
    if ((i == players.posi_L1 && j == players.posj_L1)
        || (i == players.posi_L2 && j == players.posj_L2))
    {
        printf(BLU"L ");
        return (0);
    }
    else
        return (-1);
}

int    color_code_2(t_pawns players, int i, int j)
{
    if ((i == players.posi_C1 && j == players.posj_C1)
        || (i == players.posi_C2 && j == players.posj_C2))
    {
        printf(YEL"C ");
        return (0);
    }
    if ((i == players.posi_K1 && j == players.posj_K1)
        || (i == players.posi_K2 && j == players.posj_K2))
    {
        printf(YEL"K ");
        return (0);
    }
    if ((i == players.posi_T1 && j == players.posj_T1)
        || (i == players.posi_T2 && j == players.posj_T2))
    {
        printf(YEL"T ");
        return (0);
    }
    if ((i == players.posi_L1 && j == players.posj_L1)
        || (i == players.posi_L2 && j == players.posj_L2))
    {
        printf(YEL"L ");
        return (0);
    }
    else
        return (-1);
}

void    affichage_map(char **map)
{
    int i;
    int j;
    int taille;

    i = 0;
    taille = strlen(map[i]);
    printf("\t  0   1   2   3   4   5   6   7   8   9");
    printf("\n\t-----------------------------------------\n");
    while (i < taille)
    {
        j = 0;
        printf("%d\t", i);
        while (j < taille)
        {
            printf("| %c ", map[i][j]);
            j++;
        }
        printf("| \t%d", i);
        printf("\n\t-----------------------------------------\n");
        i++;
    }
    printf("\t  0   1   2   3   4   5   6   7   8   9\n");

}

void    affichage_map_bis(char **map, t_pawns *players)
{
    int i;
    int j;
    int taille;

    i = 0;
    taille = strlen(map[i]);
    printf(MAG"       ZONE DEPART JOUEUR 1 / ZONE ARRIVEE JOUEUR 2\n\n");
    printf(WHT"\t  0   1   2   3   4   5   6   7   8   9");
    printf("\n\t-----------------------------------------\n");
    while (i < taille)
    {
        j = 0;
        printf("%d\t", i);
        while (j < taille)
        {
            printf(WHT"| ");
            if ((color_code_1(players[0], i, j) == -1) && (color_code_2(players[1], i, j) == -1))
                printf(WHT"0 ");
            j++;
        }
        printf(WHT"| \t%d", i);
        printf("\n\t-----------------------------------------\n");
        i++;
    }
    printf("\t  0   1   2   3   4   5   6   7   8   9\n");
    printf(MAG"\n       ZONE DEPART JOUEUR 2 / ZONE ARRIVEE JOUEUR 1\n\n");
}

void    affichage_simple(char **map)
{
    int i;

    i = 0;
    while (i < 10)
    {
        printf("%s\n", map[i]);
        i++;
    }
}