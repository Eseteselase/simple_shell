#include"shell.h"

void execute_fun(char *input)
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

	if (access(cmd[0], X_OK) == 0)
	{
		pid_t child_process_id = fork();

		getenv_fun("/bin");
		if (child_process_id == -1)
		{
			perror("fork");
			exit(1);
		}
		if (child_process_id == 0)
		{
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
	else
		print_fun("No such file or directory\n");
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
	{
		free(input);
		input = NULL;
	}
	return (0);
}
