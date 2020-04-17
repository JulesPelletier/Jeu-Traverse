#include "../includes/lib_func.h"

int     is_pawn(char c)
{
    if (c == 'K' || c == 'T' || c == 'L' || c == 'C')
        return (1);
    else
        return (0);
}