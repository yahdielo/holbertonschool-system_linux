#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/**
 * this is the profram to replicate the LS command in the shell
 */

int main(int argc, char *argv[]){

    DIR *dir;
    char *path;
    char hidden[] = ".";
    struct dirent *dp;

    if (argc == 1){

        path = ".";
        dir = opendir((const char *)path);

        while ((dp = readdir(dir)) != NULL){

            if (strchr(dp->d_name, hidden[0])){
                continue;
            }
            printf("%s ", dp->d_name);
        }
        printf("\n");
        closedir(dir);
    }
    else if (argc == 2){

        if (strcmp(argv[1], "-ls") != 0){
            path = argv[1];
            dir = opendir((const char *)path);

            while ((dp = readdir(dir)) != NULL){

                if (strchr(dp->d_name, hidden[0])){
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

                if (strchr(dp->d_name, hidden[0])){
                continue;
            }
                printf("%s\n", dp->d_name);
            }
            closedir(dir);
        }

    }
    return 0;
}
