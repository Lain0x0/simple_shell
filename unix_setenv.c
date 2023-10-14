#include "shell.h"

/**
 * main - Entry Point of Program
 *
 * set_env_variable : to set any
 * variable that user enter
 *
 * unset_env_variable : to unset any
 * variable that user enter
 *
 * @args : Additional arguments required by the function
 *
 * Return : Always 0 (SUCCESS)
 *
 *
 * Description : Program that make user put a value
 *
 */

void set_env_variable(char **args)
{
	if (args[1] == NULL || args[2] == NULL)

	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return;
	}

	char *variable = args[1];

	char *value = args[2];

	if (setenv(variable, value, 1) != 0)

	{
		perror("setenv");
	}
}

void unset_env_variable(char **args)
{
	if (args[1] == NULL)

	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return;
	}

	char *variable = args[1];

	if (unsetenv(variable) != 0)

	{
		perror("unsetenv");
	}
}

int main(void)
{
	while (1)

	{
		char command[100];

		printf("$ ");

		fgets(command, sizeof(command), stdin);

		command[strcspn(command, "\n")] = '\0';

		char *args[100];

		char *token = strtok(command, " ");

		int i = 0;

		while (token != NULL)

		{
			args[i] = token;

			token = strtok(NULL, " ");

			i++;
		}

		args[i] = NULL;

		if (args[0] == NULL)

		{
			continue;
		}

		if (strcmp(args[0], "setenv") == 0)

		{
			set_env_variable(args);
		}

		else if (strcmp(args[0], "unsetenv") == 0)

		{
			unset_env_variable(args);
		}

		else

		{
			printf("Unknown command: %s\n", args[0]);
		}

	}
	return (0);
}

