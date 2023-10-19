#include "shell.h"

void (*check_build(char **args))(char **args)
{
	int i, j;
	my_build T[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{"setenv", set_environment},
		{"unsetenv", unset_environment},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		j = 0;
		if (T[i].name[j] == args[0][j])
		{
			for (j = 0; args[0][j]; j++)
			{
				if (T[i].name[j] != args[0][j])
					break;
			}
			if (!args[0][j])
				return (T[i].func);
		}
	}
	return (0);
}
