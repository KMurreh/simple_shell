#include <stdio.h>
#include <string.h>

/* Function Declarations */
void execute_command(const char *command);

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
return (1);
}

FILE *file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
return (1);
}

char line[100];
while (fgets(line, sizeof(line), file) != NULL)
{
if (line[0] == '#')
continue; /* Skip comment lines */

line[strcspn(line, "\n")] = '\0'; /* Remove trailing newline character */

printf("Executing command: %s\n", line);
execute_command(line);
}

fclose(file);
return (0);
}

/**
 * execute_command - Executes the given command.
 * @command: The command to execute.
 */
void execute_command(const char *command)
{
/* Execute the command here */
/* Replace this with your desired command execution logic */

/* Example: Print the command output */
printf("Command output\n");
}
