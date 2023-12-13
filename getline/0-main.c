#include "laps.h"

/**
 * main - entry point.
 *
 * Return: always 0.
 */
int main()
{

    int ids1[2] = {2, 89};
    int ids2[1] = {102};
    
    race_state(ids1, 2);
    race_state(ids1, 2);
    race_state(ids1, 2);
    race_state(ids1, 2);
    puts("from here it fucks up");
    race_state(ids2, 1);
    race_state(ids1, 2);
    race_state(ids1, 2);
    race_state(ids2, 1);
    
    race_state(NULL, 0);
    return (0);
}
