#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>

int main(int argno,char **argv) {
    int fd,nread;

    // Open the file for reading
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    // Try to acquire a read lock
    if (flock(fd, LOCK_SH) == -1) {
        perror("Error acquiring lock");
        close(fd);
        exit(1);
    }
    else
    {
        printf("lock acquired \n");
    }

    // Read and print data from the file
    char buf[1024];
nread=read(fd,buf,sizeof(buf));
while(nread > 0){
write(1,buf,nread);
nread=read(fd,buf,sizeof(buf));
}
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
