#include <stdio.h>
#include <string.h>

/**
 * checkOption - loop the firts char of every argument of the str to check for the option -
 * @count: is the argument coun pass from the main program
 * @str: is the lust of string raguments pass from the main 
 * Return: the position of the option argument in the argv/str else -1
 */

int checkOption(int count, char *str[])
{
    int i;
    unsigned long j;

    for (i = 1; i < count; i++){
        for (j = 0; j < 1; j++)
        {
            if(str[i][0] == '-')
                return i;
        }
    }
    return -1;
}
