// CS20B1031 -Daathwinaagh
// IPC using PIPES (string reversing between parent and child process)

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

char str[20]="";

// algorithm for reversing the string complexity = O(size of string)
void stringReverse()
{
    char temp;
    int low=0;
    int high=strlen(str)-1;
    while(low<=high)
    {
        temp = str[low];
        str[low]=str[high];
        str[high]=temp;
        low++;
        high--;
    }
}

void childProcess(int pipe1[2], int pipe2[2])
{
    // close unwanted ends
    close(pipe1[0]); 
    close(pipe2[1]); 
    // pipe1 is used for writing to parent process
    // pipe2 is used for reading from parent process
    
    int cR_status = read(pipe2[0], str, sizeof(str));
    
    // Reading from pipe2 on failure 
    if(cR_status == -1) {
        printf("Reading from parent process failed..\n");
        return;
    }
    printf("\n\nIN CHILD PROCESS: \n");
    printf("Reading from parent process is successful..\n");
    printf("Read from Parent Process: %s\n", str);
    stringReverse();
    printf("modified string in child process: %s\n", str);
    
    // writing the reversed string to parent process..
    int cW_status = write(pipe1[1],str,sizeof(str));
    
    // writing from pipe1 on failure
    if(cW_status == -1) {
        printf("Writing to parent process is failed..\n");
        return;
    }
    printf("Successfully written to parent process..\n");
    
}

void parentProcess(int pipe1[2], int pipe2[2])
{
    // close unwanted ends
    close(pipe1[1]); 
    close(pipe2[0]); 
    // pipe2 is used for writing to child process
    // pipe1 is used for reading from child process
    
    printf("\n\nIN PARENT PROCESS: \n");
    printf("Enter a string [20 chars max]: ");
    scanf("%s", str);
    
    int pW_status = write(pipe2[1], str, sizeof(str));
    if(pW_status == -1) {
        printf("Writing to child process failed..\n");
        return;
    }
    printf("Written successfully to child process..\n");
    
    // reading from child process
    int pR_status = read(pipe1[0], str, sizeof(str));
    
    // reading from child process on failure
    if(pR_status == -1) {
        printf("Reading from child process failed..\n");
        return;
    }
    printf("\n\nIN PARENT PROCESS: \n");
    printf("Reading from child process is successful..\n");
    printf("Read from child process [REVERSED STRING]: %s\n", str);
}

int main()
{
    int pipe1[2];
    int pipe2[2];
    int returnStatus1, returnStatus2;
    int pid;
    
    returnStatus1 = pipe(pipe1);
    // creation of pipe1 on failure
    if(returnStatus1 == -1) {
        printf("Error in creating pipe..\n");
        return -1;
    }
    
    returnStatus2 = pipe(pipe2);
    // creation of pipe2 on failure
    if(returnStatus2 == -1) {
        printf("Unable to create pipe..\n");
        return -1;
    }
    
    pid = fork();
    if(pid == 0)
        childProcess(pipe1, pipe2);
    else if(pid < 0)
        printf("Unable to create child process..\n");
    else
        parentProcess(pipe1, pipe2);
    return 0;
}