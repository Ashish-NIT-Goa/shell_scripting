// program to open a directory, read the contents and print the contents

#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
        
    DIR *d;

    struct dirent *ch;
    
    d = opendir(argv[1]);

    if (d == NULL) {
        printf("unable to open");
    } else {
        while ((ch = readdir(d)) != NULL) {
            printf("%s\n", ch -> d_name);
        }
        printf("\n");
        printf("Printed the contents of the directory\n");
    }

    closedir(d);

    return 0;
}