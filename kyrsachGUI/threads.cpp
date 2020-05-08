#include "threads.h"

void *threadWriteFile(void *param){
    struct print_parms* p = (struct print_parms*)param;
    FILE* stream=fopen(p->FILE_NAME,"w+");
    stream = popen(p->FILE_COMMAND,"r");
    fclose(stream);
}

void createThread(char* FILE_NAME,char* FILE_COMMAND){
    pthread_t thread1_id;
    struct print_parms thread1_args;
    thread1_args.FILE_NAME=FILE_NAME;
    thread1_args.FILE_COMMAND=FILE_COMMAND;
    pthread_create(&thread1_id,NULL,&threadWriteFile,&thread1_args);
    pthread_join(thread1_id,NULL);
}
