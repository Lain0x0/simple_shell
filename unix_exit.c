#include "shell.h"

/**
 * main - Entry Point of Program
 *
 * return : 0
 *
 * Description : Shell Program use exit command
 *
*/

int main(void)
{
	char input[MAX_INPUT_SIZE];
	int status;

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

			status = 0;

			break;
		}

		else if (strncmp(input, "exit ", 5) == 0)

		{

			status = atoi(input + 5);
			break;
		}

		else

		{


			printf("Command not recognized: %s\n", input);
		}
	}

	printf("Exiting with status: %d\n", status);
	exit(status);
}

