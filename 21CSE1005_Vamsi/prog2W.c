#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>

int main(int argno,char **argv) {
    int fd;

    // Open the file for writing and create it if it doesn't exist
    fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    // Try to acquire a write lock
    if (flock(fd, LOCK_EX) == -1) {
        perror("Error acquiring lock");
        close(fd);
        exit(1);
    }
    else{
        printf("lock acquired\n");
    }
    // Write data to the file
    write(fd, "Hello, World!", 13);
    getchar();

    // Release the lock
    if(flock(fd, LOCK_UN)==-1)
    {
        perror("Error releasing file\n");
    }
    else
    {
        printf("Released successfully\n");
    }

    // Close the file
    close(fd);

    return 0;
}
