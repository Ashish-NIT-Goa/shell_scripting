
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

void copy_content(char *f1,char *f2) {
    int fd1;
    int fd2;
    int nread;
    char buf[1024];
    fd1=open(f1,O_RDONLY);
    fd2=open(f2,O_WRONLY);
    if(fd1==-1 || fd2==-1) {
        perror(f1);
        perror(f2);
        return;
    }
    nread=read(fd1,buf,sizeof(buf));
    while(nread > 0) {
        write(fd2,buf,nread);
        nread=read(fd1,buf,sizeof(buf));
    }
    printf("Successfully copied.");
    close(fd2);
    close(fd1);
}

int main( int argc,char **argv) {
    int argno=0;
    char *file1;
    char *file2;
    file1=argv[1];
    file2=argv[2];
    copy_content(file1,file2);
}