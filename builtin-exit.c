#include <stdio.h>
#include <stdlib.h>

/**
 *exit_shell - Exits the shell
 *
 *Description: Terminates the shell program.
 *Return: Does not return a value
 */
void exit_shell(void)
{
exit(EXIT_SUCCESS);
}
/**
 *main - Entry point of the program
 *
 *Description: Displays a prompt, reads user commands, and executes them.
 *              Supports the built-in exit command to exit the shell.
 *Return: Always 0
 */
int main(void)
{
char command[100];

while (1)
{
printf("$ "); /* Display prompt */
scanf("%s", command);

if (strcmp(command, "exit") == 0)
{
exit_shell();
}
else
{
printf("Invalid command\n");
}
}

return (0);
}
