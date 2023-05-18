#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * _getline - Custom implementation of getline
 *
 * Description:Reads line of input from user and stores it in a buffer.
 *              Uses static variables to keep track of buffer and its position.
 * Return: Pointer to the read line, or NULL on failure or end-of-file.
 */
char *_getline(void)
{
static char buffer[BUFFER_SIZE];
static int pos;
static int bytes_read;

if (pos >= bytes_read)
{
bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
if (bytes_read <= 0)
return (NULL);
pos = 0;
}

char *line = malloc(bytes_read - pos + 1);
if (line == NULL)
return (NULL);

int i = 0;
while (pos < bytes_read && buffer[pos] != '\n')
line[i++] = buffer[pos++];

line[i] = '\0';
pos++;

return (line);
}

/**
 * main - Entry point of the program
 *
 * Description: Reads lines of input using the custom getline function
 *              and prints them to the console.
 * Return: Always 0
 */
int main(void)
{
char *line;

do {
printf("$ ");
line = _getline();
if (line != NULL)
{
printf("You entered: %s\n", line);
free(line);
}
} while (line != NULL);

return (0);
}
