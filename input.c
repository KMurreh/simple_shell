#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_VARIABLE_LENGTH 20



/**
 * main - Entry point of the simple_shell program.
 * @argc: The number of command line arguments.
 * @argv: An array of strings containing the command line arguments.
 *
 * Return: 0 on success, or exit status on failure.
 */
int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
return (EXIT_FAILURE);
}

/* Open the file for reading */
FILE *file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
return (EXIT_FAILURE);
}

/* Read and execute commands from the file */
char command[MAX_COMMAND_LENGTH];
while (fgets(command, sizeof(command), file) != NULL)
{
/* Remove trailing newline character */
command[strcspn(command, "\n")] = '\0';

/* Execute the command */
if (execute_command(command) == -1)
{
fprintf(stderr, "Error executing command: %s\n", command);
fclose(file);
return (EXIT_FAILURE);
}
}

fclose(file);
return (EXIT_SUCCESS);
}
