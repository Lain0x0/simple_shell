#include "shell.h"

/**
 * main - Entry Point
 *
 * parse_input -  Parse user input into command and arguments.
 *
 * @input: The user input string
 *
 * @args: An array to store the parsed command and arguments.
*/

void parse_input(char *input, char **args)
{
	int i = 0;

	args[i] = strtok(input, " \t\n");

	while (args[i] != NULL && i < MAX_ARGS - 1)

	{
		i++;
		args[i] = strtok(NULL, " \t\n");
	}

	args[i] = NULL;
}

int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARGS];
	char *path = "/bin/";

	while (1)

	{
		printf("$ ");

		if (fgets(input, sizeof(input), stdin) == NULL)

		{
			break;
		}


		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)

		{
			break;
		}

		parse_input(input, args);

		if (args[0] != NULL)

		{

			pid_t pid = fork();

			if (pid < 0)

			{
				perror("Fork failed");
			}

			else if (pid == 0)

			{

				char command_path[MAX_INPUT_SIZE];

				snprintf(command_path, sizeof(command_path), "%s%s", path, args[0]);

				execv(command_path, args);

				perror("Command not found");
				exit(EXIT_FAILURE);
			}

			else

			{

				int status;

				waitpid(pid, &status, 0);
			}
		}
	}

	return (0);
}

