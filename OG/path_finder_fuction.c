#include"shell.h"
/**
 * find_command_path - find the path.
 * @command: will take the user input.
 * Return: path of the command
 */
char *find_command_path(const char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

/**	if (path == NULL)
	{
		perror("getenv");
		exit(1);
	}*/
	if (path_copy == NULL)
	{
		perror("strdup");
		exit(1);
	}
	if (strchr(command, '/') != NULL)
        {
                if (access(command, X_OK) == 0)
		{
			free(path_copy);
                        return (strdup(command));
		}
		free(path_copy);
                return (NULL);
        }
	while (dir != NULL)
	{
		char *full_path = create_full_path(dir, command);

		if (full_path == NULL)
		{
			free(path_copy);
			exit(1);
		}
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
/**
 * create_full_path - create the path.
 * @dir: char
 * @command: will take the user input.
 * Return: path of the command
 */
char *create_full_path(const char *dir, const char *command)
{
	char *full_path = malloc(strlen(dir) + strlen(command) + 2);

	if (full_path == NULL)
	{
		perror("malloc");
		exit(1);
	}
	strcpy(full_path, dir);
	strcat(full_path, "/");
	strcat(full_path, command);
	return (full_path);
}
