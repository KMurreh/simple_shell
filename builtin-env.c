#include <stdio.h>
#include <stdlib.h>

/**
 * print_environment - Prints the current environment.
 * @envp: The array of environment variable strings.
 */
void print_environment(char *envp[])
{
    int i = 0;
    while (envp[i] != NULL) {
        printf("%s\n", envp[i]);
        i++;
    }
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * @envp: An array of environment variable strings.
 * Return: 0 on success.
 */
int main(int argc, char *argv[], char *envp[])
{
    if (argc > 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    print_environment(envp);

    return 0;
}
