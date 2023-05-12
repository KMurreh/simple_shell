#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

/**
 *execute_command - Execute a command in the shell
 *@command: The command to execute
 *Return: 0 on success, -1 on failure
 */
int execute_command(char *command)
{
int status;
pid_t pid;

pid = fork();
if (pid == -1)
{
perror("fork");
return (-1);
}
else if (pid == 0)
{
/* Child process */
if (execve(command, NULL, environ) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
/* Parent process */
do {
if (waitpid(pid, &status, 0) == -1)
{
perror("waitpid");
return (-1);
}
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

return (0);
}
/**
 *main - Entry point of the program
 *Return: Always 0
 */
int main(void)
{
char command[MAX_COMMAND_LENGTH];

while (1)
{
printf("$ "); /* Display prompt */
fflush(stdout);

if (fgets(command, sizeof(command), stdin) == NULL)
{
printf("\n"); /* Handle EOF (Ctrl+D) */
break;
}

command[strcspn(command, "\n")] = '\0'; /* Remove trailing newline */

if (execute_command(command) == -1)
{
fprintf(stderr, "Failed to execute command\n");
continue;
}
}

return (0);
}
