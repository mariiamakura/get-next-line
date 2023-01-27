#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static int current_line = 0; // static variable to keep track of current line

int main() {
    int fd;
    char *line;
    ssize_t bytes_read;
    int current_position = 0;

    // Open the file
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the line
    line = (char *)malloc(1024);
    if (line == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    // Read the file until the current line is reached
    while (current_line > 0) {
        bytes_read = read(fd, line, 1024);
        if (bytes_read == -1) {
            perror("Error reading file");
            exit(EXIT_FAILURE);
        }

        // Check for newline characters
        for (int i = 0; i < bytes_read; i++) {
            if (line[i] == '\n') {
                current_line--;
            }
        }

        current_position += bytes_read;
    }

    // Seek to the current position
    lseek(fd, current_position, SEEK_SET);

    // Read the current line
    bytes_read = read(fd, line, 1024);
    if (bytes_read == -1) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }

    // Print the line
    printf("%s", line);

    // Free the memory
    free(line);
    // Close the file
    close(fd);

    // Increment the current line
    current_line++;

    return 0;
}