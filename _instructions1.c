#include "monty.h"

/**
 * __push - func that pushs a number to the stack.
 * @stack: arr of ->charsequences.
 * @l_num: number of the instruction.
 * Return: void.
 */
void __push(stack_t **stack, __attribute__((unused)) unsigned int l_num)
{
	__insert_start(stack, var.inst_code);
}

/**
 * __pall - func that prints all values included onto stack.
 * @stack: ptr to ptr to stack.
 * @l_num: instruction's line number.
 * Return: void.
 */
void __pall(stack_t **stack, __attribute__((unused)) unsigned int l_num)
{
	stack_t *p;

	if (!stack || !(*stack))
		return;

	p = *stack;
	while (p)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}

/**
 * __pint - func that prints the tp element in stack.
 * @stack: ptr to ptr to the stack.
 * @l_num: number of current line.
 * Return: void.
*/
void __pint(stack_t **stack, unsigned int l_num)
{
	stack_t *p;

	if (stack)
	{
		p = *stack;
		if (!p)
		{
			__pint_error(l_num);
			exit(EXIT_FAILURE);
		}
		printf("%d\n", p->n);
	}
	else
		__pint_error(l_num);
}


/**
 * __pop - func that removes the tp element of stack.
 * @stack: ptr to ptr to the stack.
 * @l_num: number of current line.
 * Return: void.
*/
void __pop(stack_t **stack, unsigned int l_num)
{
	stack_t *p, *temp;

	if (!stack)
		__pop_error(l_num);
	p = *stack;
	if (!p)
		__pop_error(l_num);

	temp = p->next;
	if (!temp)
	{
		*stack = NULL;
		free(p);
		return;
	}
	temp->prev = NULL;
	*stack = temp;
	free(p);
}

/**
 * __swap - func that swaps tp 2 elements of stack.
 * @stack: ptr to ptr to the stack.
 * @l_num: number of current line.
 * Return: void.
 */
void __swap(stack_t **stack, unsigned int l_num)
{
	stack_t *tp, *next, *temp;

	if (!stack || !(*stack) || !(*stack)->next)
		__swap_error(l_num);

	tp = *stack;
	next = tp->next;
	temp = next->next;

	*stack = next;
	next->prev = NULL;
	next->next = tp;
	tp->next = temp;
	tp->prev = next;
	if (temp)
		temp->prev = tp;
}
