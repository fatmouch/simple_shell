#include "shell.h"

/* my own personal print func */

void tima_mhmd_print_function(const char *missage)
{
write(STDOUTFILENO, missage, strlen(missage)); /*personal print*/
}
