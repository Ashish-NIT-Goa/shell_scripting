#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argno,char **argv) {
	int fd,nread;
    	fd = open(argv[1], O_RDONLY);

    	if (fd == -1) {
        	perror("Error opening file");
	        exit(1);
    	}

    	char buf[1024];
	nread=read(fd,buf,sizeof(buf));
	while(nread > 0){
		write(1,buf,nread);
		nread=read(fd,buf,sizeof(buf));
	}
    
    	close(fd);

    	return 0;
}