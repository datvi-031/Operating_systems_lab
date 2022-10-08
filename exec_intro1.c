// CS20B1031 - Daathwinaagh
// demonstrating exec() system calls

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
    printf("I am in exec1.c\n");
    printf("[exec_intro1.c] with [PID: %u]\n",getpid());
    
    char* args[] = {"Hello", "demostrating", "exec", NULL};
    
    execv("./exec2",args);
    
    // this wont be printed because executable file of exec2.c will be replaced in exec1.c
    // pid is same because code replced not the process is created or destroyed
    printf("Welcome to exec1.c again!\n");
    return 0;
}