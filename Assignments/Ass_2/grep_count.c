// program to find the count of a pattern in a file using grep

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {

    char command[MAX_BUF_SIZE];
    char result[MAX_BUF_SIZE];
    
    char *pattern = argv[1];
    char *filename = argv[2];
    FILE *fp;

    // construct the grep command
    snprintf(command, sizeof(command), "grep -c %s %s", pattern, filename);

    // execute the command and capture its output
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to execute command\n");
        exit(1);
    }

    // read the output of the command
    fgets(result, sizeof(result), fp);

    // close the pipe
    pclose(fp);

    // print the result
    printf("The pattern '%s' appears %s times in the file '%s'\n", pattern, result, filename);

    return 0;
}