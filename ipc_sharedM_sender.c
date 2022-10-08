// CS20B1031 - Daathwinaagh
// Inter process communication via shared memory (sender side)

#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

int main()
{
    int i;
    void *shared_mem;
    char buffer[100];
    int shmid;
    
    shmid = shmget((key_t)1810113862, 100, 0666|IPC_CREAT);
    
    // shmid on failure returns -1
    if(shmid == -1) {
        printf(">> Error occured in creating shared memory..\n");
        return -1;
    }
    
    printf(">> shared memory key: [%d]\n", shmid);
    
    // attaching the shared memory segment with the process
    shared_mem = shmat(shmid, NULL, 0);
    printf(">> Process attached at the address: [%p]\n", shared_mem);

    read(0, buffer, 100);   // reading into buffer string

    strcpy(shared_mem, buffer); // copy buffer string into shared memorysdf
    printf("Data sent\n");
    
    printf("Please enter any charecter after executing ./reciever code : ");
    getchar();
    printf("Data read from shared memory: %s\n", (char*)shared_mem);
    return 0;
}