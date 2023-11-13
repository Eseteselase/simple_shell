#include"header_file.h"

void input_fun(char *input, size_t length)
{
	if (fgets(input, length, stdin) == NULL)
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
	input[strcspn(input, "\n")] = '\0';
}
