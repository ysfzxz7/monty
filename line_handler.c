#include "main.h"

/**
 * __handle_line - func that splits line ito words
 * @line: ptr to d char seq
 * Return: array of words, NULL if it failed.
 */
char **__handle_line(char *line)
{
	char **array, *word;
	int i = 0, count;

	if (!line || strlen(line) == 0)
		return (NULL);
	count = __word_count(line);
	if (count == 0)
		return (NULL);
	array = (char **) malloc((count + 1) * sizeof(char *));
	if (!array)
		__malloc_error();

	word = strtok(line, " \t\n");
	while (word != NULL)
	{
		array[i++] = __strdup(word);
		word = strtok(NULL, " \t\n");
	}
	array[i] = NULL;

	return (array);
}

/**
 * __split_line - function that split lines to keywords using handle_line fuc.
 * @line: ptr to tagt line
 * Return: arr of keys
*/
char **__split_line(char *line)
{
	if (line)
	{
		if (strlen(line) <= 1)
			return (NULL);
		return (__handle_line(line));
	}
	return (NULL);
}

