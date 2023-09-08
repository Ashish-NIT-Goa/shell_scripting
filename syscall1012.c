#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// this function opens the file, reads it, and prints it to the standard output
void typefile(char* filename){ // takes a filename as an argument
    int fd, nread; // file descriptor and number of bytes read
    int fd2, nread2;
    char buf[1024]; // buffer to read into
    fd = open(filename, O_RDONLY); // open the file
    fd2 = open(filename2, 
    if (fd == -1){ // if the file descriptor is -1, there was an error
        perror(filename); // print the error
        return;
    }
    while ((nread = read(fd, buf, sizeof(buf))) > 0){ // read the file into the buffer
        write(1, buf, nread); // write the buffer to the standard output
    }
    close(fd); // close the file
}

// this function loops through the command line arguments and calls `typefile` on each one
int main(int argc, char **argv){ // takes the number of arguments and the arguments themselves
    int argno = 0; // argument number
    for (argno = 1; argno < argc; argno++){ // loop through the arguments
        typefile(argv[argno]); // call `typefile` on each argument
    }
    return 0;
}

/*
This code is a C program that takes command line arguments, opens each file specified in the arguments,
and prints the contents of each file to the standard output.
The `typefile` function is responsible for opening and reading the file, 
while the `main` function loops through the command line arguments and calls `typefile` on each one.
*/
