#include "../includes/lib_func.h"

char    **test_1(void)
{
    char **map;
    int i;

    map = create_map(10);
    i = 0;
    printf("--- CREATE MAP ---\n");
    while (i < 10)
    {
        printf("%s\n", map[i]);
        i++;
    }

    printf("\n\n----- AFFICHAGE --------\n\n");

    affichage_map(map);
    printf("\n");
    return (map);
}

char    **test_2(void)
{
    char **map;
    map = test_1();
    int n_players = 2;

    t_pawns *players;

    players = (t_pawns *)malloc(sizeof(t_pawns) * n_players);
    configure_struct_1(&players[0]);
    configure_struct_2(&players[1]);

    map_filled(map, players[0]);
    map_filled(map, players[1]);

    printf("------ FILL MAP ----\n\n");
    affichage_map(map);
    printf("\n");

    return (map);
}

void    test_rules(void)
{
    t_rules rules;
    int     number_players;
    int     mode;
    char    **player_names;
    int     i;

    number_players = 0;
    mode = 0;
    player_names = NULL;

    init_rules(&rules);
    printf("How many players ?  : ");
    scanf("%d", &number_players);
    printf("\n");
    printf("Which mode ?  : ");
    scanf("%d", &mode);
    printf("\n");
    player_names = (char **)malloc(sizeof(char *) * (number_players + 1));

    i = 0;
    while (i < number_players)
    {
        player_names[i] = (char *)malloc(sizeof(char) * 50);
        printf("Enter player %d's name : ", i + 1);
        scanf("%s", player_names[i]);
        printf("\n");
        i++;
    }
    player_names[i] = "\0";

    rules.mode = mode;
    rules.name_player = player_names;
    rules.number_players = number_players;

    printf("Mode : %d\n", rules.mode);
    printf("Number of Players : %d\n", rules.number_players);

        i = 0;
    while (i < number_players)
    {
        printf("Player %d name : %s\n", i + 1, player_names[i]);
        i++;
    }
}

int main_1(void)
{
    test_rules();
    test_1();
    test_2();
    return (0);
}
