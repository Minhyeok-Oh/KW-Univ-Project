#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <linux/unistd.h>

#define MAX_PROCESSES 100
void* thread_func(void *arg);
void cleanup_func(void *arg);


int main(void)
{
    pthread_t tid[MAX_PROCESSES+1];
    int i;
    for(i=0; i<MAX_PROCESSES; i++){
        pthread_create(&tid[i], NULL, thread_func, NULL);
        pthread_join(tid[i], NULL);
    }

    
        
}

void * thread_func(void *arg){
    pthread_cleanup_push(cleanup_func, "cleanup");
    FILE * f_read = fopen("./temp.txt", "rt");
    int num, num1, num2;

    if(fscanf(arg, "%d", &num1)!=-1 && fscanf(arg, "%d", &num2)!=-1)
    {
        num = num1*num2;
        fprintf(arg, "%d",num);
    }

    pthread_cleanup_pop((void*)arg);
    
    return (void*)arg;
}

void cleanup_func(void *arg)
{
    printf("%s\n", (char*)arg);
}