#include "shell.h"

char *_strchr(const char *s, int c);
size_t _strspn(const char *st1, const char *st2);
size_t _strcspn(const char *st1, const char *st2);

/**
 * _strtoookK - breaks the string st1 into tokens and null-terminates them.
 * Delimiter-Characters at the beginning and end
 *of str are skipped. On each subsequent call delim may change.
 * @str: string to tokenize
 * @delim: string with the character that delimit srt.
 * Return: the first/next token if possible, a null-pointer otherwise.
 **/
char *_strtoookK(char *str, const char *delim)
{
	static char *p;

	if (str)
		p = str;
	else if (!p)
		return (0);
	str = p + _strspn(p, delim);
	p = str + _strcspn(str, delim);
	if (p == str)
		return (p = 0);
	p = *p ? *p = 0, p + 1 : 0;
	return (str);
}
/**
 * _strcspn - computes the length of the maximum initial segment of the string
 * pointed to by st1which consists entirely of characters not from the
 * string pointed to by st2.
 * @st1: string to check
 * @st2: string useful to compare
 * Return: the length of the segment.
 **/
size_t _strcspn(const char *st1, const char *st2)
{
	size_t ret = 0;

	while (*st1)
	{
		if (_strchr(st2, *st1))
			return (ret);
		st1++, ret++;
	}
	return (ret);
}
/**
 * _strspn - computes the length of the maximum initial segment of the string
 * pointed to by st1 which consists entirely of characters from the string
 * pointed to by st2.
 * @st1: strint to compute the lengh
 * @st2: string delimit
 * Return: the length of the segment.
 **/
size_t _strspn(const char *st1, const char *st2)
{
	size_t ret = 0;

	while (*st1 && _strchr(st2, *st1++))
		ret++;
	return (ret);
}
/**
 * _strchr - locates the ﬁrst occurrence of c (converted to a char) in the
 * string pointed to by s. The terminating null character is considered to be
 * part of the string.
 * @s: string
 * @c: character
 * Return: a pointer to the located character, or a null pointer
 * if the character does not occur in the string.
 **/
char *_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}
