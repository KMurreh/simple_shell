#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _getline - Reads a line from input.
 * @lineptr: Pointer to the buffer storing the line.
 * Return: Number of characters read, or -1 on failure.
 */
ssize_t _getline(char **lineptr)
{
    static char buffer[BUFFER_SIZE];
    static ssize_t buffer_pos = 0;
    static ssize_t bytes_read = 0;

    ssize_t i, bytes_to_read, total_bytes = 0;
    char *line;

    if (lineptr == NULL)
        return -1;

    line = *lineptr;

    if (buffer_pos >= bytes_read) {
        bytes_to_read = read(STDIN_FILENO, buffer, sizeof(buffer));
        if (bytes_to_read <= 0)
            return -1;
        buffer_pos = 0;
        bytes_read = bytes_to_read;
    }

    for (i = buffer_pos; i < bytes_read; i++) {
        if (buffer[i] == '\n') {
            line[total_bytes] = '\0';
            buffer_pos = i + 1;
            return total_bytes;
        }

        line[total_bytes] = buffer[i];
        total_bytes++;

        if (total_bytes >= BUFFER_SIZE - 1) {
            line[total_bytes] = '\0';
            return total_bytes;
        }
    }

    line[total_bytes] = '\0';
    buffer_pos = i;
    return total_bytes;
}

/**
 * main - Entry point of the program.
 * Return: 0 on success.
 */
int main(void)
{
    char *line = NULL;
    size_t line_size = 0;
    ssize_t chars_read;

    printf("Enter a line: ");

    chars_read = _getline(&line);
    if (chars_read == -1) {
        printf("Failed to read input.\n");
        return 1;
    }

    printf("You entered %zd characters: %s\n", chars_read, line);

    free(line);
    return 0;
}
