#ifndef _GETLINE_H
#define _GETLINE_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define READ_SIZE 64

char *_getline(const int fd);

#endif /* _GETLINE_H */
