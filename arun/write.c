// program to lock a file in write mode

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>

int main(int argno,char **argv) {
    int fd;

    fd = open(argv[1], O_WRONLY | O_CREAT, 0644);

    if (fd == -1) {
        perror("Error opening the file");
        exit(1);
    }

    if (flock(fd, LOCK_EX) == -1) {
        perror("Error acquiring lock");
        close(fd);
        exit(1);
    } else {
        printf("lock acquired\n");
    }

    write(fd, "hello world", 12);
    getchar();

    if (flock(fd, LOCK_UN)==-1) {
        perror("Error releasing the file\n");
    } else {
        printf("Released successfully\n");
    }

    close(fd);

    return 0;
}