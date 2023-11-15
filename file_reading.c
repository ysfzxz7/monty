#include "monty.h"

int _is_comment(char *line);

/**
 * __read_file - func that reads the given file linebyline
 * Return: void.
 */
void __read_file(void)
{
	unsigned int counter = 1;
	char *opcode;
	function f;

	var.line = malloc(sizeof(char) * BUFF_SIZE);
	if (!var.line)
		__malloc_error();
	while (fgets(var.line, sizeof(char) * BUFF_SIZE, var.file))
	{
		if (_is_comment(var.line))
		{
			counter++;
			continue;
		}
		var.array = __split_line(var.line);
		if (var.array)
		{
			opcode = var.array[0];
			if (strcmp(opcode, "push") == 0)
			{
				if (!var.array[1])
					__push_error(counter);
				if (!__is_num(var.array[1]))
					__push_error(counter);
				var.inst_code = atoi(var.array[1]);
			}
			f = __find_function(opcode);
			if (f == NULL)
				__inst_error(counter, opcode);

			f(var.stack, counter);
		}
		__free_array(var.array);
		counter++;
	}
	free(var.line);
}

/**
 * __free_array - func that frees the read files
 * @array: array of str
 * Return: void.
*/
void __free_array(char **array)
{
	int i = 0;

	if (!array)
		return;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 * _is_comment - function that checks line if starts with #
 * @line: pointer to line.
 * Return: 1 if it is comment, 0 otherwise.
*/
int _is_comment(char *line)
{
	return (!line || line[0] == '#');
}
