#include "monty.h"
stack_t *head = NULL;
/**
 * main - Entry point
 * @argc: argc
 * @argv: list of args
 * Return: int
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return (EXIT_FAILURE);
	}
	openning_file(argv[1]);
	freeNodes();
	return (EXIT_SUCCESS);
}

/**
 * createNode - Entry point
 * @n: param for int
 * Return: stack_t
 */
stack_t *createNode(int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		err_handler(4);
		return (NULL);
	}
	node->n = n;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/**
 * freeNodes - Entry point.
 * Return: void
 */
void freeNodes(void)
{
	stack_t *tmp;

	if (!head)
		return;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * addQue - Entry point
 * @new_node: double pointer param for stack_t
 * @ln: unsigned param for int
 * Return: void
 */
void addQue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (!head)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (!tmp->next)
		tmp = tmp->next;
	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
