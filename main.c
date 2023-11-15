#include "main.h"

global_var var;

/**
 * main - the start of the pointer
 * @argc: args counter
 * @argv: array of argument
 * Return: 0 alwyas success.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	int sts;

	if (argc != 2)
		__monty_usage();

	var.file = fopen(argv[1], "r");
	if (!var.file)
		__cannot_open_file(argv[1]);

	var.stack = &stack;

	__read_file();
	sts = fclose(var.file);
	__free_stack();
	if (sts == -1)
		exit(-1);

	return (0);
}

/**
 * __free_stack - fun  that frees the stack
 * Return: void.
*/
void __free_stack(void)
{
	stack_t *p, *temp;

	if (var.stack)
	{
		p = *(var.stack);
		while (p)
		{
			temp = p;
			p = p->next;
			free(temp);
		}
		free(p);
	}
}
