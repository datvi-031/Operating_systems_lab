# Operating Systems Lab
University operating system course lab part

**Question 1:** 
Write a program to create multiple processes (up to 3/4 Levels) using fork() and display their process IDs (getpid()) and parent process ID (getppid()).<br>
**Solution** : [fork_intro.c](https://github.com/datvi-031/Operating_systems_lab/blob/main/fork_intro.c) <br><br>

**Question 2:** 
You are provided with a series of 1 to n (Take Input from User) natural numbers. Write a program where parent process will display the sum of the even numbers (EVEN_SUM) present between 1 to n and the child process will display the sum of odd numbers (ODD_SUM) present between 1 to n.<br><br>
NOTE: While Displaying the result, display the ID of Each Processes along with the result.<br>
**Solution** : [fork_intro2.c](https://github.com/datvi-031/Operating_systems_lab/blob/main/fork_intro2.c) <br><br>

**Question 3:** 
You are provided with 10 numbers (Input Given by User). Write a program where parent process will display the sorted sequence of those 10 numbers in ascending order whereas the child process will display the sorted sequence of those numbers in descending order.<br><br>
NOTE: Make sure that the descending order must be displayed before the ascending order.
<br>
**Solution** : [fork_intro3.c](https://github.com/datvi-031/Operating_systems_lab/blob/main/fork_intro3.c) <br><br>

**Question 4:** 
Write two programs (in exec1.c and exec2.c) to demonstrate the usage of exec() system call.
<br>
**Solution** : [exec_intro1.c](https://github.com/datvi-031/Operating_systems_lab/blob/main/exec_intro1.c) <br>
**Solution** : [exec_intro2.c](https://github.com/datvi-031/Operating_systems_lab/blob/main/exec_intro2.c) <br><br>

**Question 5:** 
Write two different programs (Sender and Receiver) in C to demonstrate IPC using shared memory. Process "Sender.c" will write atleast 100 bytes of data to the shared memory and process "Receiver.c" will read from the shared memory and displays it. Then, "Receiver.c" will write atleast 100 bytes of data to the same shared memory and  "Sender.c" will read and displays it. 
<br>
**Solution** : [ipc_sharedM_sender.c](https://github.com/datvi-031/Operating_systems_lab/blob/main/ipc_sharedM_sender.c) <br>
**Solution** : [ipc_sharedM_receiver.c](https://github.com/datvi-031/Operating_systems_lab/blob/main/ipc_sharedM_receiver.c) <br><br>

**Question 6:** 
Write two different programs (SenderNew and ReceiverNew) in C to demonstrate IPC using shared memory. 
Process "SenderNew.c" will sets-up a string (take input from user) and writes it on to the shared memory. 
"ReceiverNew.c" will read the string from the shared memory, checks whether the string is palindrome or not (in the same process itself) and writes either 0 (not palindrome) or 1 (palindrome) to the same shared memory. 
Then, "SenderNew.c" will read the number (0/1) and displays whether the input string given by the user is palindrome or not
<br>
**Solution** : [ipc_sharedM_sender_palin_check.c](https://github.com/datvi-031/Operating_systems_lab/blob/main/ipc_sharedM_sender_palin_check.c) <br>
**Solution** : [ipc_sharedM_receiver_palin_check.c](https://github.com/datvi-031/Operating_systems_lab/blob/main/ipc_sharedM_receiver_palin_check.c) <br><br>

**Question 7:** 
Write a program using pipe() and fork() in which parent process takes one string as input. The same is sent to the child using pipe1 and child will reverse it. After the reversing is complete, the child process will send it (reversed string) to parent process using pipe2. Subsequently, parent process will read the string and displays it.
<br>
**Solution** : [ipc_pipes_strReverse.c](https://github.com/datvi-031/Operating_systems_lab/blob/main/ipc_pipes_strReverse.c) <br><br>

**Question 8:** 
A parent process creates a child process and the child process creates a grandchild process. The parent creates a pipe that is shared between the parent and the child. The parent writes a message to the pipe and the child reads it from the pipe. The child creates another pipe which is shared between the child and the grandchild. Note that this pipe is not available to the parent and is not the same as the one shared by the parent and the child. The grandchild writes another message to the pipe and the child reads it from the pipe. After obtaining the two messages from the pipes, the child prints the difference in lengths of the two messages. Moreover, each of the three processes prints the PID of its respective parent process. The contents of the two messages must be taken as user inputs.
<br>
**Solution** : [ipc_pipes_parent_child_grandChild.c](https://github.com/datvi-031/Operating_systems_lab/blob/main/ipc_pipes_parent_child_grandChild.c) <br><br>

**Question 9:** 
Write a program to create five threads using pthread library. Find the sum of first 1000 numbers using five threads, where each thread can calculate sum of 200 numbers in each (parallel counting using threads).
<br>
**Solution** : [thread_intro.c](https://github.com/datvi-031/Operating_systems_lab/blob/main/thread_intro.c) <br><br>

**Question 10:** 
Write a program to create a thread. The thread prints numbers from 0 to n, where value of n is passed from the main process to the thread.
<br>
**Solution** : [thread_intro2.c](https://github.com/datvi-031/Operating_systems_lab/blob/main/thread_intro2.c) <br><br>

**Question 11:** 
Write a program to create a thread. The thread is created by passing an array which contains more than two integers as input from the main process. The two or more array elements will be added in the thread and will return the result to the main function. Finally, the main function will print the final sum.
<br>
**Solution** : [thread_intro3.c](https://github.com/datvi-031/Operating_systems_lab/blob/main/thread_intro3.c) <br><br>
