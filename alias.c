#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ALIASES 100
#define MAX_ALIAS_LENGTH 50

struct Alias {
char name[MAX_ALIAS_LENGTH];
char value[MAX_ALIAS_LENGTH];
};

struct Alias aliases[MAX_ALIASES];
int aliasCount = 0;

void print_aliases(void);
void print_alias(char *name);
void define_alias(char *name, char *value);

void print_aliases(void)
{
int i;
for (i = 0; i < aliasCount; i++)
{
printf("%s='%s'\n", aliases[i].name, aliases[i].value);
}
}

void print_alias(char *name)
{
int i;
for (i = 0; i < aliasCount; i++)
{
if (strcmp(name, aliases[i].name) == 0)
{
printf("%s='%s'\n", aliases[i].name, aliases[i].value);
return;
}
}
}

void define_alias(char *name, char *value)
{
int i;
for (i = 0; i < aliasCount; i++)
{
if (strcmp(name, aliases[i].name) == 0)
{
strcpy(aliases[i].value, value);
return;
}
}

if (aliasCount < MAX_ALIASES)
{
strcpy(aliases[aliasCount].name, name);
strcpy(aliases[aliasCount].value, value);
aliasCount++;
}
else
{
fprintf(stderr, "Reached maximum number of aliases.\n");
}
}

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
int i;
for (i = 1; i < argc; i++)
{
char *name = strtok(argv[i], "=");
char *value = strtok(NULL, "=");

if (name != NULL && value != NULL)
define_alias(name, value);
}
else
{
fprintf(stderr, "Invalid alias definition: %s\n", argv[i]
}
}
}

return (0);
}
