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

#define BUFF_SIZE 1024

/* environ variable */
extern char **environ;


char *readCommand();
char *expand_buff(char *buffer, size_t length);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
int execCommand(char **argv);
char **splitCommand(char *command, const char *delimiter);
size_t count_tokens(char *command, const char *delimiter);
char *get_path(char *command);
char *creat_path(char *dir, char *command);
char *_getenv(const char *name);
void print_env(void);

/* String functions */

int _strlen(const char *s);
char *_strdup(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char  *s1, const char *s2, size_t n);
char *_strchr(const char *str, int c);

#endif
