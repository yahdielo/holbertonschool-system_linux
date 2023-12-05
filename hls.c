#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/**
 * this is the profram to replicate the LS command in the shell
 */

int main(int argc, char *argv[]){

   DIR *dir = opendir((const char *)'.');
   struct dirent *dp;

   if (argc != 2){
       perror ("Missing Command");
       exit(1);
   }
   if (dir == NULL){
       perror("Could not open directory");
       exit(1);
   }
   if (strcmp(argv[1], "ls")){
    while ((dp = readdir(dir)) != NULL) {
        printf("%s", dp->d_name); 
        }
   }
}
