#include "monty.h"

/**
 * open_file - opens a file
 * @f_name: the file namepath
 * Return: void
 */

void open_file(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (f_name == NULL || fd == NULL)
		errors(2, f_name);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - reads a file
 * @f_desc: pointer to file descriptor
 * Return: void
 */

void read_file(FILE *f_desc)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, f_desc) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delimtr = "\n ";

	if (buffer == NULL)
		errors(4);

	opcode = strtok(buffer, delimtr);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delimtr);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, value, line_number, format);
	return (format);
}

/**
 * find_function - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @l_num: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_function(char *opcode, char *value, int l_num, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_function(func_list[i].f, opcode, value, l_num, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errors(3, l_num, opcode);
}


/**
 * call_func - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 *
 * @op_code: string representing the opcode.
 * @value: string representing a numeric value.
 * @l_nm: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_func(op_func func, char *op_code, char *value, int l_nm, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op_code, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			errors(5, l_num);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				errors(5, l_num);
		}
		node = crt_node(atoi(value) * flag);
		if (format == 0)
			function(&node, l_num);
		if (format == 1)
			add_to_queue(&node, l_num);
	}
	else
		function(&head, l_num);
}
