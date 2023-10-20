#include "shell.h"
/**
 * _exit_ccomand - this function closes the simple_shell when
 * @arg: pointer with the direction argument.
 * @lineptr: standar input string
 * @_exit: value of exit
 * Return: None
 */
void _exit_ccomand(char **arg, char *lineptr, int _exit)
{
	int exit_status = 0;

	if (!arg[1])
	{
		free(lineptr);
		free(arg);
		exit(_exit);
	}
	exit_status = atoi(arg[1]);

	free(lineptr);
	free(arg);
	exit(exit_status);
}

/**
 *_getttenv - function to get all env
 *@env: enviroment
 *Return: 0
 */

void _getttenv(char **env)
{
	size_t run = 0;

	while (env[run])
	{
		write(STDOUT_FILENO, env[run], len_gth(env[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}