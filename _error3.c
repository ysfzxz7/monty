#include "monty.h"

/**
 * __div_error - func that print error in div instr.
 * @type: type of the error
 * @l_num: the line of the error
 * Return: void.
*/
void __div_error(int type, unsigned int l_num)
{
	if (type == 1)
		fprintf(stderr, "L%d: can't div, stack too short\n", l_num);
	else if (type == 0)
		fprintf(stderr, "L%d: division by zero\n", l_num);
	exit(EXIT_FAILURE);
}

/**
 * __mul_error - func that print error about mul
 * @l_num: the current line
 * Return: void.
*/
void __mul_error(unsigned int l_num)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", l_num);
	exit(EXIT_FAILURE);
}

/**
 * __mod_error - func a func that print the mod erros
 * @type: error type
 * @l_num: the curr line
 * Return: void.
*/
void __mod_error(int type, unsigned int l_num)
{
	if (type == 1)
		fprintf(stderr, "L%d: can't mod, stack too short\n", l_num);
	else
		fprintf(stderr, "L%d: division by zero\n", l_num);
	exit(EXIT_FAILURE);
}

/**
 * __pchar_error - func a func that print the mod erros
 * @type: error type
 * @l_num: the curr line
 * Return: void.
*/
void __pchar_error(int type, unsigned int l_num)
{
	if (type == 1)
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
	else
		fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
	exit(EXIT_FAILURE);
}

