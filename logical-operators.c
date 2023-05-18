#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/**
 * execute_command - Executes a single command.
 * @command: The command to execute.
 *
 * Return: 0 on success, or exit status on failure.
 */
int execute_command(char *command)
{
pid_t pid = fork();

if (pid == -1)
{
perror("fork");
return (1);
}
else if (pid == 0)  /* Child process */
{
/* Execute the command */
execlp(command, command, NULL);

/* If execlp fails, print an error and exit */
perror(command);
return (1);
}
else  /* Parent process */
{
int status;
wait(&status);
return (WIFEXITED(status) ? WEXITSTATUS(status) : (1));
}
}

/**
 * handle_logical_operators - Handles the logical operators && and ||.
 * @commands: The array of commands to execute.
 * @operators: The array of logical operators.
 * @num_commands: The number of commands.
 *
 * Return: 0 on success, or exit status on failure.
 */
int handle_logical_operators(char *commands[], char *operators[], int num_commands)
{
int i = 0;
int status;

while (i < num_commands)
{
int exit_status = execute_command(commands[i]);

if ((exit_status != 0 && strcmp(operators[i], "&&") == 0) ||
(exit_status == 0 && strcmp(operators[i], "||") == 0))
{
i += 2;  /* Skip the next command */
}
else
{
i++;  /* Move to the next command */
}
}

return (0);
}

/**
 * main - Entry point of the simple_shell program.
 * @argc: The number of command line arguments.
 * @argv: An array of strings containing the command line arguments.
 *
 * Return: 0 on success, or exit status on failure.
 */
int main(int argc, char *argv[])
{
if (argc < 2)
{
fprintf(stderr, "Usage: %s command1 [&& command2] [|| command3]\n", argv[0]);
return (1);
}

int num_commands = (argc - 1) / 2;

char *commands[num_commands];
char *operators[num_commands];

int i, j;
for (i = 0, j = 1; i < num_commands; i++, j += 2)
{
commands[i] = argv[j];
operators[i] = argv[j + 1];
}

return (handle_logical_operators(commands, operators, num_commands));
}
