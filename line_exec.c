#include "shell.h"

char **split_string(char *str, const char *delim)
{
	int i, wn;
	char **array;
	char *token;
	char *copy;

	copy = malloc(string_length(str) + 1);
	if (copy == NULL)
	{
		perror(get_env_var("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';

	token = strtok(copy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = string_duplicate(token);

	i = 1;
	wn = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = reallocate(array, (sizeof(char *) * (wn - 1)), (sizeof(char *) * wn));
		array[i] = string_duplicate(token);
		i++;
		wn++;
	}
	free(copy);
	return (array);
}

void execute_command(char **argv)
{
	int d, status;

	if (!argv || !argv[0])
		return;
	d = fork();
	if (d == -1)
	{
		perror(get_env_var("_"));
	}
	if (d == 0)
	{
		execve(argv[0], argv, environ);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}

void *reallocate(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}

void free_args(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}
