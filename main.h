#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

/* environ variable */
extern char **environ;


char *readCommand();
int execCommand(char **argv);
char **splitCommand(char *command, const char *delimiter);
size_t count_tokens(char *command, const char *delimiter);
char *get_path(char *command);
char *creat_path(char *dir, char *command);
char *_getenv(const char *name);

/* String functions */

int _strlen(const char *s);
char *_strdup(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);

#endif
