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
		char path[300];
		char *args[2];

		if ((size_t)snprintf(path, sizeof(path), "/bin/%s", input) >= sizeof(path))
		{
			fprintf(stderr, "Path too long\n");
			exit(1);
		}

		args[0] = (char *)input;
		args[1] = NULL;

		execvp(input, args);

		perror("execvp");
		exit(1);
	}
	else
		wait(NULL);
}
