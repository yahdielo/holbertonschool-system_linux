#include "_getline.h"
/**
 * 
 */
char *_getline(const int fd)
{
    static char buff[READ_SIZE];
    static size_t buffLen = 0;
    ssize_t bytesRead;
    int newLines[60];
    char *line;
    size_t i,count = 0, newLinePos = 0;

    if(buffLen == 0)
    {
        bytesRead = read(fd, buff, READ_SIZE);
        if (bytesRead <= 0) {
            return NULL; 
        }
        buffLen = (size_t)bytesRead;
    }
    while (newLinePos < buffLen)
    {
        if (buff[newLinePos] == '\n')
        {
            newLines[count] = newLinePos;
            count++;
        }
        newLinePos++;
    }
    line = malloc(newLinePos + 2);
    if (line == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < newLinePos; ++i) {
        line[i] = buff[i];
    }
    line = realloc(line, sizeof(newLines[1]));

    buffLen = (size_t)bytesRead - newLines[0];
    
    for (i = newLines[0]; i < buffLen; ++i) 
    {
        line[i] = buff[i];
    }
    line[buffLen] = '\0';
    buffLen = 0;

    return line;
}
