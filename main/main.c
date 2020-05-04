#include "../includes/lib_func.h"

void    print_header(void)
{
    printf("\n\n");
    printf(WHT"████████ ██████   █████  ██    ██ ███████ ██████  ███████ ███████ \n");
    printf(WHT"   ██    ██   ██ ██   ██ ██    ██ ██      ██   ██ ██      ██      \n");
    printf(WHT"   ██    ██████  ███████ ██    ██ █████   ██████  ███████ █████   \n");
    printf(WHT"   ██    ██   ██ ██   ██  ██  ██  ██      ██   ██      ██ ██      \n");
    printf(WHT"   ██    ██   ██ ██   ██   ████   ███████ ██   ██ ███████ ███████ \n");
    printf("\n\n");
}

char    **setup_map(t_pawns *players)
{
    char **map;

    map = create_map(10);

    map_filled(map, players[0]);
    map_filled(map, players[1]);

    return (map);
}

int     main(int ac, char **av)
{
    t_rules     rules;
    int         compteur;
    t_pawns     *players;
    char        **map;

    int         pos_depart_i;
    int         pos_depart_j;
    int         pos_arrivee_i;
    int         pos_arrivee_j;
    int         error_move;
    int         check_arr;
    int         check_start;
    int         check_input;

    int IAi_1;
    int IAi_2;
    int IAj_1;
    int IAj_2;
    int     *pos_final;

    pos_arrivee_i = 0;
    pos_arrivee_j = 0;
    pos_depart_i = 0;
    pos_depart_j = 0;
    players = NULL;
    error_move = 0;

    compteur = 0;
    rules = check_rules(ac, av);
    if (rules.error == -1)
        return (0);
    if (check_rules_params(rules) == -1)
        return (0);

    players = (t_pawns *)malloc(sizeof(t_pawns) * rules.number_players);
    configure_struct_1(&players[0]);
    configure_struct_2(&players[1]);
    map = setup_map(players);
    print_header();

    affichage_map_bis(map, players);

    if (rules.mode == 1)
    {
        while (players[0].player_won == 0 && players[1].player_won == 0)
        {
            players[0].player_played = 0;
            players[1].player_played = 0;

            while (players[0].player_played == 0)
            {
                error_move = 0;
                check_arr = 0;
                check_input = 0;
                check_start = 0;
                printf(WHT"\n  ------  Tour du joueur 1  ------ \n\n");
                printf("Case de depart \n\n");
                printf("Numero ligne : ");
                scanf("%d", &pos_depart_i);
                printf("Numero colonne : ");
                scanf("%d", &pos_depart_j);
                printf("\n\n");
                printf("Case d'arrivee \n\n");
                printf("Numero ligne : ");
                scanf("%d", &pos_arrivee_i);
                printf("Numero colonne : ");
                scanf("%d", &pos_arrivee_j);
                printf("\n\n");
                check_input = check_inputs(pos_arrivee_i, pos_arrivee_j, pos_depart_i, pos_depart_j);
                if (check_input == 0)
                {
                    error_move = error_pawn(players[0], pos_depart_i);
                    check_arr = check_arrival(players[0], pos_depart_i, pos_depart_j, pos_arrivee_i, pos_arrivee_j, map);
                    check_start = check_starting_pos(pos_depart_i, pos_depart_j, map);
                    if (error_move == 0 && check_arr == 0 && check_start == 0)
                    {
                        if (check_move(players[0], pos_depart_i, pos_depart_j, pos_arrivee_i, pos_arrivee_j, map) != -1)
                        {
                            players[0].player_played = 1;
                            players[0] = update_pos(players[0], pos_depart_i, pos_depart_j, pos_arrivee_i, pos_arrivee_j);
                        }
                    }
                    else if (error_move == 0 && check_arr == -1 && check_input == 0)
                    {
                        pos_final = saut(players[0], pos_depart_i, pos_arrivee_i, pos_depart_j, pos_arrivee_j, map);
                        players[0].player_played = 1;
                        players[0] = update_pos(players[0], pos_depart_i, pos_depart_j, pos_final[0], pos_final[1]);
                    }
                }
                //affichage_simple(map);
                affichage_map_bis(map, players);
            }
            while (players[1].player_played == 0)
            {
                error_move = 0;
                check_arr = 0;
                check_input = 0;
                printf(WHT"\n  ------  Tour du joueur 2  ------ \n\n");
                printf("Case de depart \n\n");
                printf("Numero ligne : ");
                scanf("%d", &pos_depart_i);
                printf("\n");
                printf("Numero ligne : ");
                scanf("%d", &pos_depart_j);
                printf("\n\n");
                printf("Case d'arrivee \n\n");
                printf("Numero ligne : ");
                scanf("%d", &pos_arrivee_i);
                printf("\n");
                printf("Numero ligne : ");
                scanf("%d", &pos_arrivee_j);
                printf("\n\n");
                check_input = check_inputs(pos_arrivee_i, pos_arrivee_j, pos_depart_i, pos_depart_j);
                if (check_input == 0)
                {
                    error_move = error_pawn(players[1], pos_depart_i);
                    check_arr = check_arrival(players[1], pos_depart_i, pos_depart_j, pos_arrivee_i, pos_arrivee_j, map);
                    if (error_move == 0 && check_arr == 0 && check_input == 0)
                    {
                        if (check_move(players[1], pos_depart_i, pos_depart_j, pos_arrivee_i, pos_arrivee_j, map) != -1)
                        {
                            players[1].player_played = 1;
                            players[1] = update_pos(players[1], pos_depart_i, pos_depart_j, pos_arrivee_i, pos_arrivee_j);
                        }
                    }
                    else if (error_move == 0 && check_arr == -1 && check_input == 0)
                    {
                        pos_final = saut(players[1], pos_depart_i, pos_arrivee_i, pos_depart_j, pos_arrivee_j, map);
                        players[1].player_played = 1;
                        players[1] = update_pos(players[1], pos_depart_i, pos_depart_j, pos_final[0], pos_final[1]);
                    }
                }
                //affichage_simple(map);
                affichage_map_bis(map, players);
            }
            compteur++;
            //printf("####Compteur : %d\n", compteur);
            if (check_rounds(compteur, map, players) == 1)
                break;
            check_victory(players[0]);
            check_victory(players[1]);
        }
    }
    if (rules.mode == 2)
    {
        while (players[0].player_won == 0 && players[1].player_won == 0)
        {
            players[0].player_played = 0;
            players[1].player_played = 0;

            while (players[0].player_played == 0)
            {
                error_move = 0;
                check_arr = 0;
                check_input = 0;
                check_start = 0;
                printf(WHT"\n  ------  Tour du joueur 1  ------ \n\n");
                printf("Case de depart \n\n");
                printf("Numero ligne : ");
                scanf("%d", &pos_depart_i);
                printf("Numero colonne : ");
                scanf("%d", &pos_depart_j);
                printf("\n\n");
                printf("Case d'arrivee \n\n");
                printf("Numero ligne : ");
                scanf("%d", &pos_arrivee_i);
                printf("Numero colonne : ");
                scanf("%d", &pos_arrivee_j);
                printf("\n\n");
                check_input = check_inputs(pos_arrivee_i, pos_arrivee_j, pos_depart_i, pos_depart_j);
                if (check_input == 0)
                {
                    error_move = error_pawn(players[0], pos_depart_i);
                    check_arr = check_arrival(players[0], pos_depart_i, pos_depart_j, pos_arrivee_i, pos_arrivee_j, map);
                    check_start = check_starting_pos(pos_depart_i, pos_depart_j, map);
                    if (error_move == 0 && check_arr == 0 && check_start == 0)
                    {
                        if (check_move(players[0], pos_depart_i, pos_depart_j, pos_arrivee_i, pos_arrivee_j, map) != -1)
                        {
                            players[0].player_played = 1;
                            players[0] = update_pos(players[0], pos_depart_i, pos_depart_j, pos_arrivee_i, pos_arrivee_j);
                        }
                    }
                    else if (error_move == 0 && check_arr == -1 && check_input == 0)
                    {
                        pos_final = saut(players[0], pos_depart_i, pos_arrivee_i, pos_depart_j, pos_arrivee_j, map);
                        players[0].player_played = 1;
                        players[0] = update_pos(players[0], pos_depart_i, pos_depart_j, pos_final[0], pos_final[1]);
                    }
                }
                //affichage_simple(map);
                affichage_map_bis(map, players);
            }
            while (players[1].player_played == 0)
            {
                error_move = 0;
                check_arr = 0;
                check_input = 0;
                IAi_1 = 0;
                IAj_1 = 0;
                IAi_2 = 0;
                IAj_2 = 0;
                printf(WHT"\n  ------  Tour de l'IA  ------ \n\n");
                while (check_IA(players[1], IAi_1, IAj_1) != 1)
                {
                    IAi_1 = rand() % 10;
                    IAj_1 = rand() % 10;
                }
                while (check_move_IA(players[1], IAi_1, IAj_1, IAi_2, IAj_2, map) == -1)
                {
                    IAi_2 = rand() % 10;
                    IAj_2 = rand() % 10;
                }
                check_arr = check_arrival(players[1], IAi_1, IAj_1, IAi_2, IAj_2, map);
                if (check_arr == 0)
                {
                    players[1].player_played = 1;
                    players[1] = update_pos(players[1], IAi_1, IAj_1, IAi_2, IAj_2);
                }
                else if (check_arr == -1)
                {
                    pos_final = saut(players[1], IAi_1, IAi_2, IAj_1, IAj_2, map);
                    players[1].player_played = 1;
                    players[1] = update_pos(players[1], IAi_1, IAj_1, pos_final[0], pos_final[1]);
                }
                //affichage_simple(map);
                affichage_map_bis(map, players);
            }
            compteur++;
            //printf("####Compteur : %d\n", compteur);
            if (check_rounds(compteur, map, players) == 1)
                break;
            check_victory(players[0]);
            check_victory(players[1]);
        }

    }
    if (players[0].player_won == 1)
    {
        printf(GRN"\n\n  --------------------------  \n");
        printf(GRN"     Vainqueur : Player 1  \n");
        printf(GRN"  --------------------------  \n\n\n");
        return (0);
    }
    else if (players[1].player_won == 1)
    {
        printf(GRN"\n\n  --------------------------  \n");
        printf(GRN"     Vainqueur : Player 2  \n");
        printf(GRN"  --------------------------  \n\n\n");
        return (0);
    }
    else
    {
        printf("ERREUR INCONNUE\n");
        return (0);
    }
}