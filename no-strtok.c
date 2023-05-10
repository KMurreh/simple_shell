#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 10
#define MAX_TOKEN_LENGTH 20

/**
 * tokenize_string - Tokenizes a string into an array of tokens.
 * @str: The string to tokenize.
 * @tokens: Array to store the tokens.
 * Return: The number of tokens.
 */
int tokenize_string(const char *str, char tokens[][MAX_TOKEN_LENGTH])
{
    int num_tokens = 0;
    char *token, *copy;

    copy = strdup(str);
    if (copy == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 0;
    }

    token = strtok(copy, " \t\n");
    while (token != NULL && num_tokens < MAX_TOKENS) {
        strncpy(tokens[num_tokens], token, MAX_TOKEN_LENGTH - 1);
        tokens[num_tokens][MAX_TOKEN_LENGTH - 1] = '\0';
        num_tokens++;
        token = strtok(NULL, " \t\n");
    }

    free(copy);
    return num_tokens;
}

/**
 * main - Entry point of the program.
 * Return: 0 on success.
 */
int main(void)
{
    const char *input = "This is a sample string";
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int num_tokens, i;

    num_tokens = tokenize_string(input, tokens);

    printf("Number of tokens: %d\n", num_tokens);
    printf("Tokens:\n");
    for (i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i]);
    }

    return 0;
}
