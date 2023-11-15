#include"shell.h"

/**
 * execute_fun - execve file
 * @input: take the command
 */

void execute_fun(char *input)
{
	pid_t child_process_id = fork();

	if (child_process_id == -1)
	{
		perror("fork");
		exit(1);
	}
	if (child_process_id == 0)
	{
		char **cmd = tokenize_input(input);

		if (execve(cmd[0], cmd, NULL) == -1)
		{
			int j = 0;

			perror("execve");
			while (cmd[j] != NULL)
			{
				free(cmd[j]);
				j++;
			}
			free(cmd);
			exit(1);
		}
	}
	else
	{
		pid_t terminated_child_id = wait(NULL);

		if (terminated_child_id == -1)
		{
			perror("wait");
			exit(1);
		}
	}
}
