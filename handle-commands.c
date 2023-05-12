#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute_commands_separated_by_semicolon-commands separted by semicolon.
 *
 * Function prompts user to enter series of commands separated by semicolons.
 * Tokenizes input string using `strtok()`
 * executes commands in child process using 'system()'
 * parent process waits child processes to complete and checks the exit status.
 * If any command fails, it prints an error message.
 *
 * Return: 0 on success, or a non-zero value on failure.
 */
int execute_commands_separated_by_semicolon(void)
{
char input[4096];
char *command;
const char *separator = ";";

printf("Enter commands separated by semicolons:\n");
fgets(input, sizeof(input), stdin);

command = strtok(input, separator);
while (command != NULL)
{
pid_t pid = fork();

if (pid < 0)
{
perror("fork");
return (1);
}
else if (pid == 0)
{
system(command);
exit(0);
}
else
{
int status;
waitpid(pid, &status, 0);
if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
{
fprintf(stderr, "Command failed: %s\n", command);
return (1);
}
}

command = strtok(NULL, separator);
}

return (0);
}

/**
 * main - Entry point of the program.
 *
 * Function calls `execute_commands_separated_by_semicolon`.
 *
 * Return: Always returns 0.
 */
int main(void)
{
return (execute_commands_separated_by_semicolon());
}
