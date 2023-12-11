#include <stdio.h>
#include <string.h>

/**
 * 
 * 
 */

int PathDivide(char str[], char *lastToken, char *newString) {
    char delimiters[] = "/";

    // Tokenize the string
    char *tokens[10];  // Assuming a maximum of 10 tokens for simplicity
    int tokenCount = 0;

    char *token = strtok(str, delimiters);

    // Store tokens in an array
    while (token != NULL && tokenCount < 10) {
        tokens[tokenCount++] = token;
        token = strtok(NULL, delimiters);
    }

    // Copy the last token to the provided buffer
    strcpy(lastToken, tokens[tokenCount - 1]);

    // Exclude the last token when building the new string
    for (int i = 0; i < tokenCount - 1; ++i) {
        strcat(newString, tokens[i]);
        if (i != tokenCount - 2)
            strcat(newString, "/");  // Add "/" between tokens if needed
    }

    return 0;
}
