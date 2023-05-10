#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

/**
 * main - Entry point of the program.
 * Return: 0 on success.
 */
int main(void)
{
    char buffer[BUFFER_SIZE];
    char *command;

    while (1) {
        // Display prompt
        printf("$ ");
        fflush(stdout);

        // Read input
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            printf("\n");
            break;
        }

        // Remove trailing newline
        buffer[strcspn(buffer, "\n")] = '\0';

        // Parse command
        command = strtok(buffer, " ");

        if (command == NULL) {
            continue;
        }

        // Check if command exists
        if (access(command, F_OK) == -1) {
            printf("%s: command not found\n", command);
            continue;
        }

        // Create child process
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // Child process
            char *argv[] = {command, NULL};
            execve(command, argv, environ);
            perror("execve");
            exit(1);
        } else {
            // Parent process
            int status;
            wait(&status);
        }
    }

    return 0;
}
