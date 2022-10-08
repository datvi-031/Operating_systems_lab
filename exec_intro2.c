#include<stdio.h>
#include<unistd.h>
int main(int argc, char** argv)
{
    // compile the code with the commmand "gcc exec_intro.c -o exec2"
    printf("Iam in exec_intro2.c\n");
    printf("Code replaced : from [exec_intro2.c] with [PID: %u]\n", getpid());
    return 0;
}