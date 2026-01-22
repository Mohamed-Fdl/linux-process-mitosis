#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Hello, World!, pid: %d\n", getpid());

    for (int i = 0; i <= 6; i++)
    {
        printf("Here: %i\n", i);
    }

    int pid = fork();
    printf("Fork Pid: %i\n", pid);
    if (pid == 0)
    {
        char *const args[] = {"ls", "-l", "/tmp", NULL};
        char *const env[] = {"CUSTOM_VAR=hello", NULL};
        execve("/bin/ls", args, env);
    }

    printf("\n");

    for (int i = 0; i <= 4; i++)
    {
        printf("After calling execve: %i\n", i);
    }

    return 0;
}
