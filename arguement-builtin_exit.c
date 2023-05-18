#include <stdio.h>
#include <stdlib.h>

/**
 * main - Exits the shell with the specified status
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Description: This program is a shell that supports a built-in exit command.
 *              The command allows the user to exit the shell with a specific
 *              status code. The status code is provided as an argument to the
 *              exit command.
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
int status = 0;

if (argc > 1)
{
status = atoi(argv[1]);
}

exit(status);
}
