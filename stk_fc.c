#include "monty.h"
/**
 * addStack - Entry point
 * @new_node: double pointer param for stack_t
 * @ln: unsgined param for int
 */
void addStack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (!new_node || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (!head)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * pstack - Entry point
 * @stack: double pointer param for stack_t
 * @line_number: unsigned param for int
 */
void pstack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (!stack)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * poptop - Entry point
 * @stack: double pointer param for stack_t
 * @line_number: unsigned param for int
 */
void poptop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || *stack == NULL)
		more_err_handler(7, line_number);
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * ptop - Entry point
 * @stack: double pointer param for stack_t
 * @line_number: unsigned param for int
 */
void ptop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err_handler(6, line_number);
	printf("%d\n", (*stack)->n);
}
