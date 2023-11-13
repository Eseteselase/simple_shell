#include"header_file.h"

void print_fun(const char *output)
{
	write(1, output, strlen(output));
}
