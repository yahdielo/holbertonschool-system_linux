#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * cmpStrings - function to compare if string are the same
 * @str: the firstring
 * @str2: the second string to compare
 * Return: -1 if not the same 0 if its the same
 */
int cmpStrings(char str[], char str2[])
{
    int i;

    if (len(str) == len(str2)){

        for (i=0; i <= len(str); i++){
            if (str[i] != str2[i])
                return -1;
            else
                return 0;
        }
    }
    return -1;
}
