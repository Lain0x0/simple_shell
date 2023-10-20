#include "shell.h"

/**
 * executeEnv - Execute the "env" built-in command
 * to print the current environment
*/

extern char **environ;

void executeEnv(void)
{
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

	return 0;
}
