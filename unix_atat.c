#include "shell.h"

/**
 * main - Entry Point of Program
 *
 * execute_command - Execute command that user enter
 *
 * @command: The command to execute
 *
 * Return : Always 0 (success)
 *
 * Description : Shell Program with C
*/





int execute_command(char *command)
{
	int status = system(command);

	if (status == 0)

	{
		return (1);
	}

	else

	{
		return (0);
	}
}

int main(void)
{
	char user_input[100];

	while (1)

	{
		printf("@~user$: ");

		fgets(user_input, sizeof(user_input), stdin);

		user_input[strcspn(user_input, "\n")] = '\0';

		if (strcmp(user_input, "exit") == 0)

		{
			break;
		}
		char *command;

		char *commands[10];

		int command_count = 0;

		command = strtok(user_input, "&&");

		while (command != NULL)

		{
			commands[command_count] = command;

			command_count++;

			command = strtok(NULL, "&&");
		}

		int success = 1;

		for (int i = 0; i < command_count; i++)

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

			command = strtok(user_input, "||");

			while (command != NULL)

			{
				commands[command_count] = command;

				command_count++;

				command = strtok(NULL, "||");
			}

			success = 0;

			for (int i = 0; i < command_count; i++)

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

	return (0);
}
