#include"shell.h"

/**
 * execute_env - to run env
 * 
 */

void execute_env(void)
{
	extern char **environ;

	int i =0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
