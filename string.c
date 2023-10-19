#include "shell.h"

char *string_duplicate(char *str)
{
	int i, l;
	char *new;

	if (!str)
	{
		return (NULL);
	}
	for (l = 0; str[l] != '\0';)
	{
		l++;
	}
	new = malloc(sizeof(char) * l + 1);
	if (!new)
	{
		return (NULL);
	}
	for (i = 0; i < l; i++)
	{
		new[i] = str[i];
	}
	new[l] = str[l];
	return (new);
}

char *concatenate_all(char *name, char *sep, char *value)
{
	char *result;
	int l1, l2, l3, i, k;

	l1 = string_length(name);
	l2 = string_length(sep);
	l3 = string_length(value);

	result = malloc(l1 + l2 + l3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

int string_length(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

int print_char(char c)
{
	return (write(1, &c, 1));
}

void print_string(char *str)
{
	int i = 0;

	while (str[i])
	{
		print_char(str[i]);
		i++;
	}
}
