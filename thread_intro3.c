// CS20B1031 -Daathwinaagh
// adding array elements and printing sum of elem of arr in main process

#include <stdio.h>
#include <stdlib.h>
#include<pthread.h>

int size;
int sum=0;

// thread function that calculates sum 
void *calculate_sum(void *ptr)
{
    int* msg;
    msg = (int*)ptr;
    printf("Inside the thread: ");
    
    // updating global variable while seeing element on traversing the array
    for(int i=0; i<size; i++)
    	sum+=msg[i];
    	
    printf("Sum computed : %d\n", sum);
}

int main()
{
    // creating thread
    pthread_t thread;
    printf("What's Array size? : ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter array elem [space seperated]: ");
    for(int i=0; i<size; i++)
    	scanf("%d", &arr[i]);

    // adding functionality to the created thread
    int iret = pthread_create(&thread, NULL, calculate_sum, arr);
    if(iret != 0) 
    {
        // in unsuccessful case
        printf("Thread creation is unsuccessful..\n");
        return -1;
    }

    // joining thread
    if(pthread_join(thread, NULL)!=0) {
        // in unsuccessful case
        printf("Joining thread is unsuccessful..\n");
        return -1;
    }
    // printing sum of elements computed by thread from global variable..
    printf("In main process: The sum of elements of array: %d\n", sum);
    return 0; 
}