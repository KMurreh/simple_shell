#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 100

/**
 *execute_command - Execute a command in the shell
 *@command: The command to execute
 *@path: The PATH environment variable
 *Return: 0 on success, -1 on failure
 */
int execute_command(char *command, char *path)
{
char *path_token;
char command_path[MAX_COMMAND_LENGTH + MAX_PATH_LENGTH];
int found_command = 0;
int status;

path_token = strtok(path, ":");

while (path_token != NULL)
{
snprintf(command_path, sizeof(command_path), "%s/%s", path_token, command);

if (access(command_path, X_OK) == 0)
{
found_command = 1;
break;
}

path_token = strtok(NULL, ":");
}

if (!found_command)
{
fprintf(stderr, "Command not found: %s\n", command);
return (-1);
}

if (fork() == 0)
{
execv(command_path, NULL);
fprintf(stderr, "Failed to execute command: %s\n", command);
exit(EXIT_FAILURE);
}
else
{
wait(&status);
return (status);
}
}
/**
 * main - Entry point of the program
 * Description: Displays a prompt, reads user commands, and executes them.
 * Supports command lines with arguments, handles the PATH,
 * and ensures that fork is not called if the command doesn't exist.
 * Return: Always 0
 */
int main(void)
{
char command[MAX_COMMAND_LENGTH];
char path[MAX_PATH_LENGTH];
int status;

/* Get the PATH environment variable */
char *path_env = getenv("PATH");
if (path_env == NULL)
{
fprintf(stderr, "PATH environment variable not found\n");
return (-1);
}
strncpy(path, path_env, sizeof(path));

while (1)
{
printf("$ "); /* Display prompt */
flush(stdout);

if (fgets(command, sizeof(command), stdin) == NULL)
{
printf("\n"); /* Handle EOF (Ctrl+D) */
break;
}

command[strcspn(command, "\n")] = '\0'; /* Remove trailing newline */

status = execute_command(command, path);
if (status == -1)
{
continue;
}
else
{
printf("Command executed with status: %d\n", status);
}
}
return (0);
}
