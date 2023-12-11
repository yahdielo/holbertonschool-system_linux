#include <stdio.h>
#include <string.h>

/**
 * 
 * 
 */

int PathDivide(char str[], char *lastToken, char *newString) {
    char delimiters[] = "/";
    char *tokens[10];
    int tokenCount = 0, i;

    char *token = strtok(str, delimiters);

    while (token != NULL && tokenCount < 10) {
        tokens[tokenCount++] = token;
        token = strtok(NULL, delimiters);
    }

    strcpy(lastToken, tokens[tokenCount - 1]);

    for (i = 0; i < tokenCount - 1; ++i) {
        strcat(newString, tokens[i]);
        if (i != tokenCount - 2)
            strcat(newString, "/");  
    }

    return 0;
}
