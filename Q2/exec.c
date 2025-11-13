#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec\n");
    execl("/bin/ls", "ls", NULL);
    printf("This will NOT print if exec succeeds\n");
    return 0;
}
