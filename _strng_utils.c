#include "shell.h"
/**
 *strcatt - copy string to another string.
 *@desti: char
 *@sr: char
 *Return: desti
 *
 */

char *strcatt(char *desti, char *sr)
{
	int d = 0;
	int s = 0;

	while (desti[d] != '\0')
	{
		d++;
	}
	while (sr[s] != '\0')
	{
		desti[d] = sr[s];
		d++;
		s++;
	}
	desti[d] = '\0';
	return (desti);
}

/**
 * strng_cmpr - compare the values of a string
 * @st1: character
 * @st2: character
 * Return: 0
 */

int strng_cmpr(char *st1, char *st2)
{
	int a;

	for (a = 0; st1[a] != '\0' && st2[a] != '\0'; a++)
	{
		if (st1[a] != st2[a])
			return ((int)st1[a] - st2[a]);
	}
	return (0);
}

/**
 * len_gth - copies the string pointed to by sr into desti
 * @s: A pointer
 * Return: char pointer to desti
 */

int len_gth(char *s)
{
	int ch = 0;

	while (*(s + ch) != '\0')
	{
		ch++;
	}

	return (ch);
}

/**
 *strn_cmp -  function that compares two strings.
 *@st1: string one
 *@st2: string two
 *@n: number of characters
 * Return: diference
 */

size_t strn_cmp(char *st1, char *st2, size_t n)
{
	size_t i, j;

	for (j = 0; st1[j] != '\0' && j < n; j++)
	{
		i = st1[j] - st2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}

/**
 * _strngcpy - copies the string pointed to by sr into desti
 * @desti: destiination of the copy
 * @sr: source of the copy
 *
 * Return: char pointer to desti
 */

char *_strngcpy(char *desti, char *sr)
{
	int i = 0;

	while (*(sr + i) != '\0')
	{
		*(desti + i) = *(sr + i);
		++i;
	}
	*(desti + i) = *(sr + i);

	return (desti);
}
