#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int fd[2];
    char buffer[50];
    pipe(fd);

    pid_t pid = fork();
    if(pid == 0){
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Child recieved: %s\n", buffer);
        close(fd[0]);
    } else {
        close(fd[0]);
        char msg[] = "Hello from parent!";
        write(fd[1], msg, strlen(msg)+1);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}

