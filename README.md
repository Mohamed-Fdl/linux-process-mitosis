# Linux process mitosis

In this project I briefly explore how linux processes can make request to the OS to lauch another process.

We have fork() syscall which allow us to have an exact copy of the original proccess.
On the other hand we have execve() syscall which allow to replace the execution of one process with another.

So when a process want to lauch another one, it starts by forking to get a copy of itself and that copy then call execve to replace itself with the wanted process.

## Cloning process using fork()

```c
int main()
{
    printf("Hello, World!\n");

    for (int i = 0; i <= 6; i++)
    {
        printf("Here: %i\n", i);
    }

    int pid = fork();
    printf("Forked Pid: %i\n", pid);

    for (int i = 0; i <= 4; i++)
    {
        printf("After forking: %i\n", i);
    }

    return 0;
}

```

## Replacing process using execve()

```c
int main()
{
    printf("Hello, World!, pid: %d\n", getpid());

    for (int i = 0; i <= 6; i++)
    {
        printf("Here: %i\n", i);
    }

    printf("\n");

    char *const args[] = {"ls", "-l", "/tmp", NULL};
    char *const env[] = {"CUSTOM_VAR=hello", NULL};
    execve("/bin/ls", args, env);

    for (int i = 0; i <= 4; i++)
    {
        printf("After calling execve: %i\n", i);
    }

    return 0;
}

```

## Launching a new process via another using fork() and execve()

We have to note that fork return 0 when it is the child process and the process id when it is the parent process.
So we can check this return to decide if the process can replace itself with execve or not.

Check main.c to see the example.
