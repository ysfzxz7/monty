#include "main.h"

/**
 * __malloc_error - func that prints a malloc error and exit with failure.
 * Return: void.
 */
void __malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * __cannot_open_file - func that prints error about opening file,
 * and exiting with a failure  num.
 * @file_path: pointer to the file path.
 * Return: void.
 */
void __cannot_open_file(char *file_path)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
}

/**
 * __monty_usage - func that prints a monty usage error when monty used,
 * with wrong way.
 * Return: void.
 */
void __monty_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * __push_error - func that prints an error of push, and exits with failure.
 * @l_num:  num of line that contains the incorrect instruction.
 * Return: void.
*/
void __push_error(unsigned int l_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", l_num);
	exit(EXIT_FAILURE);
}

/**
 * __inst_error - func that prints an instruction error.
 * @l_num: instruction's line  num.
 * @opcode: pointer to the opcode.
 * Return: void.
 */
void __inst_error(unsigned int l_num, char *opcode)
{
	fprintf(stderr, "L%d: unkown instruction %s\n", l_num, opcode);
	exit(EXIT_FAILURE);
}
