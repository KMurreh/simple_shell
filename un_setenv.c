#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * set_env - Set a new environment variable or modify an existing one.
 * @variable: The name of the environment variable.
 * @value: The value to set for the environment variable.
 * Return: 0 on success, -1 on failure.
 */
int set_env(const char *variable, const char *value)
{
    if (variable == NULL || value == NULL) {
        fprintf(stderr, "setenv: Invalid arguments\n");
        return -1;
    }

    if (setenv(variable, value, 1) != 0) {
        fprintf(stderr, "setenv: Failed to set environment variable\n");
        return -1;
    }

    return 0;
}

/**
 * unset_env - Remove an environment variable.
 * @variable: The name of the environment variable to remove.
 * Return: 0 on success, -1 on failure.
 */
int unset_env(const char *variable)
{
    if (variable == NULL) {
        fprintf(stderr, "unsetenv: Invalid argument\n");
        return -1;
    }

    if (unsetenv(variable) != 0) {
        fprintf(stderr, "unsetenv: Failed to unset environment variable\n");
        return -1;
    }

    return 0;
}

/**
 * main - Entry point of the program.
 * Return: 0 on success.
 */
int main(void)
{
    const char *variable = "MY_VAR";
    const char *value = "my_value";

    // Set environment variable
    if (set_env(variable, value) != 0) {
        fprintf(stderr, "Failed to set environment variable\n");
        return 1;
    }

    // Print the environment variable
    char *env_value = getenv(variable);
    if (env_value != NULL) {
        printf("Environment variable %s: %s\n", variable, env_value);
    } else {
        fprintf(stderr, "Failed to retrieve environment variable\n");
        return 1;
    }

    // Unset environment variable
    if (unset_env(variable) != 0) {
        fprintf(stderr, "Failed to unset environment variable\n");
        return 1;
    }

    // Check if environment variable is unset
    env_value = getenv(variable);
    if (env_value == NULL) {
        printf("Environment variable %s is unset\n", variable);
    } else {
        fprintf(stderr, "Environment variable was not unset\n");
        return 1;
    }

    return 0;
}
