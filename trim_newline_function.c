#include"shell.h"

/**
 * trim_newline - used to trim new line
 * @str: to identify the new line
 */

void trim_newline(char *str)
{
	size_t len = strlen(str);

	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}
