#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    char buffer[50];
    int n = read(fd, buffer, sizeof(buffer));

    int out = open("copy.txt", O_WRONLY | O_CREAT, 0644);
    write(out, buffer, n);

    close(fd);
    close(out);
    return 0;
}
