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

		char *command_path = find_command_path(cmd[0]);

		if (command_path == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", cmd[0]);
			exit(1);
		}
		if (execve(command_path, cmd, NULL) == -1)
		{
			perror("execve");
			fprintf(stderr, "Failed to execute command: %s\n", cmd[0]);
			free(command_path);
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
