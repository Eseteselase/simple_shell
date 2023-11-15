#include"shell.h"

/**
 * print_fun - used as printf
 * @output: it will take the things to print
 */

void print_fun(const char *output)
{
	write(1, output, strlen(output));
}
