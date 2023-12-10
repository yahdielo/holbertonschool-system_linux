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
                    /* if the dir returns null, shop the last file ot dire name
                        and look if the last token is a file that exist.
                        if exist return it else print to stdrerr*/
                    char delimiters[] = "/";
                    char *tokens[10];  
                    int tokenCount = 0;
                    char *lastToken, lasTokenString[10];

                    char *token = strtok(path, delimiters);

                    // Store tokens in an array
                    while (token != NULL && tokenCount < 10) {
                        tokens[tokenCount++] = token;
                        lastToken = token;
                        token = strtok(NULL, delimiters);
                    }
                    strcat(lasTokenString, lastToken);

                    char newString[1000] = "";  
                    for (int i = 0; i < tokenCount - 1; ++i) {
                        strcat(newString, tokens[i]);
                        if (i != tokenCount - 2)
                            strcat(newString, "/");
                    }
                    path = newString;
                    newDir = opendir((const char *)path);
                    if(newDir != NULL){
                        while ((dp = readdir(dir)) != NULL) {
                            if(cmpStrings(lastToken, dp->d_name) == 0)
                                printf("%s  ", dp->d_name);
                        }

                    }else{
                        char error_message[256];
                        sprintf(error_message, "%s %s", argv[0], argv[i]);
                        perror(error_message);
                        continue;

                    }
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
