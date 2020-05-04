#include "../includes/lib_func.h"

t_rules     check_rules(int ac, char **av)
{
    t_rules rules;

    init_rules(&rules);
    if (ac > 3)
    {
        printf(RED"ERREUR : trop d'arguments\n");
        rules.error = -1;
    }
    else if (ac == 3)
    {
        rules.number_players = atoi(av[1]);
        rules.mode = atoi(av[2]);
        if (rules.mode == 2)
            printf(GRN"MODE 2 : player vs IA \n");
    }
    else if (ac == 2)
    {
        rules.number_players = atoi(av[1]);
        rules.mode = 1;
        if (rules.number_players > 2)
        {
            printf(RED"MODE BONUS : NOT DONE");
            rules.error = -1;
        }
        if (rules.number_players == 1)
        {
            printf(RED"MODE NOT POSSIBLE\n");
            rules.error = -1;
        }
    }
    else if (ac == 1)
    {
        printf(GRN"DEFAULT MODE : player vs player\n");
        rules.number_players = 2;
        rules.mode = 1;
    }
    else
    {
        printf(RED"ERREUR : Probleme d'arguments\n");
        rules.error = -1;
    }
    return (rules);
}

int     check_rules_params(t_rules rules)
{
    if (rules.number_players > 2)
    {
        printf(RED"Bonus : pas fait\n");
        return (-1);
    }
    if (rules.number_players != 2 && rules.mode == 1)
    {
        printf(RED"Configuration impossible\n");
        return (-1);
    }
    if (rules.mode != 1 && rules.mode != 2)
    {
        printf(RED"Mode non defini\n");
        return (-1);
    }
    return (0);
}

int     check_inputs(int posi1, int posi2, int posj1, int posj2)
{
    if (isalpha(posi1) == 1 || (isalpha(posi2) == 1) || (isalpha(posj1) == 1) || (isalpha(posj2) == 1))
    {
        printf(RED"ERREUR : les positions entrees ne sont pas des entiers\n");
        return (-1);
    }
    if ((posi1 >= 10 || posi2 >= 10 || posj1 >= 10 || posj2 >= 10)
        || (posi1 < 0 || posi2 < 0 || posj1 < 0 || posj2 < 0))
    {
        printf(RED"ERREUR : les positions entrees sont en dehors de la map\n");
        return (-1);
    }
    return (0);
}

int     check_IA(t_pawns player, int posi1, int posj1)
{
    if (((posi1 == player.posi_C1) && (posj1 == player.posj_C1))
        || ((posi1 == player.posi_C2) && (posj1 == player.posj_C2))
        || ((posi1 == player.posi_K1) && (posj1 == player.posj_K1))
        || ((posi1 == player.posi_K2) && (posj1 == player.posj_K2))
        || ((posi1 == player.posi_L1) && (posj1 == player.posj_L1))
        || ((posi1 == player.posi_L2) && (posj1 == player.posj_L2))
        || ((posi1 == player.posi_T1) && (posj1 == player.posj_T1))
        || ((posi1 == player.posi_T2) && (posj1 == player.posj_T2)))
        return (1);
    else
        return (0);
}