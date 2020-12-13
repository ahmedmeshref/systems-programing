# Final Project

## Problem Solved
You have been tasked  to develop a program for process creation and termination on a Linux platform. You are required to create multiple child processes to work under one parent process. In principle, child processes can do their own work independently or cooperatively to accomplish a task. In this assignment, these child processes simply print out a "hello” message together with their PIDs (process IDs) and exit. You should use fork() and wait() system calls to actualize this program.

Requirements: 

1. Take the number of child processes as an argument when the parent process creates child processes. This argument should be passed through a command line argument.

2. The parent process creates child processes and should print out an error message if creation fails. The parent process should also wait for all child processes to finish and then exit.

3. Each child process should print out a hello message together its PID and then exit.

4. Test with 2, 4, and 8 child processes.

5. Next, instead of creating multiple child processes of a parent process, you are asked to create a chain of processes. That is to say, the parent process will create one child and wait for it to finish, while the child creates its own child and wait for it as well, and so on. The last child created should print out the message and exit immediately so that its ancestors can finish too. Test your program with 2, 4, and 8 child processes again.

6. Develop a Makefile, to automate the compilation process.

7. Develop a shell script to automate the test process, i.e. to test with 2, 4, and 8 children processes for both versions of program automatically with this script.

## Run 
- Navigate to the project directory 

- From your terminal, run ```gcc processes.c -lpthread && ./a.out {NUMBER_OF_PROCESSES}``` 
OR 
Use the make file to compile and execute the file. 
- From your terminal, run ```make compile && make run```
> Note: make run passes a default number of process, 10. 

## Test 
> Note: all pre built tests are using default values of 2, 4, and 8 for the number of created processes.
- Navigate to the project directory 

- From your terminal, run ```./test_automation.c```
OR 
- From your terminal, run ```make compile && make test```

## Owner 
- [Ahmed Meshref](https://github.com/ahmedmeshref) 


