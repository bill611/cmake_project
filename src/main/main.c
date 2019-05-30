#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "cmake_config.h"

static void* test(void* arg)
{
    while (1) {
        printf("%s(),%s,%d\n", __func__,__FILE__,__LINE__);
        sleep(5);
    }
    return NULL;
}
int createThread(void *(*start_routine)(void *), void *arg)
{
    int result;
    pthread_t      task;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    result = pthread_create(&task, &attr, start_routine, arg);
    if(result)
        printf("create thread failt,Error code:%d\n",result);
    pthread_attr_destroy(&attr);
    return task;
}


int main(int argc, char *argv[])
{
    printf("%s(),%s,%d\n", __func__,__FILE__,__LINE__);
    printf("version:%d,%d\n",VERSION_MAJOR,VERSION_MINOR);
    mode1();
    mode2();
    createThread(test,NULL);
    pause();
    return 0;
}
