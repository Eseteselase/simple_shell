#include"header_file.h"

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

void execute_fun(const char *input)
{
	pid_t child_process_id = fork();

	if (child_process_id == -1)
	{
		perror("fork");
		exit(1);
	}
	if (child_process_id == 0)
	{
		char **cmd = malloc(2 * sizeof(char *));

		if (cmd == NULL)
		{
			perror("malloc");
			exit(1);
		}
		cmd[0] = (char *)input;
		cmd[1] = NULL;
		if (execve(input, cmd, environ) == -1)
		{
			perror("./shell");
			free(cmd);
			exit(1);
		}
	}
	else
		wait(NULL);
}

int main(void)
{
	char *input = NULL;
	size_t length = 0;

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
