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
		if (execve(input, (char *const *)(&input), NULL) == -1)
		{
			perror("./shell");			
			exit(1);
		}
	}
	else
		wait (NULL);
}
