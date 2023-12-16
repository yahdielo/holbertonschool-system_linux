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
    size_t i, newLinePos = 0, restetBuff;
    /* to initialize the buflen*/
    if(buffLen == 0)
    {
        /*read a chuk of data drom file size of READ_zide to bytesRead*/
        bytesRead = read(fd, buff, READ_SIZE);
        if (bytesRead <= 0) {
            return NULL; 
        }
        /*assing the lenght if the chunk od data read to bufflen*/
        buffLen = (size_t)bytesRead;
    }

    while (newLinePos < buffLen && buff[newLinePos] != '\n')
    {
        newLinePos++;
    }
    /*to correcly print the file content, i need to know where is the position of the nes line
        and allocate memory for that line + 1 to include the null byte*/
    line = malloc(newLinePos + 1);
    if (line == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    /*copy the content of the buffer to the dynamic allocated memory
        the memory is allocated just unitl new line is found, to correctly print the file
        line by line*/
    for (i = 0; i < newLinePos; ++i) {
        line[i] = buff[i];
        if(line[i] == EOF)
            break;
    }
    /*null terminate the line*/
    buff[newLinePos] = '\0';
    /* Ones the chunk of data from  the buffer before the new line is allocated,
        and we still have some data in the buffer, we need to reset the buffer to start from 0,
        to correctly allocate the new line, in a new line when printing it.*/
    restetBuff = buffLen - newLinePos - 1;
    line = realloc(line, restetBuff + 1);
    for( i = 0; i < newLinePos; ++i)
    {
        line[i] = buff[newLinePos + 1 + i];
    }

    buffLen =  restetBuff;

    return line;
}
