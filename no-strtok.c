#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 10
#define MAX_TOKEN_LENGTH 20

/**
 * split_string - Splits a string into tokens
 * @str: The string to tokenize
 * tokenize_string - Tokenizes a string into an array of tokens
 * @tokens: The array to store the tokens
 * Description: Splits a string into tokens using manual string manipulation.
 * Return: The number of tokens found.
 */
int split_string(const char *str, char tokens[][MAX_TOKEN_LENGTH])
{
int num_tokens = 0;
int token_length = 0;

for (int i = 0; str[i] != '\0'; i++)
{
if (str[i] == ' ')
{
if (token_length > 0)
{
tokens[num_tokens][token_length] = '\0';
num_tokens++;
token_length = 0;
}
}
else
{
tokens[num_tokens][token_length] = str[i];
token_length++;
}
}

if (token_length > 0)
{
tokens[num_tokens][token_length] = '\0';
num_tokens++;
}

return (num_tokens);
}

/**
 * main - Entry point of the program
 *
 * Description:Splits sample string into tokens using split_string function
 *              and prints the tokens.
 *Return: 0 on success.
 */
int main(void)
{
char str[] = "Hello World! Welcome to the Shell";
char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];

int num_tokens = split_string(str, tokens);

printf("Tokens:\n");
for (int i = 0; i < num_tokens; i++)
{
printf("%s\n", tokens[i]);
}

return (0);
}
