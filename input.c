#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_FILENAME_LENGTH 50

void execute_commands_from_file(char *filename);

void execute_commands_from_file(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return;
    }

    char command[MAX_COMMAND_LENGTH];

    while (fgets(command, MAX_COMMAND_LENGTH, file) != NULL)
    {
        system(command);
    }

    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    execute_commands_from_file(filename);

    return 0;
}
