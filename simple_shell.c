#include"header_file.h"

int main(void)
{
	char input[200];

	while (1)
	{
		display_prompt_fun();
		input_fun(input, sizeof(input));
		execute_fun(input);
	}
	return (0);
}
