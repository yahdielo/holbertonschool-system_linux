#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * checkHidden - checks if the file name start with .
 * @str: name of the file
 * Return: 0 if strat with . and -1 if not
 */
int checkHidden(char str[])
{
    char check[] = ".";

    if ( check[0] == str[0]){

        return 0;
    }
    else{
        return -1;
    }
}
