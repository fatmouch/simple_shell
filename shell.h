#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int print_char(char c);
void print_string(char *str);
int string_length(char *s);
char *string_duplicate(char *str);
char *concatenate_all(char *name, char *sep, char *value);

char **split_string(char *str, const char *delim);
void execute_command(char **args);
void *reallocate(void *ptr, unsigned int old_size, unsigned int new_size);

extern char **environ;

typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;

char *get_env_var(const char *name);
list_path *add_node_end(list_path **head, char *str);
list_path *create_path_list(char *path);
char *get_executable_path(char *filename, list_path *head);

typedef struct my_build
{
	char *name;
	void (*func)(char **);
} my_build;

void (*check_build(char **args))(char **args);
int string_to_int(char *s);
void exit_shell(char **args);
void print_env(char **args);
void set_environment(char **args);
void unset_environment(char **args);

void free_args(char **args);
void free_list(list_path *head);

#endif
