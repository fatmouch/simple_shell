#include "shell.h"
/**
 * _get_tooKken - get token of string
 * @lineptr: comman user
 * Return: To a pointer
 */

char **_get_tooKken(char *lineptr)
{
	char **user_command = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;

	if (lineptr == NULL)
		return (NULL);

	for (i = 0; lineptr[i]; i++)
	{
		if (lineptr[i] == ' ')
			size++;
	}
	if ((size + 1) == len_gth(lineptr))
		return (NULL);
	user_command = malloc(sizeof(char *) * (size + 2));
	if (user_command == NULL)
		return (NULL);

	token = _strtoookK(lineptr, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		user_command[i] = token;
		token = _strtoookK(NULL, " \n\t\r");
	}
	user_command[i] = NULL;
	return (user_command);
}
