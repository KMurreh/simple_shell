#include <stdio.h>
#include <string.h>

#define MAX_ALIASES 100
#define MAX_ALIAS_LENGTH 50

/* Function Declarations */
void print_aliases(void);
void print_alias(const char *name);
void define_alias(const char *name, const char *value);

/* Global Variables */
char aliases[MAX_ALIASES][MAX_ALIAS_LENGTH];
char values[MAX_ALIASES][MAX_ALIAS_LENGTH];
int num_aliases = 0;

/**
 * main - Entry point of the simple_shell program.
 * @argc: The number of command line arguments.
 * @argv: An array of strings containing the command line arguments.
 *
 * Return: 0 on success, or exit status on failure.
 */
int main(int argc, char *argv[])
{
if (argc == 1)
{
print_aliases();
}
else if (argc == 2)
{
print_alias(argv[1]);
}
else
{
for (int i = 1; i < argc; i++)
{
char *name = strtok(argv[i], "=");
char *value = strtok(NULL, "=");

if (name != NULL && value != NULL)
{
define_alias(name, value);
}
}
}

return (0);
}

/**
 * print_aliases - Prints all the defined aliases.
 */
void print_aliases(void)
{
for (int i = 0; i < num_aliases; i++)
{
printf("%s='%s'\n", aliases[i], values[i]);
}
}

/**
 * print_alias - Prints the value of the specified alias.
 * @name: The name of the alias to print.
 */
void print_alias(const char *name)
{
for (int i = 0; i < num_aliases; i++)
{
if (strcmp(aliases[i], name) == 0)
{
printf("%s='%s'\n", aliases[i], values[i]);
return;
}
}
}

/**
 * define_alias - Defines an alias with the specified name and value.
 * If the alias already exists, its value is replaced with the new value.
 * @name: The name of the alias.
 * @value: The value of the alias.
 */
void define_alias(const char *name, const char *value)
{
for (int i = 0; i < num_aliases; i++)
{
if (strcmp(aliases[i], name) == 0)
{
strcpy(values[i], value);
return;
}
}

if (num_aliases < MAX_ALIASES)
{
strcpy(aliases[num_aliases], name);
strcpy(values[num_aliases], value);
num_aliases++;
}
else
{
fprintf(stderr, "Error: Maximum number of aliases reached\n");
}
}
