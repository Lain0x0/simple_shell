#include "shell.h"


/**
 * main - Entry point of the simple shell program
 *
 * executeEnv - Execute the "env" built-in command
 * to print the current environment
 *
 * executeEnv - Print the current environment variables
 *
 * Return: Always 0
 */

void executeEnv(void)
{
	char **environ;

	char **env = environ;

	while (*env != NULL)

	{
		printf("%s\n", *env);

		env++;
	}
}

int main(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)

	{
		printf("$ ");

		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)

		{
			break;
		}


		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "env") == 0)

		{
			executeEnv();
		}

		else if (strcmp(input, "exit") == 0)

		{
			break;
		}
	}

	return (0);
}

