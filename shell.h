#ifndef SHELL_H
#define SHELL_H

/*
 * Desc: Header file containing prototypes for all functions
 *       written in the 0x16. C - Simple Shell repo.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int sum_array(int arr[], int size);

void execute_command(const char *command);

int main(int argc, char *argv[]);

int main(int argc, char *argv[]);

int execute_command(char *command);

void handle_variable_replacement(char *command);

int main(int argc, char *argv[]);

void print_environment(void);

char *_getline(void);

int main(int argc, char *argv[]);

int execute_command(char *command, char *path);

int execute_command(char *command, char *arguments[], int num_arguments);

void exit_shell(void);

int execute_commands_separated_by_semicolon(void);

int execute_command(char *command);

int split_string(const char *str, char tokens[][MAX_TOKEN_LENGTH]);

int main(int argc, char *argv[])


#endif /* SHELL_H */
