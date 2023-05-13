#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int execute_command(char **command);
int execute_subcommand(char **subcommand);

int execute_command(char **command)
{
int result = 1; /* Assume initial result as true */

while (*command != NULL)
{
if (*command[0] == '&' && *command[1] == '&')
{
command += 2; /* Skip '&&' operator */
continue;
}
else if (*command[0] == '|' && *command[1] == '|')
{
command += 2; /* Skip '||' operator */
break;
}

result = execute_subcommand(command);
command++;
}

return (result);
}

int execute_subcommand(char **subcommand)
{
pid_t pid = fork();

if (pid == 0)
{
/* Child process */
if (execvp(subcommand[0], subcommand) == -1)
{
perror("Execution failed");
exit(EXIT_FAILURE);
}
}
else if (pid < 0)
{
/* Fork failed */
perror("Fork failed");
exit(EXIT_FAILURE);
}
else
{
	/* Parent process */
int status;
waitpid(pid, &status, 0);

if (WIFEXITED(status))
{
if (WEXITSTATUS(status) != 0)
return (0); /* Subcommand failed */
}
else
return (0); /* Subcommand terminated abnormally */
}

return (1); /* Subcommand succeeded */
}

int main(void)
{
char *command[] = {"echo", "Hello", "&&", "ls", "non_existent_file", "||", "echo", "World", NULL};
int result = execute_command(command);

printf("Result: %s\n", result ? "True" : "False");

return (0);
}
