#include "shell.h"

int execute_command(char *command)
{
	int status = system(command);

	if (status == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	char user_input[100];
	char *command;
	char *commands[10];
	int command_count = 0;
	int success = 1;
	int i;

	while (1)
	{
		printf("@~user$: ");

		fgets(user_input, sizeof(user_input), stdin);

		user_input[strcspn(user_input, "\n")] = '\0';

		if (strcmp(user_input, "exit") == 0)
		{
			break;
		}

		/* Split user input by "&&" */
		command = strtok(user_input, "&&");

		while (command != NULL)
		{
			commands[command_count] = command;
			command_count++;
			command = strtok(NULL, "&&");
		}

		/* Check each command separated by "&&" */
		for (i = 0; i < command_count; i++)
		{
			if (!execute_command(commands[i]))
			{
				success = 0;
				break;
			}
		}

		if (!success)
		{
			command_count = 0;

			/* Split user input by "||" */
			command = strtok(user_input, "||");

			while (command != NULL)
			{
				commands[command_count] = command;
				command_count++;
				command = strtok(NULL, "||");
			}

			success = 0;

			/* Check each command separated by "||" */
			for (i = 0; i < command_count; i++)
			{
				if (execute_command(commands[i]))
				{
					success = 1;
					break;
				}
			}
		}

		if (!success)
		{
			printf("Command failed\n");
		}
	}

	return 0;
}
