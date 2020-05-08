#ifndef THREADS_H
#define THREADS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

struct print_parms{
    char *FILE_NAME;
    char *FILE_COMMAND;
};

void *threadWriteFile(void *param);

void createThread(char* FILE_NAME,char* FILE_COMMAND);

#endif // THREADS_H
