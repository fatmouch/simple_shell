#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int strng_cmpr(char *st1, char *st2);
size_t strn_cmp(char *st1, char *st2, size_t n);
int len_gth(char *s);
char *_strngcpy(char *desti, char *sr);
char *strcatt(char *desti, char *sr);
int _putchar(char c);

char *_getpath(char **env);
int values_de_path(char **arg, char **env);
char *_getlin_commande(void);
void _getttenv(char **env);
char **_get_tooKken(char *lineptr);
void _exit_ccomand(char **args, char *lineptr, int _exit);
int _forkk_fuUn(char **arg, char **av, char **env,char *lineptr, int np, int c);
char *_strtoookK(char *str, const char *delim);


#endif /* SHELL_H */
