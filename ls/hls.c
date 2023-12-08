#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "main.h"

/**
 * main - fucntion wish is the mane program
 * @argc: arguiment count
 * @argv: argument vector
 * return: always 0
 */
int main(int argc, char *argv[])
{
    DIR *dir;
    char *path;
    struct dirent *dp;

    if (argc == 1)
    {
        path = ".";
        dir = opendir((const char *)path);

        while ((dp = readdir(dir)) != NULL) {

            if (checkHidden(dp->d_name) == 0) {
                continue;
            }
            printf("%s ", dp->d_name);
        }
        printf("\n");
        closedir(dir);
    }
    else if (argc == 2)
    {

        if (cmpStrings(argv[1], "-ls") != 0)
        {
            path = argv[1];
            dir = opendir((const char *)path);

            while ((dp = readdir(dir)) != NULL)
            {

                if (checkHidden(dp->d_name) == 0)
                {
                    continue;
                }
                printf("%s ", dp->d_name);
            }
            printf("\n");
            closedir(dir);
        }
        else {

            path = ".";
            dir = opendir((const char *)path);
            while ((dp = readdir(dir)) != NULL)
            {

                if (checkHidden(dp->d_name) == 0)
                {
                    continue;
                    }
                printf("%s\n", dp->d_name);
            }
            closedir(dir);
        }

    }
    return 0;
}
