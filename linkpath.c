#include "shell.h"

char *get_env_var(const char *name)
{
	int i, j;
	char *value;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;

				j++;
			}
			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (0);
}

list_path *add_node_end(list_path **head, char *str)
{

	list_path *tmp;
	list_path *new_node;

	new_node = malloc(sizeof(list_path));

	if (!new_node || !str)
	{
		return (NULL);
	}

	new_node->dir = str;

	new_node->p = '\0';
	if (!*head)
	{
		*head = new_node;
	}
	else
	{
		tmp = *head;

		while (tmp->p)
		{
			tmp = tmp->p;
		}

		tmp->p = new_node;
	}

	return (*head);
}

list_path *create_path_list(char *path)
{
	list_path *head = '\0';
	char *token;
	char *cpath = string_duplicate(path);

	token = strtok(cpath, ":");
	while (token)
	{
		head = add_node_end(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

char *get_executable_path(char *filename, list_path *head)
{
	struct stat st;
	char *string;

	list_path *tmp = head;

	while (tmp)
	{
		string = concatenate_all(tmp->dir, "/", filename);
		if (stat(string, &st) == 0)
		{
			return (string);
		}
		free(string);
		tmp = tmp->p;
	}

	return (NULL);
}

void free_list(list_path *head)
{
	list_path *storage;

	while (head)
	{
		storage = head->p;
		free(head->dir);
		free(head);
		head = storage;
	}
}
