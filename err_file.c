#include "monty.h"

/**
 * err_handler - Entry point
 * @error_code: param for int
 * Return: void
 */
void err_handler(int error_code, ...)
{
	va_list args;
	char *file_name;
	int line_number;
	char *instruction;

	va_start(args, error_code);

	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			file_name = va_arg(args, char *);
			fprintf(stderr, "Error: Can't open file %s\n", file_name);
			break;
		case 3:
			line_number = va_arg(args, int);
			instruction = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			line_number = va_arg(args, int);
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			break;
		default:
			fprintf(stderr, "Error: Unknown error code %d\n", error_code);
			break;
	}
	va_end(args);
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err_handler - Entry point
 * @error_code: param for int
 * Return: void
 */
void more_err_handler(int error_code, ...)
{
	va_list args;
	unsigned int line_number;
	char *operation;

	va_start(args, error_code);

	switch (error_code)
	{
		case 6:
			line_number = va_arg(args, unsigned int);
			fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
			break;
		case 7:
			line_number = va_arg(args, unsigned int);
			fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
			break;
		case 8:
			line_number = va_arg(args, unsigned int);
			operation = va_arg(args, char *);
			fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, operation);
			break;
		case 9:
			line_number = va_arg(args, unsigned int);
			fprintf(stderr, "L%u: division by zero\n", line_number);
			break;
		default:
			fprintf(stderr, "Error: Unrecognized error code %d\n", error_code);
			break;
	}
	va_end(args);
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * str_err - Entry point
 * @error_code: param for int
 * Return: void
 */
void str_err(int error_code, ...)
{
	va_list args;
	int line_number;

	va_start(args, error_code);
	line_number = va_arg(args, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			break;
		default:
			fprintf(stderr, "Error: Unrecognized error code %d\n", error_code);
			break;
	}
	va_end(args);
	freeNodes();
	exit(EXIT_FAILURE);
}
