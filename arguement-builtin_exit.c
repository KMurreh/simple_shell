#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * exit_shell - Exits the shell with the specified status.
 * @status: The exit status.
 */
void exit_shell(int status)
{
    printf("Exiting shell with status %d\n", status);
    exit(status);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [status]\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        int status = atoi(argv[1]);
        exit_shell(status);
    } else {
        exit_shell(0);
    }

    return 0;
}
