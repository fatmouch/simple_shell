#include "shell.h"
/**
 * _getlin_commande - print "#cisfun$ " and wait for the user type something.
 * Return: line of string input for user
 */

char *_getlin_commande(void)
{
	char *lineptr = NULL;
	size_t charter_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&lineptr, &charter_user, stdin) == -1)
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}
