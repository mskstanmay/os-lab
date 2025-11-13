#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0)
        printf("Child process\n");
    else
        printf("Parent process, child PID = %d\n", pid);

    return 0;
}
