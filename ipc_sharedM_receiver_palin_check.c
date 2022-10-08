// CS20B1031 -Daathwinaagh
// Palindrome check via shared memory [reciever side]

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
#include<stdbool.h>

// function to detect whether string is plaindrome or not
bool checkPalindrome(char *s, int size)
{
    int low = 0;
    int high = size-1;
    while(low <= high)
    {
        if(s[low]!=s[high]) return false;
        low++; high--;
    }
    return true;
}

int main()
{
    int i;
    void *shared_mem;
    char buff[100];
    int shmid;
    
    // creates shared memory, at id, atleast 100bytes, with all permissions
    shmid = shmget((key_t)17022002, 100, 0666|IPC_CREAT);
    
    // on a failure case
    if (shmid == -1) {
        printf("Error detected in creating shared memory..\n");
        return -1;
    }
    
    printf(">> shared mem key: [%d]\n", shmid);
    shared_mem = shmat(shmid, NULL, 0);
    
    // copying shared memory string to buffer
    strcpy(buff, (char *)shared_mem);
    
    printf("Recieved string: %s\n", buff);
    
    // checking whether palindrome or not
    if(checkPalindrome(buff, strlen(buff)))
    {
        memcpy(shared_mem, "1", 1); // 1 is added if palindrome
    } else {memcpy(shared_mem, "0", 1);} // else 0 is added if not
    
    printf("Please go to sender to check..\n");
    return 0;
}