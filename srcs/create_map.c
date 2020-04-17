#include "../includes/lib_func.h"

char    **create_map(int taille)
{
    char **map;
    int i;
    int j;

    i = 0;
    map = (char **)malloc(sizeof(char *) * (taille + 1));
    while (i < taille)
    {
        j = 0;
        map[i] = (char *)malloc(sizeof(char) * (taille + 1));
        while (j < taille)
        {
            map[i][j] = '0';
            j++;
        }
        map[i][j] = '\0';
        i++;
    }
    map[i] = "\0";
    return (map);
}
