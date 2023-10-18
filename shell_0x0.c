#include "shell.h"

/**
 * main - Entry Point
 *
 * Description: Entry point of the shell
 *
 * Return: Always 0
*/
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	char *args[2];

	while (1)
	{
		printf("$ ");

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\nExit code (0)\n");
			break;
		}

		size_t command_length = strlen(command);

		if (command_length > 0 && command[command_length - 1] == '\n')

		{
			command[command_length - 1] = '\0';
		}

		args[0] = command;
		args[1] = NULL;

		pid_t pid = fork();

		if (pid < 0)


		{
			perror("Fork failed");
			exit(1);
		}

		else if (pid == 0)

		{
			if (execvp(command, args) == -1)

			{
				perror("Execution failed");
				exit(1);
			}
		}

		else

		{
			int status;

			waitpid(pid, &status, 0);

			if (WIFEXITED(status) && WEXITSTATUS(status) == 0)

			{
				printf("Command executed successfully.\n");
			}

			else

			{
				printf("Command execution failed.\n");
			}
		}
	}

	return (0);
}

