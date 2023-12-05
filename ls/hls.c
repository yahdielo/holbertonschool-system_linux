#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/**
 * this  program replicate the LS command
 */

int main(int argc, char *argv[]){

    DIR *dir;
    const char *path;
    struct dirent *dp;

    if (argv[1]){
        path = argv[1];
    }
    else{
        path = ".";
    }

    dir = opendir((const char *)path);

    if (dir == NULL){
        perror("Could not open directory");
        exit(1);
    }

    if (argc == 2){
    while ((dp = readdir(dir)) != NULL) {
        printf("%s \n", dp->d_name); 
        }
    }
    closedir(dir);
    return 0;
}
