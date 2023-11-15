#include"shell.h"

/**
 * input_fun - take the input and check for the error.
 * @input: will take the user input.
 * @length: will read the string length.
 */

void input_fun(char **input, size_t *length)
{
	ssize_t read_result;

	read_result = getline(input, length, stdin);

	if (read_result == -1)
	{
		if (feof(stdin))
		{
			print_fun("\n");
			exit(0);
		}
		else
		{
			print_fun("Error Input\n");
			exit(1);
		}
	}
	if ((*input)[read_result - 1] == '\n')
		(*input)[read_result - 1] = '\0';
}
