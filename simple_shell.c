#include"shell.h"

/**
 * execute_fun - execve file
 * @input: take the command
 */

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
		display_prompt_fun();
		input_fun(&input, &length);
		execute_fun(input);
	}
	if (input != NULL)
		free(input);
	return (0);
}
