#include "monty.h"

/**
 * __mod - func that computes the rest of divition of
 * tp element by the second.
 * @stack: ptr of ptr to the stack
 * @l_num: the curr line.
 * Return: void.
*/
void __mod(stack_t **stack, unsigned int l_num)
{
	stack_t *tp, *next;

	if (!stack || !(*stack) || !(*stack)->next)
		__mod_error(1, l_num);

	tp = *stack;
	if (tp->n == 0)
		__mod_error(0, l_num);
	next = tp->next;

	next->n %= tp->n;
	next->prev = NULL;
	*stack = next;
	free(tp);
}

/**
 * __pchar - func that convert the tp element on stack and print
 * it as a character.
 * @stack: ptr of ptr to the stack.
 * @l_num: the curr line.
 * Return: void.
*/
void __pchar(stack_t **stack, unsigned int l_num)
{
	stack_t *tp;
	int vl;

	if (!stack || !(*stack))
		__pchar_error(1, l_num);

	tp = *stack;
	vl = tp->n;
	if (!__is_ascii(vl))
		__pchar_error(0, l_num);
	printf("%c\n", vl);
}

/**
 * __pstr - func that prints all elements of stack as characters,
 * and stps when stack is over or reach a vl equals 0.
 * @stack: ptr of ptr to the stack.
 * @l_num: the curr line.
 * Return: void.
*/
void __pstr(stack_t **stack, __attribute__((unused)) unsigned int l_num)
{
	stack_t *tp;
	int vl;

	if (!stack)
	{
		printf("\n");
		return;
	}
	tp = *stack;
	while (tp)
	{
		vl = tp->n;
		if (vl == 0 || !__is_ascii(vl))
			break;
		printf("%c", vl);
		tp = tp->next;
	}
	printf("\n");
}

/**
 * __rotl - func that rotates a stack the first element becomes the lst,
 * and the second element becomes the tp or first.
 * @stack: ptr of ptr to the stack.
 * @l_num: the curr line.
 * Return: void.
 */
void __rotl(stack_t **stack, unsigned int l_num)
{
	stack_t *tp;
	int data;
	(void) l_num;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	tp = *stack;
	data = tp->n;
	while (tp->next)
	{
		tp = tp->next;
		tp->prev->n = tp->n;
	}

	tp->n = data;
}

/**
 * __rotr - func that rotates the stack to bottom.
 * @stack: ptr of ptr to the stack.
 * @l_num: the curr line.
 * Return: void.
*/
void __rotr(stack_t **stack, unsigned int l_num)
{
	stack_t *lst;
	int data;
	(void) l_num;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	lst = *stack;
	while (lst->next)
		lst = lst->next;

	data = lst->n;
	while (lst->prev)
	{
		lst = lst->prev;
		lst->next->n = lst->n;
	}
	lst->n = data;
}
