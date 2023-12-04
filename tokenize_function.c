#include"shell.h"

/**
 * tokenize_input - execve file
 * @input: take the command
 * Return: cmd
 */
char **tokenize_input(char *input)
{
	char *token;
	char **cmd = NULL;
	int i = 0;

	token = strtok(input, " ");
	while (token != NULL)
	{
		cmd = realloc(cmd, (i + 2) * sizeof(char *));
		if (cmd == NULL)
		{
			perror("realloc");
			exit(1);
		}
		cmd[i] = strdup(token);
		if (cmd[i] == NULL)
		{
			perror("strdup");
			while (i > 0)
			{
				i--;
				free(cmd[i]);
			}
			free(cmd);
			exit(1);
		}
		i++;
		token = strtok(NULL, " ");
	}
	cmd[i] = NULL;
	return (cmd);
}
