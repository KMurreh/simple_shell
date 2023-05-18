#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_VARIABLE_LENGTH 20

/**
 * handle_variable_replacement - Replaces "$?" and "$$" variables in command.
 * @command: The command string to modify.
 */
void handle_variable_replacement(char *command)
{
char *variable;
char *value;
char *replacement;
char temp[MAX_COMMAND_LENGTH];

/* Replace "$?" with the return code of the last command */
variable = "$?";
value = "0";  /* Assuming last command was successful */
replacement = strstr(command, variable);
while (replacement != NULL)
{
strcpy(temp, replacement + strlen(variable));
sprintf(replacement, "%d%s", atoi(value), temp);
replacement = strstr(command, variable);
}

/* Replace "$$" with the process ID of the shell */
variable = "$$";
value = (char *)malloc(MAX_VARIABLE_LENGTH * sizeof(char));
sprintf(value, "%d", getpid());
replacement = strstr(command, variable);
while (replacement != NULL)
{
strcpy(temp, replacement + strlen(variable));
sprintf(replacement, "%s%s", value, temp);
replacement = strstr(command, variable);
}

free(value);
}

/**
 * main - Main function.
 * Return: Returns 0 upon successful execution.
 */
int main(void)
{
char command[MAX_COMMAND_LENGTH];

/* Example command */
strcpy(command, "echo $? $$");

/* Handle variable replacement */
handle_variable_replacement(command);

/* Print the modified command */
printf("Modified Command: %s\n", command);

return (0);
}
