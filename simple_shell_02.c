#include"shell.h"

void execute_fun_path(char *input)
{
	pid_t child_process_id = fork();

	if (access(input, X_OK) == -1)
	{
		print_fun("Command not found\n");
		return;
	}

	if (child_process_id == -1)
	{
		perror("fork");
		exit(1);
	}
	if (child_process_id == 0)
	{
		char *token;
		char **cmd = malloc(2 * sizeof(char *));
		int i = 0;

		if (cmd == NULL)
		{
			perror("malloc");
			exit(1);
		}
		token = strtok(input, " ");
		while (token != NULL)
		{
			cmd[i] = strdup(token);
			i++;
			token = strtok(NULL, " ");
		}
		cmd[i] = NULL;
		if (execve(cmd[0], cmd, environ) == -1)
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
		input_fun(&input, &length);
		execute_fun_path(input);
	}
	if (input != NULL)
	{
		free(input);
		input = NULL;
	}
	return (0);
}
