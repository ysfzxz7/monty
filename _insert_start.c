#include "main.h"

/**
 * __insert_start - func a func that insert to a doubly linked list
 * @head: ptr of ptr to the head of the linked list
 * @data: data of node.
 * Return: the address of the new node, NULL if it failed.
 */
stack_t *__insert_start(stack_t **head, int data)
{
	stack_t *temp, *p = *head;

	if (head == NULL)
		return (NULL);

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
		__malloc_error();
	temp->next = NULL;
	temp->prev = NULL;
	temp->n = data;

	if (p == NULL)
	{
		*head = temp;
		return (temp);
	}

	temp->next = p;
	p->prev = temp;
	*head = temp;
	return (temp);
}
