#include "monty.h"

/**
 * __add - func that add tp two numbers of stack to each other
 * @stack: pointer of pointer to stack.
 * @l_num: number of current instruction's line.
 * Return: void.
 */
void __add(stack_t **stack, unsigned int l_num)
{
	stack_t *tp, *nxt;

	if (!stack || !(*stack) || !(*stack)->next)
		__add_error(l_num);

	tp = *stack;
	nxt = tp->next;
	nxt->n += tp->n;
	*stack = nxt;
	free(tp);
}

/**
 * __nop - func that do nothing.
 * @stack: pointer of pointer to stack.
 * @l_num: number of instruction's line.
 * Return: void.
*/
void __nop(stack_t **stack, unsigned int l_num)
{
	(void)stack;
	(void)l_num;
}

/**
 * __sub - func that subtract the tp element of stack from the second.
 * @stack: pointer of pointer to stack.
 * @l_num: number of instruction's line.
 * Return: void.
*/
void __sub(stack_t **stack, unsigned int l_num)
{
	stack_t *tp, *nxt;

	if (!stack || !(*stack) || !(*stack)->next)
		__sub_error(l_num);

	tp = *stack;
	nxt = tp->next;

	nxt->n -= tp->n;
	nxt->prev = NULL;
	*stack = nxt;
	free(tp);
}

/**
 * __div - func that divides the second tp element by the tp.
 * @stack: pointer of pointer to stack.
 * @l_num: number of instruction's line.
 * Return: void.
*/
void __div(stack_t **stack, unsigned int l_num)
{
	stack_t *tp, *nxt;

	if (!stack || !(*stack) || !(*stack)->next)
		__div_error(1, l_num);

	if ((*stack)->n == 0)
		__div_error(0, l_num);

	tp = *stack;
	nxt = tp->next;

	nxt->n /= tp->n;
	nxt->prev = NULL;
	*stack = nxt;
	free(tp);
}

/**
 * __mul - func that multiplies that multiplies tp element by the second.
 * @stack: pointer of pointer to stack.
 * @l_num: number of instruction's line.
 * Return: void.
*/
void __mul(stack_t **stack, unsigned int l_num)
{
	stack_t *tp, *nxt;

	if (!stack || !(*stack) || !(*stack)->next)
		__mul_error(l_num);

	tp = *stack;
	nxt = tp->next;

	nxt->n *= tp->n;
	nxt->prev = NULL;
	*stack = nxt;
	free(tp);
}
