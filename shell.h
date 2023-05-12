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

int main(int argc, char *argv[]);

int main(void);

int main(int argc, char *argv[]);

int main(int argc, char *argv[], char *envp[]);

int tokenize_string(const char *str, char tokens[][MAX_TOKEN_LENGTH]);

void exit_shell(int status);

int set_env(const char *variable, const char *value);

int change_directory(const char *directory);

int execute_command(const char *command);

int sum_array(int arr[], int size); 

extern char **environ;



#endif /* SHELL_H */
