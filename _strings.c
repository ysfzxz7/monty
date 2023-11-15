#include "monty.h"

/**
 * __word_count - func that returns the number of words in a string.
 * @l: ptr to yhe d  target string.
 * Return: number of words.
 */
int __word_count(char *l)
{
	int count = 0;
	char *w, *dup;

	if (!l)
		return (0);
	dup = __strdup(l);
	w = strtok(dup, " \t\n");
	while (w)
	{
		count++;
		w = strtok(NULL, " \t\n");
	}
	free(dup);

	return (count);
}

/**
 * __strdup - func that duplicates strings.
 * @str: ptr to yhe d  target string.
 * Return: address to the new string.
*/
char *__strdup(char *str)
{
	char *p;
	int i = 0;

	if (!str)
		return (NULL);
	p = malloc(sizeof(char) * (strlen(str) + 1));
	if (!p)
		__malloc_error();
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';

	return (p);
}
