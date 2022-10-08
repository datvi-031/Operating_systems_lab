// CS20B1031 -Daathwinaagh
// IPC using pipes parent/child/grandchild

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int pipe1[2], pipe2[2];
    int pid;
    char p1[20], p2[20], r1[20], r2[20];
    int rs1 = pipe(pipe1);
    // pipe creation on failure
    if(rs1 == -1) {
        printf("pipe creation failed..\n");
        return -1;
    }
    int rs2 = pipe(pipe2);
    // pipe creation on failure
    if(rs2 == -1)
    {
        printf("pipe creation failed..\n");
        return -1;
    }

    pid = fork();
    // parent process
    if (pid > 0)
    {
        printf("process ID: %d\n", getppid());
        close(pipe1[0]);
        printf("Enter string 1: ");
        scanf("%s", p1);
        int stat = write(pipe1[1], p1, sizeof(p1));
        // write on failure
        if(stat == -1) {
            printf("Writing failed..\n");
            return -1;
        }
        printf("written sucessful..\n");
        wait();
    }
    // child process
    else
    {
        // child of child -> grandchild process
        if (fork() == 0)
        {
            sleep(4);
            printf("process ID: %d\n", getppid());
            close(pipe2[0]);
            printf("Enter string 2: ");
            scanf("%s", p2);
            int stat = write(pipe2[1], p2, sizeof(p2));
            // write on failure
            if(stat == -1) {
                printf("Writing failed..\n");
                return -1;
            }
            printf("written successful..\n");
        }
        // in child process
        else
        {
            wait();
            printf("process ID: %d\n", getppid());
            close(pipe1[1]);
            close(pipe2[1]);
            int stat1 = read(pipe1[0], r1, sizeof(r1));
            // reading fail case
            if(stat1==-1) {
                printf("Reading failed..\n");
                return -1;
            }
            printf("string read from pipe1 is: %s\n", r1);
            int stat2 = read(pipe2[0], r2, sizeof(r2));
            // reading fail case
            if(stat2 == -1) {
                printf("Reading from pipe failed..\n");
                return -1;
            }
            printf("string read from pipe2 is: %s\n", r2);
            printf("difference in lengths is: %ld\n", strlen(r1) - strlen(r2));
        }
    }

    return 0;
}