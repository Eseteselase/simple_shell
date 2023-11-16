#include"shell.h"

/**
 * execute_env - to run env
 */

void execute_env(void)
{
	char **env = environ;

	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
