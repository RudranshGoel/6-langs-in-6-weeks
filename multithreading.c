#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

void *count(void *var)
{
    time_t now = time(NULL); //intial time before loop starts
    int i;
    for(i=0;;i++) //infinite loop
    {
        time_t later = time(NULL); //time inside loop
        double diff = difftime(later, now);
        if(diff==1.0) break;
    }
    printf("%d",i);
    return NULL;
}



int main()
{
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, count, NULL);
    pthread_join(thread_id, NULL);
    exit(0);
}