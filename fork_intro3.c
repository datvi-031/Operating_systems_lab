// CS20B1031 -Daathwinaagh
// parent process - ascendingSort,, child process - descendingSort

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

// function used for printing the array
void printArray(int *a)
{
    for(int i=0; i<10; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// according the decision flow in main();
// this function is called in the child process
void childProcess(int *a)
{
    int temp;
    pid_t pid = getpid();
    printf(">> CHILD PROCESS\t [PID: %d] \n", pid);
    for(int i=0; i<9; i++)
        for(int j=i+1; j<10; j++)
            if(a[i]<a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    printf(">> DESCENDING ORDER : ");
    printArray(a);
}

// according the decision flow in main();
// this function is called in parent process
void parentProcess(int *a)
{
    int temp;
    pid_t pid = getpid();
    printf(">> PARENT PROCESS\t [PID: %d] \n", pid);
    for(int i=0; i<9; i++)
        for(int j=i+1; j<10; j++)
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    printf(">> ASCENDING ORDER : ");
    printArray(a);
}

int main()
{
    int a[10];
    pid_t pid;
    printf("Enter the 10 elements one by one [space seperated] : ");
    for(int i=0; i<10; i++)
        scanf("%d", &a[i]);
        
    // fork() returns -ve - child process creation is unsuccessful
    // fork() returns 0 - child process creation is successsful
    // fork() returns +ve - parent process
    
    pid = fork();
    wait(NULL);
    if(pid == 0)
    {
        // should sort the array in descending order
        childProcess(a);
        printf("\n");
    }
    else if(pid > 0)
    {
        // should sort the array in ascending order
        parentProcess(a);
        printf("\n");
    }
    else
        printf("ERROR: child process creation is unsuccesssful\n");
    return 0;
}