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
    DIR *dir, *newDir;
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
       if (result)
       {
            if (cmpStrings(argv[result], "-l") != 0)
            {
                path = argv[1];
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
        else {
            for ( i = 1; i < argc; i++){

                path = argv[i];
                dir = opendir((const char *)path);

                if (dir == NULL)
                {
                    /* if the dir returns null, shop the last file ot dire name
                        and look if the last token is a file that exist.
                        if exist return it else print to stdrerr
                    printf("we enter the dir in NULL");

                    char lastToken[10];
                    char newPath[1000] = "";
                    PathDivide(path, lastToken, newPath);
                   
                    newDir = opendir((const char *)newPath);
                    if (newDir != NULL)
                    {
                        while ((dp = readdir(dir)) != NULL) {

                            if (cmpStrings(lastToken, dp->d_name) == 0)
                                printf("%s  ", dp->d_name);
                                continue;
                        }

                    }
                    else {
                        char error_message[256];
                        sprintf(error_message, "%s %s", argv[0], argv[i]);
                        perror(error_message);
                        continue;

                    }*/
                    char error_message[256];
                    sprintf(error_message, "%s %s", argv[0], argv[i]);
                    perror(error_message);
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
