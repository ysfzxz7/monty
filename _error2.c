#include "monty.h"

/**
 * __pint_error - func that prints an error about pint instruction.
 * @l_num: number of current line.
 * Return: void.
*/
void __pint_error(unsigned int l_num)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", l_num);
	exit(EXIT_FAILURE);
}

/**
 * __pop_error - func that prints an error about pop instruction.
 * @l_num: number of current line.
 * Return: void.
*/
void __pop_error(unsigned int l_num)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", l_num);
	exit(EXIT_FAILURE);
}

/**
 * __swap_error - func that prints an error about swap.
 * @l_num: number of current line.
 * Return: void.
*/
void __swap_error(unsigned int l_num)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", l_num);
	exit(EXIT_FAILURE);
}

/**
 * __add_error - func that prints an error about add.
 * @l_num: number of current line.
 * Return: void.
*/
void __add_error(unsigned int l_num)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", l_num);
	exit(EXIT_FAILURE);
}

/**
 * __sub_error - func that prints an error about sub instruction.
 * @l_num: number of current instruction's line.
 * Return: void.
*/
void __sub_error(unsigned int l_num)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", l_num);
	exit(EXIT_FAILURE);
}
