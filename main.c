#include"shell.h"

/**
 * main - will execute everyting
 * Return: Always 0
 */

int main(void)
{
	char *input = NULL;
	size_t length = 0;

	while (1)
	{
		input_fun(&input, &length);
		execute_fun(input);
	}
}
