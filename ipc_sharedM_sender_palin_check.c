// CS20B1031 -Daathwinaagh
// Palindrome check via shared memory ( sender side)

#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int i;
    void *shared_mem;
    char buff[100];
    int shmid;
    
    // creates shared memory at id, with atleast 100 bytes, 
    shmid = shmget((key_t)17022002, 100, 0666|IPC_CREAT);
    
    // on failure case
    if(shmid == -1) {
        printf("Error occured in creating shared memory..\n");
        return -1;
    }
    
    printf(">> shared mem key: [%d]\n", shmid);
    
    // connects shared memory to the address of this process
    shared_mem = shmat(shmid, NULL, 0);
    
    printf(">> Process attached at [%p]\n",shared_mem);
    scanf("%s", buff);
    getchar();
    
    // copying into shared memory
    strcpy(shared_mem, buff);
    printf("Please enter any charecter after executing [reciever code]: ");
    getchar();
    
    strcpy(buff, shared_mem);
    printf("Data read abt string in shared mem [%c]\n", buff[0]);
    return 0;
}