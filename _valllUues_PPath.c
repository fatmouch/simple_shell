#include "shell.h"
/**
 * values_de_path - separate the path in new strings.
 * @arg: command input of user.
 * @env: enviroment.
 * Return:  a pointer to strings.
 */
int values_de_path(char **arg, char **env)
{
	char *token = NULL, *path_rela = NULL, *path_absol = NULL;
	size_t value_path, command;
	struct stat stat_lineptr;

	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);
	path_rela = _getpath(env);
	if (!path_rela)
		return (-1);
	token = _strtoookK(path_rela, ":");
	command = len_gth(*arg);
	while (token)
	{
		value_path = len_gth(token);
		path_absol = malloc(sizeof(char) * (value_path + command + 2));
		if (!path_absol)
		{
			free(path_rela);
			return (-1);
		}
		path_absol = _strngcpy(path_absol, token);
		strcatt(path_absol, "/");
		strcatt(path_absol, *arg);

		if (stat(path_absol, &stat_lineptr) == 0)
		{
			*arg = path_absol;
			free(path_rela);
			return (0);
		}
		free(path_absol);
		token = _strtoookK(NULL, ":");
	}
	free(path_rela);
	return (-1);
}
