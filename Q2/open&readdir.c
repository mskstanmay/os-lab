#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *d = opendir(".");
    struct dirent *f;

    while ((f = readdir(d)) != NULL)
        printf("%s\n", f->d_name);

    closedir(d);
    return 0;
}
