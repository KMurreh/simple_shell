#include "shell.h"

#include <stdio.h>
#include <stdlib.h>
#include "environ.h"

/**
 * print_environment - Prints the current environment
 *
 * Description: Prints the environment variables of the current process.
 * Return: Does not return a value
 */
void print_environment(void)
{
int i;

for (i = 0; environ[i] != NULL; i++)
{
printf("%s\n", environ[i]);
}
}

/**
 * main - Entry point of the program
 *
 * Description:Prints current environment using the print_environment function.
 * Return: Always 0
 */
int main(void)
{
print_environment();

return (0);
}
