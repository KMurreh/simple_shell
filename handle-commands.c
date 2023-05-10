#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024

/**
 * execute_command - Execute a single command.
 * @command: The command to execute.
 * Return: 0 on success, -1 on failure.
 */
int execute_command(const char *command)
{
    // Implement your code to execute the command here
    printf("Executing command: %s\n", command);
    return 0;
}

/**
 * handle_commands - Handle commands separated by ";".
 * @commands: The commands string.
 * Return: 0 on success, -1 on failure.
 */
int handle_commands(const char *commands)
{
    char *command;
    char *commands_copy = strdup(commands);
    if (commands_copy == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return -1;
    }

    command = strtok(commands_copy, ";");
    while (command != NULL) {
        if (execute_command(command) != 0) {
            free(commands_copy);
            return -1;
        }
        command = strtok(NULL, ";");
    }

    free(commands_copy);
    return 0;
}

/**
 * main - Entry point of the program.
 * Return: 0 on success.
 */
int main(void)
{
    const char *commands = "command1 ; command2 ; command3";

    if (handle_commands(commands) != 0) {
        return 1;
    }

    return 0;
}
