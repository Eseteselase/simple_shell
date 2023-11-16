#include"shell.h"

/**
 * handle_exit - to exit
 * @cmd: input command
 */

void handle_exit(char **cmd)
{
	free(cmd);
	exit(0);
}
