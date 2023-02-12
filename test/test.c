#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
    char cmd[80];

    while (1)
    {
        printf("$");

        fgets(cmd, sizeof(cmd), stdin);
    
    int len = strlen(cmd);
    if (cmd[len - 1] == '\n')
        cmd[len -1] = 0;
    if (len == 0)
        continue;
    
    char *c[] = {"/bin/ls", "/usr", NULL};

    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        execve(c[0], c, NULL);
        perror(" ");
        exit (1);
    }
    else
    {
        waitpid(pid, NULL, 0);
    }

    }
}