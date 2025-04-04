# I. File Management
1. Creating Different File Types: Utilize both shell commands and system calls to create the following types of files:
a. soft link (using the symlink system call)
b. hard link (using the link system call)
c. FIFO (using either the mkfifo Library Function or the mknod system call)
2. Background Process Exploration: Develop a simple program to execute indefinitely in the background. Traverse the /proc directory and extract relevant process information from the corresponding proc directories.
3. File Creation and Descriptor Printing: Write a program that creates a file and prints its file descriptor value using the creat() system call.
4. Opening Existing File: Write a program to open an existing file in read-write mode. Experiment with the O_EXCL flag.
5. Continuous File Creation: Create a program that generates five new files in an infinite loop. Execute the program in the background and inspect the file descriptor table at /proc/pid/fd.
6. Input and Output Using System Calls: Craft a program to take input from STDIN and display it on STDOUT using only read/write system calls.
7. File Copying: Develop a program to copy the contents of file1 into file2, emulating the behavior of the $cp file1 file2 command.
8. Read-Only File Reading: Write a program to open a file in read-only mode, read line by line, and display each line as it is read. Close the file upon reaching the end of the file.
9. File Information Extraction: Create a program to print various details about a given file, including:
a. Inode
b. Number of hard links
c. UID
d. GID
e. Size
f. Block size
g. Number of blocks
h. Time of last access
i. Time of last modification
j. Time of last change
10. File Write and Seek: Implement a program to open a file in read-write mode, write 10 bytes, move the file pointer by 10 bytes using lseek, and then write another 10 bytes.
a. Check the return value of lseek.
b. Open the file with od command and examine the empty spaces between the data.
11. File Descriptor Duplication and Appending: Write a program to open a file, duplicate the file descriptor, append the file with both descriptors, and verify whether the file is updated correctly.
a. Use dup
b. Use dup2
c. Use fcntl
12. Determining Opening Mode of a File: Create a program to find out the opening mode of a file using the fcntl system call.
13. Waiting for STDIN Using Select: Develop a program to wait for input from STDIN for 10 seconds using select. Include proper print statements to verify data availability within the specified time.
14. File Type Identification: Write a program that takes input from the command line and identifies the type of file. Ensure the program can recognize various file types.
15. Displaying User Environmental Variables: Create a program to display the environmental variables of the user, utilizing the environ variable.
16. Mandatory Locking Implementation: Write a program to perform mandatory locking with the following implementations:
a. Implement a write lock.
b. Implement a read lock.
17. Online Ticket Reservation Simulation: Develop a program to simulate online ticket reservation with the implementation of a write lock. Write one program to open a file, store a ticket number, and exit. Write a separate program to open the file, implement a write lock, read the ticket number, increment the number, print the new ticket number, and then close the file.
18. Record Locking Implementation: Write a program to perform record locking with the following implementations:
a. Implement a write lock.
b. Implement a read lock.
Create three records in a file. Whenever you access a particular record, first lock it, then modify/access it to avoid race conditions
# II. Process Management
19. Process States: Develop a program to initiate a process in distinct states:
a. running
b. sleeping
c. stopped
Confirm the current state of the process using the relevant commands.
20. Printing Parent and Child Process IDs: Write a program that calls fork and prints both the parent and child process IDs.
21. File Writing by Parent and Child Processes: Develop a program that opens a file, calls fork, and allows both the child and parent processes to write to the file. Examine the output of the file.
22. Creating a Zombie State: Write a program to create a zombie state in the running program.
23. Creating an Orphan Process: Develop a program to create an orphan process.
24. Creating and Waiting for Child Processes: Write a program to create three child processes. The parent process should wait for a specific child process using the waitpid system call.
25. Executing an Executable Program:
a. Execute a program using the exec system call.
b. Pass input to an executable program (e.g., execute an executable as $./a.out name).
26. Executing ls -Rl Using Various exec System Calls: Write a program to execute ls -Rl using the following system calls:
a. execl
b. execlp
c. execle
d. execv
e. execvp
27. Getting Maximum and Minimum Real-Time Priority: Develop a program to retrieve the maximum and minimum real-time priority.
28. Determining and Modifying Program Priority: Find out the priority of your running program and modify it using the nice command.
29. Getting and Modifying Scheduling Policy: Write a program to obtain the scheduling policy and modify it (e.g., SCHED_FIFO, SCHED_RR).
30. Running a Script at a Specific Time with a Daemon Process: Create a program to execute a task at a specific time using a Daemon process.
