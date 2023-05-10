#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * @envp: An array of environment variable strings.
 * Return: 0 on success.
 */
int main(int argc, char *argv[], char *envp[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    char *path = getenv("PATH");
    char *token, *path_entry;
    char command_path[MAX_PATH_LENGTH];

    if (path == NULL) {
        fprintf(stderr, "PATH environment variable not found\n");
        return 1;
    }

    // Tokenize the PATH variable to get individual directories
    token = strtok(path, ":");
    while (token != NULL) {
        // Check if the command exists in each directory
        snprintf(command_path, sizeof(command_path), "%s/%s", token, command);
        if (access(command_path, X_OK) == 0) {
            // Command found, execute it
            execve(command_path, argv + 1, envp);
            perror("execve");
            return 1;
        }
        token = strtok(NULL, ":");
    }

    fprintf(stderr, "%s: command not found\n", command);
    return 1;
}
