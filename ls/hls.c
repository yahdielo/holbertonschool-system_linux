#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "main.h"

/**
 * checkHidden - checks if the file name start with .
 * @str: name of the file
 * return: 0 if strat with . and -1 if not
 */
int checkHidden(char str[]){

    char check[] = ".";

    if ( check[0] == str[0]){
        return 0;
    }
    else{
        return -1;
    }
}
/**
 * main - fucntion wish is the mane program
 * @arc: arguiment count
 * @argv: argument vector
 * return: always 0
 */
int main(int argc, char *argv[]){

    DIR *dir;
    char *path;
    struct dirent *dp;

    if (argc == 1){

        path = ".";
        dir = opendir((const char *)path);

        while ((dp = readdir(dir)) != NULL){

            if (checkHidden(dp->d_name) == 0){
                continue;
            }
            printf("%s ", dp->d_name);
        }
        printf("\n");
        closedir(dir);
    }
    else if (argc == 2){

        if (cmpStrings(argv[1], "-ls") != 0){
            path = argv[1];
            dir = opendir((const char *)path);

            while ((dp = readdir(dir)) != NULL){

                if (checkHidden(dp->d_name) == 0){
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
            while ((dp = readdir(dir)) != NULL){

                if (checkHidden(dp->d_name) == 0){
                    continue;
            }
                printf("%s\n", dp->d_name);
            }
            closedir(dir);
        }

    }
    return 0;
}
