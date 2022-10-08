// CS20B1031 - Daathwinaagh
// print EVEN_SUM in child process ODD_SUM in parent process in range [1, n]

#include<stdio.h>
#include<unistd.h>

void childProcess(int num);
void parentProcess(int num);

// according to decision flow in main();
// this function will be executed in child process
void childProcess(int num)
{
    int ODD_SUM = 0;
    pid_t Cpid = getpid();
    printf("CHILD PROCESS\tPID: %d\n",Cpid);
    
    for(int i=1; i<=num; i=i+2)
        ODD_SUM = ODD_SUM + i;
    
    printf("Odd sum in the range of [1, %d] : %d\n", num, ODD_SUM);
}

// according to decision flow in main();
// this function will be executed in parent process
void parentProcess(int num)
{
    int EVEN_SUM = 0;
    pid_t Ppid = getpid();
    printf("PARENT PROCESS\tPID: %d\n",Ppid);
    
    for(int i=2; i<=num; i=i+2)
        EVEN_SUM = EVEN_SUM + i;
    
    printf("Even sum in the range of [1, %d] : %d\n", num, EVEN_SUM);
}

int main()
{
    int num;
    pid_t pid;
    
    // fork() returns -ve value of type pid_t : child process creation is unsuccessful
    // fork() returns 0 value of type pid_t : child process crearion is successful
    // fork() returns +ve value of type pid_t : pid of parent process
    
    printf("Enter the value of N (in range[1, N]) : ");
    scanf("%d", &num);
    pid = fork();
    
    if(pid == 0)
        childProcess(num);
    else if(pid > 0)
        parentProcess(num);
    else
        printf("ERROR : child process creation is unsuccessful\n");
    return 0;
}