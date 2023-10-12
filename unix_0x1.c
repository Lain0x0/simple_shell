#include "shell.h"

/**
 * main - Entry point for the simple shell program.
 *
 * exitShell - Exits the shell program
 *
 * Return: Always 0.
*/

void exitShell(void)
{
	printf("Exiting the shell...\n");
	exit(0);
}

int main(void)
{
	char input[MAX_COMMAND_LENGTH];

	while (1)

	{
		printf("$ ");

		if (fgets(input, sizeof(input), stdin) == NULL)

		{
			perror("Error reading input");
			exit(1);
		}


		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)

		{
			exitShell();
		}

		else

		{

			printf("Command not recognized: %s\n", input);
		}
	}

	return (0);
}

