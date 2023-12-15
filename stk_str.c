#include "monty.h"

/**
 * pchar - Entry point
 * @stack: double pointer param for stack_t
 * @line_number: unsigned param for int
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		str_err(11, line_number);
	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		str_err(10, line_number);
	printf("%c\n", ascii);
}

/**
 * print_str - Entry point
 * @stack: double pointer for stack_t
 * @ln: param for int
 * Return: void
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotate_toBot - Entry point
 * @stack: double pointer for stack_t
 * @ln: param for int
 * Return: void
 */
void rotate_toBot(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotate_r - Entry point
 * @stack: double pointer for stack_t
 * @ln: param for int
 * Return: void
 */
void rotate_r(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
