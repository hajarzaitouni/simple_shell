#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *readCommand();
int execCommand(char **argv);
char **splitCommand(char *command, char *delimiter);

/* String functions */

int _strlen(char *s);
char *_strdup(char *s);

#endif
