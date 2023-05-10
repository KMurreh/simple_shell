#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_message - Prints a message to stdout.
 */
void print_message(void)
{
    char *message = "Hello, world!";
    write(1, message, 13);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        int num = atoi(argv[1]);
        printf("You entered: %d\n", num);
    } else {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return 1;
    }

    print_message();

    return 0;
}
