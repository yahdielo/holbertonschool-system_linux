#include <string.h>
#include <stdio.h>

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

int main(void){

    char str[] = "./hola";

    if(cmpStrings(str, "./hola") == 0){
        printf("are the same \n");
        return 0;
    }

    printf("not the same");
    return -1;
}
