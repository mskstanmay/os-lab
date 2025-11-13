#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat s;
    stat("test.txt", &s);
    printf("File size: %ld bytes\n", s.st_size);
    return 0;
}
