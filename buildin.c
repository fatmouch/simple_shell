#include "shell.h"

void exit_shell(char **args)
{
	int i, n;

	if (args[1])
	{
		n = string_to_int(args[1]);
		if (n <= -1)
			n = 2;
		free_args(args);
		exit(n);
	}
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
	exit(0);
}

int string_to_int(char *s)
{
	int i, integer, sign = 1;

	i = 0;
	integer = 0;
	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
	{
		if (s[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (integer);
}

void print_env(char **args __attribute__ ((unused)))
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		print_string(environ[i]);
		print_string("\n");
	}
}

void set_environment(char **args)
{
	int i, j, k;

	if (!args[1] || !args[2])
	{
		perror(get_env_var("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (args[1][j] == environ[i][j])
		{
			while (args[1][j])
			{
				if (args[1][j] != environ[i][j])
					break;

				j++;
			}
			if (args[1][j] == '\0')
			{
				k = 0;
				while (args[2][k])
				{
					environ[i][j + 1 + k] = args[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{
		environ[i] = concatenate(args[1], "=", args[2]);
		environ[i + 1] = '\0';
	}
}

void unset_environment(char **args)
{
	int i, j;

	if (!args[1])
	{
		perror(get_env_var("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (args[1][j] == environ[i][j])
		{
			while (args[1][j])
			{
				if (args[1][j] != environ[i][j])
					break;

				j++;
			}
			if (args[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}
