#include"shell.h"

/**
 * main - maonks
 * Return: 0
 */
int main()
{
        char command[100];
        while (1)
        {
                pid_t child_pid;
		printf("$ ");
                if (fgets(command, sizeof(command), stdin) == NULL)
                {
                        printf("\n");
                        break;
                }
                command[strlen(command) - 1] = '\0';
                if (command[0] == 3)
                {
                        printf("\n");
                        break;
                }
                child_pid = fork();
                if (child_pid == -1)
                {
                        perror("fork");
                        exit(1);
                }
                if (child_pid == 0)
                {
			char **cmd = malloc(sizeof(char *) * 2);
			if (cmd == NULL)
			{
				perror("malloc");
				exit(1);
			}
			cmd[0] = command;
			cmd[1] = NULL;

			execvp(cmd[0], cmd);
                        perror("execve");
			free(cmd);
                        exit(1);
                }
                else
                        wait(NULL);
        }
        return 0;
}
