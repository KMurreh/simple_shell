#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void handle_variable_replacement(char *command);

void handle_variable_replacement(char *command)
{
    char result[MAX_COMMAND_LENGTH];

    while (*command != '\0')
    {
        if (*command == '$')
        {
            if (*(command + 1) == '?')
            {
                sprintf(result, "%d", WEXITSTATUS(system(NULL)));
                printf("%s", result);
                command += 2;
            }
            else if (*(command + 1) == '$')
            {
                sprintf(result, "%d", getpid());
                printf("%s", result);
                command += 2;
            }
            else
            {
                printf("$");
                command++;
            }
        }
        else
        {
            printf("%c", *command);
            command++;
        }
    }
}

int main(void)
{
    char command[MAX_COMMAND_LENGTH];

    printf("Enter a command: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = '\0';

    handle_variable_replacement(command);
    printf("\n");

    return 0;
}
