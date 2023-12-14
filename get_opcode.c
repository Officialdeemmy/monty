#include "monty.h"

/**
 * get_opcode - selects correct opcode to perform
 * @op: opcode passed
 * Return: pointer to the function that executes opcode
 */
void (*get_opcode(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction[] = {
		{"push", _push_},
		{"pall", _pall_},
		{"pint", _pint_},
		{"pop", _pop_},
		{"swap", _swap_},
		{"queue", _queue_},
		{"stack", _stack_},
		{"add", _add_},
		{"nop", _nop_},
		{"sub", _sub_},
		{"mul", _mul_},
		{"div", _div_},
		{"mod", _mod_},
		{"pchar", _pchar_},
		{"pstr", _pstr_},
		{"rotl", _rotl_},
		{"rotr", _rotr_},
		{NULL, NULL}
	};
	int n;

	for (n = 0; instruction[n].opcode; n++)
	{
		if (_strcmp_(instruction[n].opcode, op) == 0)
			break;
	}

	return (instruction[n].f);
}
