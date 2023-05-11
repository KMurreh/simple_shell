#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void handle_comments(char *command);

void handle_comments(char *command)
{
    char *comment = strchr(command, '#');

    if (comment != NULL)
    {
        *comment = '\0';
    }

    printf("%s", command);
}

int main(void)
{
    char command[MAX_COMMAND_LENGTH];

    printf("Enter a command: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = '\0';

    handle_comments(command);
    printf("\n");

    return 0;
}
