#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

void execmdftmf(char *commande);
char *avoir_LOcation(char *commande);
void tima_mhmd_print_function(const char *missage);

#endif
