#include"header_file.h"

void execute_fun(const char *input)
{
	pid_t child_process_id = fork ();
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

		execve(input, cmd, NULL);
		perror("./shell");
		free(cmd);
		exit(1);
	}
	else
		wait (NULL);
}
