#include "main.h"

/**
 * __is_num - func that check if a line contains a numb or not
 * @num: ptr to the string
 * Return: 1 success other 0
*/
int __is_num(char *num)
{
	int i;

	if (num)
	{
		for (i = 0; num[i]; i++)
		{
			if (i == 0 && num[0] == '-')
				continue;
			if (num[i] < '0' || num[i] > '9')
				return (0);
		}
	}
	else
		return (0);

	return (1);
}

/**
 * __find_function - func handle func ptrs.
 * @opcode: the command
 * Return: the func ptr otherwise NULL otherwise.
*/
function __find_function(char *opcode)
{
	instruction_t fs[] = {
		{"push", __push},
		{"pall", __pall},
		{"pint", __pint},
		{"pop", __pop},
		{"swap", __swap},
		{"add", __add},
		{"nop", __nop},
		{"sub", __sub},
		{"div", __div},
		{"mul", __mul},
		{"mod", __mod},
		{"pchar", __pchar},
		{"pstr", __pstr},
		{"rotl", __rotl},
		{"rotr", __rotr},
		{NULL, NULL}
	};
	int i = 0;

	while (fs[i].opcode)
	{
		if (strcmp(fs[i].opcode, opcode) == 0)
			break;
		i++;
	}

	return (fs[i].f);
}

/**
 * __is_ascii - func check if a number ot of range
 * @ascii: ascii num
 * Return: 1 if ascii, 0 otherwise.
 */
int __is_ascii(int ascii)
{
	return (ascii >= 0 && ascii <= 127);
}
