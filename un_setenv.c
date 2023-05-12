#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Description: program implements the setenv and unsetenv built-in commands.
 *              setenv command is used to initialize new environment variable
 *              or modify existing one. the two arguments: the variable name
 *              and its value. The unsetenv command removes an environment
 *              variable. and takes one argument: the variable name.
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
if (argc < 2)
{
fprintf(stderr, "Usage %s VARIABLE VALUE (setenv) or %s VARIABLE (unsetenv)\n",
argv[0], argv[0]);
exit(1);
}

if (strcmp(argv[1], "setenv") == 0)
{
if (argc != 4)
{
fprintf(stderr, "Usage: %s setenv VARIABLE VALUE\n", argv[0]);
exit(1);
}
if (setenv(argv[2], argv[3], 1) != 0)
{
fprintf(stderr, "Failed to set environment variable\n");
exit(1);
}
}
else if (strcmp(argv[1], "unsetenv") == 0)
{
if (argc != 3)
{
fprintf(stderr, "Usage: %s unsetenv VARIABLE\n", argv[0]);
exit(1);
}

if (unsetenv(argv[2]) != 0)
{
printf(stderr, "Failed to unset environment variable\n");
exit(1);
}
}
else
{
fprintf(stderr, "Unknown command: %s\n", argv[1]);
exit(1);
}
return (0);
}
