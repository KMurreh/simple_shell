#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024

/**
 * change_directory - Changes the current directory of the process.
 * @directory: The directory to change to.
 * Return: 0 on success, -1 on failure.
 */
int change_directory(const char *directory)
{
    char path[MAX_PATH_LENGTH];

    if (directory == NULL || strcmp(directory, "") == 0) {
        directory = getenv("HOME");
        if (directory == NULL) {
            fprintf(stderr, "cd: No home directory found\n");
            return -1;
        }
    } else if (strcmp(directory, "-") == 0) {
        directory = getenv("OLDPWD");
        if (directory == NULL) {
            fprintf(stderr, "cd: No previous directory found\n");
            return -1;
        }
    }

    if (chdir(directory) != 0) {
        fprintf(stderr, "cd: Failed to change directory to %s\n", directory);
        return -1;
    }

    if (getcwd(path, sizeof(path)) == NULL) {
        fprintf(stderr, "cd: Failed to get current directory\n");
        return -1;
    }

    if (setenv("PWD", path, 1) != 0) {
        fprintf(stderr, "cd: Failed to set PWD environment variable\n");
        return -1;
    }

    printf("Current directory: %s\n", path);
    return 0;
}

/**
 * main - Entry point of the program.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [DIRECTORY]\n", argv[0]);
        return 1;
    }

    const char *directory = (argc == 2) ? argv[1] : NULL;
    if (change_directory(directory) != 0) {
        return 1;
    }

    return 0;
}
