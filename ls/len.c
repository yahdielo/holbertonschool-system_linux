#include <stdio.h>
#include <string.h>

/**
 * len - function to get the lenght of a string
 * @str: string to get the lenght
 * Return: a integer with the size of the string
 */
int len(char str[])
{
    int count = 0, i = 0;
    while (str[i] != '\0'){
        count += 1;
        i++;
    }
    return count;
}
