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

class FindInfo
{
public:
void createThread(char* FILE_NAME,char* FILE_COMMAND);
};

void *threadWriteFile(void *param);

#endif // THREADS_H
