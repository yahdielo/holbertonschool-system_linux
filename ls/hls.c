#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/**
 * cmpString: compare strings to see if are the same
 * return 0
 */
int cmpStrings(char str[],char str2[]){
    unsigned long i;

    if (strlen(str) == strlen(str2)){

        for (i=0; i <= strlen(str); i++){
            if (str[i] != str2[i])
                return -1;
            else
                return 0;
        }
    }
    return -1;
}
/**
 * checkHidden: checks if the file name start with . means in hidden
 * return 0
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
 * this is the profram to replicate the LS command in the shell
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
