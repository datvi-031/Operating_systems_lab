// CS20B1031 -Daathwinaagh
// calculating the sum of 1000 natural numbers with 5 threads(parallel computing) from 200 values each

#include <stdio.h>
#include <stdlib.h>
#include<pthread.h>

int from = 1;
int sum = 0;

void *calculateSum(void *ptr)
{
    char* msg;
    msg = (char*)ptr;
    int tSum = (from+199)*(from+200)/2 - (from-1)*from/2;
    sum += (from+199)*(from+200)/2 - (from-1)*from/2;
    from = from+200;
    printf("Processed sum in %s [from %d to %d]: %d\n", msg, from-200, from-1, tSum);
    tSum = 0;
}

int main()
{
    // creating array of threads with size = 5
    pthread_t thread[5];
    int i, iret[5];
    char* msg[5] = {"Thread 1", "Thread 2", "Thread 3", "Thread 4", "Thread 5"};

    // providing functionality for array of threads - 5 in number
    for(i=0; i<5; i++) 
    {
        iret[i] = pthread_create(&thread[i], NULL, calculateSum, (void*)msg[i]);
        if(iret[i]!=0) {
            // unsuccessful case
            printf("Thread creation is unsuccessful..\n");
            return -1;
        }
    }

    // Joining threads
    for(i=0; i<5; i++) 
    {
        if(pthread_join(thread[i], NULL)!=0) {
            // in unsuccessful case
            printf("Thread joining is unsuccessful..\n");
            return -1;
        }
    }
    
    // printing the sum that is collected from various threads into some global variable
    printf("Sum of 1000 Natural numbers is: %d\n", sum);
    return 0; 
}