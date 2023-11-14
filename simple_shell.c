#include"header_file.h"

int main(void)
{
	char *input = NULL;
	size_t length =0;

	while (1)
	{
		display_prompt_fun();
		input_fun(&input, &length);
		execute_fun(input);
	}
	if (input != NULL)
		free(input);
	return (0);
}
