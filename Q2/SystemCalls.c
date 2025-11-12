#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void process_control();
void file_stat(const char *filename);
void list_directory(const char *path);
void copy_file(const char *source, const char *destination);

int main()
{
    process_control();
    file_stat("main.txt");
    list_directory(".");
    copy_file("main.txt", "backup.txt");
    return 0;
}

void process_control()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("Child: Hello!\n");
        char *args[] = {"/bin/echo", "Executed with exec", NULL};
        execvp(args[0], args);
        perror("Execution failed");
        exit(1);
    }
    else
    {
        wait(NULL);
        printf("Parent: Child has finished \n");
    }
}

void file_stat(const char *filename)
{
    struct stat st;
    if (stat(filename, &st) == 0)
    {
        printf("FIle size is %ld bytes\n", st.st_size);
    }
    else
    {
        perror("Stat failed");
    }
}

void list_directory(const char *path)
{
    DIR *dir = opendir(path);
    if (dir)
    {
        printf("COntents of directory '%s': \n", path);
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            printf("- %s \n", entry->d_name);
        }
        closedir(dir);
    }
    else
    {
        perror("Opendir failed");
    }
}

void copy_file(const char *source, const char *destination)
{
    int fd = open(source, O_RDONLY);
    if (fd < 0)
    {
        perror("Open source failed");
        return;
    }
    char buf[100];
    int n = read(fd, buf, sizeof(buf) - 1);
    if (n > 0)
    {
        buf[n] = '\0';
        printf("Contents of '%s':\n%s\n", source, buf);
        int out = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (out < 0)
        {
            perror("Open destination failed");
            close(fd);
            return;
        }
        write(out, buf, n);
        close(out);
        printf("Copied t '%s' \n", destination);
    }
    else
    {
        perror("read failed");
    }
    close(fd);
}
