#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * Changes the current directory of the process.
 * Command syntax: cd [DIRECTORY]
 * If no argument is given to cd, the command is interpreted as cd $HOME.
 * Handles the command cd -
 * Updates the environment variable PWD when changing directory.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 * @return Returns 0 on success, or a non-zero value on failure.
 */
int main(int argc, char *argv[])
{
char *directory = NULL;
char current_directory[4096];

/* Check if an argument is provided */
if (argc > 1)
{
/* Check if the argument is cd - */
if (strcmp(argv[1], "-") == 0)
{
/* Change to the previous directory stored in PWD environment variable */
directory = getenv("OLDPWD");
if (directory == NULL)
{
fprintf(stderr, "cd: OLDPWD not set\n");
return (1);
}
}
else
{
/* Change to the specified directory */
directory = argv[1];
}
}
else
{
/* No argument provided, change to $HOME directory */
directory = getenv("HOME");
if (directory == NULL)
{
fprintf(stderr, "cd: HOME not set\n");
return (1);
}
}

/* Store the current directory in the environment variable OLDPWD */
if (getcwd(current_directory, sizeof(current_directory)) == NULL)
{
fprintf(stderr, "cd: Error getting current directory\n");
return (1);
}
setenv("OLDPWD", current_directory, 1);

/* Change the current directory */
if (chdir(directory) != 0)
{
fprintf(stderr, "cd: %s: No such file or directory\n", directory);
return (1);
}

/* Update the environment variable PWD */
if (getcwd(current_directory, sizeof(current_directory)) == NULL)
{
fprintf(stderr, "cd: Error getting current directory\n");
return (1);
}
setenv("PWD", current_directory, 1);

return (0);
}
