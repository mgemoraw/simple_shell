# The Simple Shell Project
I know some of us don't usually go through the GENERAL section of the projects, to see what we are expected to learn, but it is usually a good practice.

Here are the GENERAL of the SIMPLE SHELL Project, go through it and familiarize yourself with what ever you are not sure of.
I encourage us to please study for the Simple Shell, at least try to solve 20% of the task yourself, and also try to read and understand at least 20% of the code you will copy. Don't focus on the deadline, rather on understanding the concepts, reach out to your peers, including me, if you need help.

## Who designed and implemented the original Unix operating system?
The original Unix operating system was designed and implemented by Ken Thompson and Dennis Ritchie at Bell Labs in the late 1960s and early 1970s.

## Who wrote the first version of the UNIX shell?
The first version of the Unix shell was written by Ken Thompson.

## Who invented the B programming language (the direct predecessor to the C programming language)?
The B programming language was invented by Ken Thompson.
## Who is Ken Thompson?
Ken Thompson is an American computer scientist and hacker who co-designed and implemented the original Unix operating system, wrote the first version of the Unix shell, and invented the B programming language.
## How does a shell work?
A shell is a program that provides a command-line interface for interacting with the operating system. The shell takes in commands from the user, interprets those commands, and then executes the corresponding actions by calling system calls or launching other programs.
## What is a pid and a ppid?
PID (Process ID) is a unique identifier assigned to each process by the operating system. PPID (Parent Process ID) is the PID of the parent process of a given process.
How to manipulate the environment of the current process?

In C, you can manipulate the environment of the current process using the "`environ`" global variable, which is a pointer to an array of strings representing the environment variables and their values. You can access and modify the values of environment variables using functions such as `getenv()`, `setenv()`, and `putenv()`.
## What is the difference between a function and a system call?
A function is a piece of code defined by the programmer, executed within the user process, and typically returns control to the calling process when it is finished. A system call is a request for service made by a user process to the operating system's kernel, typically to request access to a resource or perform a task that cannot be performed within the user process.
## How to create processes?
In C, you can create new processes using the fork() system call. The fork() system call creates a new process by duplicating the current process, and the new process (child process) and the original process (parent process) then continue executing independently.
## What are the three prototypes of main?
The three prototypes of main are:
```c
int main(void)
int main(int argc, char *argv[])
int main(int argc, char *argv[], char *envp[])
```
The first prototype has no arguments, the second has the arguments for the number of arguments and the array of argument strings, and the third has the arguments for the number of arguments, the array of argument strings, and the array of environment strings.
## How does the shell use the PATH to find the programs?
The shell uses the PATH environment variable to find the programs. The PATH is a list of directories separated by colons, and the shell searches each directory in the PATH in order until it finds the requested program.
## How to execute another program with the execve system call?
The execve system call is used in C programming to execute another program. This system call replaces the current process image with a new process image. The format of the execve system call is as follows: 
```c
execve(const char *path, char *const argv[], char *const envp[]).
``` 
Here, the path parameter is the path to the executable file that you want to run, argv is an array of arguments passed to the executable, and envp is an array of environment variables that should be passed to the new process.

How to suspend the execution of a process until one of its children terminates
A process can wait for one of its child processes to complete using the waitpid system call. The format of the waitpid system call is as follows:
```c
waitpid(pid_t pid, int *status, int options).
```
 Here, pid is the process ID of the child process that you want to wait for, status is a pointer to an integer that will hold the exit status of the child process, and options is an integer that specifies various options for the waitpid call.

## What is EOF / “end-of-file”?
EOF stands for End-Of-File, and it is a special marker used in input and output operations in C programming. It indicates that there is no more data to be read from a file, or no more data to be written to a file. In C, the EOF constant is defined in the stdio.h header file, and it is represented by the integer value -1. When reading from a file in C, if the read operation encounters the EOF marker, it will stop reading, and the return value will be EOF.

<p>
Never miss out on resources, opportunities to help you grow as a tech enthusiast.
</p>
<a href='#'>I regularly post them here, click the text below;
Twitter
LinkedIn
Find me on GitHub
</a>
If you love such materials, please follow to see more contents.
<code on>