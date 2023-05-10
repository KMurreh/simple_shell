#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * exit_shell - Exits the shell.
 */
void exit_shell(void)
{
    printf("Exiting the shell...\n");
    exit(0);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    char buffer[1024];

    while (1) {
        printf("$ ");
        fflush(stdout);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("\n");
            exit_shell();
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "exit") == 0) {
            exit_shell();
        } else {
            // Handle other commands...
            printf("Command not recognized\n");
        }
    }

    return 0;
}
