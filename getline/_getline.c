#include "_getline.h"
/**
 * 
 */
char *_getline(const int fd)
{
    static char buff[READ_SIZE];
    static size_t buffLen = 0;
    ssize_t bytesRead;
    char *line;
    size_t i

    if(buffLen == 0)
    {
        bytesRead = read(fd, buff, READ_SIZE);
        if (bytesRead <= 0) {
            return NULL; 
        }
        buffLen = (size_t)bytesRead;
    }
    line = malloc(buffLen + 1);
    if (line == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < buffLen; ++i) {
        line[i] = buff[i];
    }
    line[buffLen] = '\0';
    buffLen = 0;

    return line;
}
