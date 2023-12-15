#include "monty.h"

/**
 * openning_file - Entry point
 * @file_name: pointer param for string
 * Return: void
 */

void openning_file(char *file_name)
{
	FILE *filed;

	filed = fopen(file_name, "r");

	if (file_name == NULL || filed == NULL)
		err_handler(2, file_name);
	reading_file(filed);
	fclose(filed);
}


/**
 * reading_file - Entry point
 * @file_name: pointer param for FILE
 * Return: void
 */

void reading_file(FILE *fd)
{
	int line_number;
	int format = 0;
	char *buffer = NULL;
	size_t len = 0;

	if (fd == NULL)
	{
		fprintf(stderr, "File descriptor is NULL.\n");
		return;
	}
	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
		format = parsing_line(buffer, line_number, format);

	free(buffer);
}


/**
 * parsing_line - Entry point
 * @buffer: pointer param for string
 * @line_number: param for int
 * @format:	param for int
 * Return: int
 */
int parsing_line(char *buffer, int line_number, int format)
{
	const char *delim = "\n ";
	char *opcode, *value;

	if (buffer == NULL)
	{
		err_handler(4);
		return (format);
	}
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	finding_function(opcode, value, line_number, format);
	return (format);
}

/**
 * finding_function - Entry point
 * @opcode: param for string
 * @value: param for string
 * @format:  param for int
 * @ln: param for int
 * Return: void
 */
void finding_function(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t listF[] = {
		{"push", addStack},
		{"pall", pstack},
		{"pint", ptop},
		{"pop", poptop},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", pchar},
		{"pstr", print_str},
		{"rotate_toBot", rotate_toBot},
		{"rotate_r", rotate_r},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; listF[i].opcode; i++)
	{
		if (strcmp(opcode, listF[i].opcode) == 0)
		{
			call_fun(listF[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err_handler(3, ln, opcode);
}


/**
 * call_fun - Entry point
 * @func: param for op_func
 * @op: param for string
 * @val: param for string
 * @ln: param for int
 * @format: param for int
 * Return: void
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag = 1;
	int i;

	flag = 1;

	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}

		if (val == NULL)
		{
			err_handler(5, ln);
		}

		for (i = 0; val[i] != '\0'; i++)
		{
			if (!isdigit(val[i]))
			{
				err_handler(5, ln);
			}
		}

		node = createNode(atoi(val) * flag);
		if (format == 0)
		{
			func(&node, ln);
		}
		if (format == 1)
		{
			addQue(&node, ln);
		}
	} else
	{
		func(&head, ln);
	}
}
