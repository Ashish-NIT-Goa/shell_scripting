#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <substring> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *substring = argv[1];
    const char *filename = argv[2];

    // Construct the grep command using snprintf()
    char command[256];
    snprintf(command, sizeof(command), "grep -o %s %s | wc -l", substring, filename);

    // Execute the command using popen()
    FILE *pipe = popen(command, "r");
    if (!pipe) {
        perror("popen");
        return EXIT_FAILURE;
    }

    // Read the output of the command
    char output[16];
    if (!fgets(output, sizeof(output), pipe)) {
        perror("fgets");
        return EXIT_FAILURE;
    }

    // Convert the output to an integer
    int count = atoi(output);

    printf("Number of occurrences of '%s' in '%s': %d\n", substring, filename, count);

    // Close the pipe and return
    pclose(pipe);
    return EXIT_SUCCESS;
}
