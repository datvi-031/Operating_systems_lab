// CS20B1031 -Daathwinaagh
// Printing 0 to N values inside thread, provided n is taken from main process..

#include <stdio.h>
#include <stdlib.h>
#include<pthread.h>

void *print_upto_n(void *ptr)
{
    int* msg;
    msg = (int*)ptr;
    printf("Passed value from main Process: %d\n", *msg);
    printf("Printing inside the thread : ");
    
    // printing from 0 to n (Using ITERATIVE APPROACH)
    for(int i=0; i <= *msg; i++)
        printf("%d ", i);
    printf("\n");
}

int main()
{
    pthread_t thread;
    int iret, num;

    printf("What's n? : ");
    scanf("%d", &num);
    
    // thread creation
    iret = pthread_create(&thread, NULL, print_upto_n, &num);
    if(iret != 0) 
    {
        // in unsuccess case
        printf("Thread creation is unsuccessful..\n");
        return -1;
    }

    // joining the thread
    if(pthread_join(thread, NULL)!=0) 
    {
        // in unsuccessful case
        printf("Joining thread is unsuccessful..\n");
        return -1;
    }
    
    return 0; 
}