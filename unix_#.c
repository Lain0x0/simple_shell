#include "shell.h"

/**
 * main - Entry Point of Program
 *
 * Return: Always 0 (success)
 *
 * Description: Entry Point Of Program
*/

int main(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)

	{
		printf("$ ");

		fgets(input, MAX_INPUT_SIZE, stdin);

		input[strcspn(input, "\n")] = '\0';

		if (input[0] == '#')

		{
			printf("Comment: %s\n", input);
			continue;
		}

		printf("You entered: %s\n", input);
	}

	return (0);
}

