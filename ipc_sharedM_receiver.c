// CS20B1031 -Daathwinaagh
// Inter process communication via shared memory(reciever size)

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
    int i;
    void *shared_mem;
    char buffer[100];
    int shmid;
    
    // creates shared mem at that id, atlease 100 bytes with all users permission
    shmid = shmget((key_t)1810113862, 100, 0666|IPC_CREAT);
    
    // on a failure case
    if(shmid == -1) {
        printf("Error occured in creating shared memory..\n");
        return -1;
    }
    
    printf(">> shared memory key: [%d]\n", shmid);
    
    // connecting the shared memory with the process`s address space
    shared_mem = shmat(shmid, NULL, 0);
    
    printf(">> Process attached at [%p]\n", shared_mem);
    
    printf("Data read from shared mem: %s\n", (char *)shared_mem);
    read(0, buffer, 100); // storing data in buffer string
    
    strcpy(shared_mem, buffer); // copying into shared memory
    printf(">> Data sent..\n");
    return 0;
} 