#include "_getline.h"
/**
 * 
 */
char *_getline(const int fd)
{
    static char buff[READ_SIZE];

    while (read(fd, buff, READ_SIZE) > 0)
    {
      
    }
    return buff;
}
