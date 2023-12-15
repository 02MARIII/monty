#include "monty.h"

/**
 * errors - Prints error messages determined by their error code.
 * @code_error: error codes:
 * (1) => The user does not give any file to the program.
 * (2) => The file provided can't be opened or read.
 * (3) => The file provided contains invalid instruction.
 * (4) => the program is unable to malloc more memory.
 * (5) => the parameter passed to the instruction "push" is not an int.
 * (6) => the stack is empty for pint.
 * (7) => the stack is empty for pop.
 * (8) => stack is too short for operation.
 */
void errors(int code_error, ...)
{
	va_list argmnt;
	char *op;
	int line_num;

	va_start(argmnt, code_error);
	switch (code_error)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(argmnt, char *));
			break;
		case 3:
			line_num = va_arg(argmnt, int);
			op = va_arg(argmnt, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argmnt, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_errors - handles errors.
 * @code_error: The error codes are the following:
 * (6) => the stack is empty for pint.
 * (7) => the stack is empty for pop.
 * (8) => stack is too short for operation.
 * (9) => Division by zero.
 */
void more_errors(int code_error, ...)
{
	va_list argmnt;
	char *op;
	int line_num;

	va_start(argmnt, code_error);
	switch (code_error)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(argmnt, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(argmnt, int));
			break;
		case 8:
			line_num = va_arg(argmnt, unsigned int);
			op = va_arg(argmnt, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(argmnt, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_errors - handles errors.
 * @code_error: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_errors(int code_error, ...)
{
	va_list argmnt;
	int line_num;

	va_start(argmnt, code_error);
	line_num = va_arg(argmnt, int);
	switch (code_error)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
