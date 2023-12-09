#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include "main.h"

/**
 * main - fucntion wish is the mane program
 * @argc: arguiment count
 * @argv: argument vector
 * Return: always 0
 */
int main(int argc, char *argv[])
{
    int result, i;
    DIR *dir;
    char *path;
    struct dirent *dp;

    if (argc == 1)
    {
        path = ".";
        dir = opendir((const char *)path);

        while ((dp = readdir(dir)) != NULL) {

            if (checkHidden(dp->d_name) == 0)
                continue;
            printf("%s ", dp->d_name);
        }
        printf("\n");
        closedir(dir);
    }
    if (argc != 1)
    {
       result = checkOption(argc, argv);
       if (result != 0)
       {
           printf("deal with the options command TODO\n");
        /**  this already deal with one option
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
        }*/
        }
        else {
            for ( i = 1; i < argc; i++){

                path = argv[i];
                dir = opendir((const char *)path);

                if (dir == NULL)
                {
                    char str[256];
                    snprintf(str, sizeof(str), "%s", strerror(errno));
                    fprintf(stdout, "%s: %s: %s\n",argv[0], path, str);
                    continue;
                }

                result = checkOption(argc, argv);
                if (argc > 2 && result != 0)
                    printf("%s:\n", path);

                while ((dp = readdir(dir)) != NULL) {

                    if (checkHidden(dp->d_name) == 0)
                        continue;
                    printf("%s  ", dp->d_name);
                }
                printf("\n");
                if (i < argc - 1)
                    printf("\n");
                closedir(dir);
            }
        }
    }
    return 0;
}
