#include"shell.h"

void getenv_fun(char *new_path)
{
	int pipefd[2];
	pid_t child_process_id;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	
	child_process_id = fork();

	if (child_process_id == -1)
	{
		perror("fork");
		exit(1);
	}
	if (child_process_id == 0)
	{
		char modified_path[1024];

		close(pipefd[0]);
		modified_path[0] = '\0';
		custom_strcat(modified_path, "PATH=");
		custom_strcat(modified_path, new_path);
		custom_strcat(modified_path, ":");
		custom_strcat(modified_path, getenv("PATH"));
		if (write(pipefd[1], modified_path, strlen(modified_path)) == -1)
		{
			perror("write");
			exit(1);
		}

		close(pipefd[1]);
		exit(0);
	}
	else
	{
		char modified_path[1024];
		ssize_t read_bytes;

		close(pipefd[1]);
		read_bytes = read(pipefd[0], modified_path, sizeof(modified_path));
		if (read_bytes == -1)
		{
			perror("write");
                        exit(1);
		}
		modified_path[read_bytes] = '\0';
		putenv(modified_path);
		close(pipefd[0]);
		wait(NULL);
	}
}
